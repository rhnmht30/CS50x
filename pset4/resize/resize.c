#include<stdio.h>
#include<stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile \n");
        return 1;
    }

    int n = atoi(argv[1]);
    char *small = argv[2];
    char *large = argv[3];

    FILE *infile = fopen(small, "r");

    if (infile == NULL)
    {
        fprintf(stderr, "File doesn't exist with name: %s \n", small);
        return 2;
    }

    FILE *outfile = fopen(large, "w");

    if (outfile == NULL)
    {
        fclose(infile);
        fprintf(stderr, "Could not create file: %s \n", large);
        return 3;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    RGBTRIPLE triple;

    fread(&bf, sizeof(BITMAPFILEHEADER), 1, infile);

    fread(&bi, sizeof(BITMAPINFOHEADER), 1, infile);

    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(infile);
        fclose(outfile);
        fprintf(stderr, "Unsupported File format \n");
        return 4;

    }

    int padding_old = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //increasing width and height
    bi.biWidth *= n;
    bi.biHeight *= n;

    //increasing padding if any
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //changing image size in INFO header file
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);

    //changing total file size
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    //writing all the file size changes from small to large file

    // writing File header to large
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);

    // writing INFO header to large
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outfile);


    //resizing begins
    int tmp1 = n, tmp2 = n; // to store value of n temporarily
    int offset = (sizeof(RGBTRIPLE) * (bi.biWidth / n)) + padding_old;

    for (int i = 0, height = abs(bi.biHeight); i < (height / n); i++)
    {
        while (tmp1 > 0)
        {
            for (int j = 0, width = bi.biWidth; j < (width / n); j++)
            {
                fread(&triple, sizeof(RGBTRIPLE), 1, infile);

                while (tmp2 > 0)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outfile);
                    tmp2--;
                }

                tmp2 = n;
            }

            //skipping the padding if any from input
            fseek(infile, padding_old, SEEK_CUR);

            //inserting padding in output file
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outfile);
            }

            tmp1--;

            if (tmp1 == 0)
            {
                fseek(infile, 0, SEEK_CUR);
            }
            else
            {
                fseek(infile, -offset, SEEK_CUR);
            }
        }
        tmp1 = n;
    }



    fclose(infile);
    fclose(outfile);

    return 0;
}