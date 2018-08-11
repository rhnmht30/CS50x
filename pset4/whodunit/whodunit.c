#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    //checking for 3 command line arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: whodunit infile outfile");
        return 1;
    }

    // assigning the filenames from command line arguments to our own variable
    char *clue = argv[1];
    char *verdict = argv[2];

    //opening the clue image file in reading mode
    FILE *in = fopen(clue, "r");

    if (in == NULL)
    {
        fprintf(stderr, "Cannot open file named %s\n", clue);
        return 2;
    }

    //opening the verdict file to insert the data
    FILE *op = fopen(verdict, "w");

    if (op == NULL)
    {
        fclose(in);
        fprintf(stderr, "Could not create file: %s\n", verdict);
        return 3;
    }


    //creating variables to access the properties of image defined in the bmp.h file
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    RGBTRIPLE triple;

    //reading the first header file of the image
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, in);

    //reading the second header file of the image that is INFO file
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, in);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(op);
        fclose(in);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //writing the file properties from clue to verdict file

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, op);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, op);

    //determining the padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //testing each pixel to uncover the murderer

    for (int i = 0, height = abs(bi.biHeight); i < height; i++)
    {
        for (int j = 0, width = abs(bi.biWidth); j < width; j++)
        {
            fread(&triple, sizeof(RGBTRIPLE), 1, in);
            if (triple.rgbtRed == 0xff)
            {
                triple.rgbtRed = 0x00;
                triple.rgbtGreen = 0x00;
                triple.rgbtBlue = 0x00;
            }


            fwrite(&triple, sizeof(RGBTRIPLE), 1, op);
        }

        fseek(in, padding, SEEK_CUR); // skipping over any padding in input file

        //adding that padding w skipped before in the output file
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, op);
        }

    }

    fclose(in);
    fclose(op);
    return 0;

}