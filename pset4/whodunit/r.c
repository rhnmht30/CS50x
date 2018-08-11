#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

#include "bmp.h"

int main(void)
{
    BITMAPINFOHEADER bi;
    BITMAPFILEHEADER bf;
    RGBTRIPLE triple;
    FILE *inp = fopen("clue.bmp","r");
    printf("%ld \n", ftell(inp));
    fread(&bf,sizeof(BITMAPFILEHEADER),1,inp);
    printf("%ld \n", ftell(inp));
    fread(&bi,sizeof(BITMAPINFOHEADER),1,inp);
    printf("%ld \n", ftell(inp));
    //printf("%lu \n",sizeof(BYTE));
    //printf("%lu \n",sizeof(WORD));
    //printf("%lu \n",sizeof(DWORD));
    //printf("%lu \n",sizeof(LONG));
    //printf("%lu \n",sizeof(int));
    //printf("%lu \n",sizeof(BITMAPFILEHEADER));
    //printf("bf.bfType = %0x \n",bf.bfType);
    printf("bi.biWidth = %d \n",bi.biWidth);
    printf("%ld \n", ftell(inp));

    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inp);
            if(triple.rgbtRed == 0xff)
            {
                printf("%i\n ",j);
            }

        }
        fseek(inp, 3, SEEK_CUR);
    }



    printf("%ld \n", ftell(inp));
    fclose(inp);



}