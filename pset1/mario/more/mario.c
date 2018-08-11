#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int row;
    do
    {
        row = get_int("Height: ");
    }
    while (row < 0 || row > 23);

    for (int i = 0; i < row; i++)
    {

        for (int space = 0; space < row - i - 1; space++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }

}