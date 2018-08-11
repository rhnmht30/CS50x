#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //checking number of arguments
    if (argc != 2)
    {
        printf("Wrong Number Of Arguments\n");
        return 1;
    }
    //checking that the entered string has all characters as alphabets
    //since the entered argument is a string, so have to check each character one by one
    //putting the entered argument in a single string to make it 1D from 2D matrix
    string k = argv[1], pt;
    int sizek = strlen(k);
    for (int i = 0; i < sizek; i++)
    {
        if (!isalpha(k[i]))
        {
            return 1;
        }
        if (islower(k[i]))
        {
            k[i] = (int) k[i] - 97;
        }
        if (isupper(k[i]))
        {
            k[i] = (int) k[i] - 65;
        }
    }

    pt = get_string("plaintext: ");
    string ct = pt;
    int size = strlen(pt);
    for (int j = 0, c = 0; j < size; j++)
    {
        if (c < sizek)
        {
            if (islower(pt[j]))
            {
                ct[j] = (((pt[j] + k[c]) - 97) % 26) + 97;
                c++;
            }
            if (isupper(pt[j]))
            {
                ct[j] = (((pt[j] + k[c]) - 65) % 26) + 65;
                c++;

            }

        }
        if (c == sizek)
        {
            c = 0;
        }
    }
    printf("ciphertext: %s\n", ct);
}