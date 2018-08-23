#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage recover card \n");
        return 1;
    }

    char *mmc = argv[1];

    //initiaze a array buffer of type char to store data to be read by file
    unsigned char buffer[512] = {0}; //type char because it has width = 1 byte

    //opening the memory card for reading
    FILE *inp = fopen(mmc, "r");
    FILE *out; //declaring file pointer
    out = NULL;
    //searching for a jpeg in the file by searching for first 4 bytes
    // for (int i = 0; i < 512 ; i++)
    // {
    //     fread(&buffer[i],1,1,inp);
    //     printf("%04x \n",buffer[i]);
    // }
    int count = 0;
    char filename[10];
    while (fread(&buffer, 512, 1, inp) == 1)
    {

        //checking first 4 bytes for jpeg files
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0)
        {

            if (out != NULL)
            {
                fclose(out); // close the files created after the first file
            }

            sprintf(filename, "%.03i.jpg", count);
            count++; //to count no. of files
            out = fopen(filename, "w");
            if (out == NULL)
            {
                fprintf(stderr, "Couldn't create file name: %s\n", filename);
                return 2;
            }
            fwrite(&buffer, 512, 1, out);
        }

        else if (out != NULL)
        {
            fwrite(&buffer, 512, 1, out);
        }
    }
    fclose(inp);
    return 0;
}