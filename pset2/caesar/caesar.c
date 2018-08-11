#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Wrong number of arguments passed, pass atleast two arguments\n");
        return 1;
    }
// to check for numeric value, can also do
// if (!atoi(argv[1]))
// {
//     printf ("pass a numeric argument\n");
//     return 1;
// }
    int k = atoi(argv[1]);// if not done so then number exist as string. taking each block till \0
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            ciphertext[i] = (((plaintext[i] + k) - 97) % 26) + 97;
        }
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = (((plaintext[i] + k) - 65) % 26) + 65;
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}
