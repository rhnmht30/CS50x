#include<cs50.h>
#include<stdio.h>


int main(void)
{
    int row;
    //user input
    do
    {
        row = get_int("Height: ");

    }
    while (row < 0 || row > 23);

    for (int i = 0; i < row; i++)
    {
        //for spaces
        for (int sp = 0; sp < row - i - 1; sp++)
        {
            printf(" ");
        }
        //for hashes
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}

