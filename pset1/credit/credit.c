#include<cs50.h>
#include<stdio.h>

int main(void)
{
    long long cc, checkdcc, firstd, twod, checkd1, checkd2, product, countd = 0, order, sum1, sum2, total;
    char company = 'I';
    cc = get_long_long("Enter credit card number: ");
    //counting digits
    checkdcc = cc;
    while (checkdcc > 0)
    {
        firstd = checkdcc % 10;
        checkdcc /= 10;
        countd++;

    }
    //validating company's name
    checkdcc = cc;
    while (checkdcc > firstd)
    {
        twod = checkdcc % 100;
        checkdcc /= 10;
    }
    if (twod >= 34 && twod <= 55)
    {
        if ((twod >= 40 && twod <= 49) && (countd >= 13 && countd <= 16))
        {
            company = 'V';

        }
        else if ((twod == 34 || twod == 37) && (countd == 15))
        {
            company = 'A';
        }
        else if ((twod >= 51 && twod <= 55) && (countd == 16))
        {
            company = 'M';
        }
        else
        {
            company = 'I';
        }
    }
    //applying checksum algorithm
    checkdcc = cc;
    order = 1;//for a paticular place selecting digit
    sum1 = 0;
    sum2 = 0;
    while (checkdcc > 0)
    {
        if (order == 1)
        {
            checkd1 = checkdcc % 10;
            sum1 += checkd1;
            order = 2;
        }
        else
        {
            checkd2 = checkdcc % 10;
            product = checkd2 * 2;
            if (product >= 10)
            {
                while (product > 0)
                {
                    sum2 += product % 10;
                    product /= 10;
                }
            }
            else
            {
                sum2 += product;
            }
            order = 1;
        }
        checkdcc /= 10;
    }
    total = sum1 + sum2;
    //printind company name
    if (total % 10 == 0)
    {
        if (company == 'I')
        {
            printf("INVALID\n");
        }
        if (company == 'V')
        {
            printf("VISA\n");
        }
        if (company == 'M')
        {
            printf("MASTERCARD\n");
        }
        if (company == 'A')
        {
            printf("AMEX\n");
        }
    }
    else
    {
        company = 'I';
    }
    if (company == 'I')
    {
        printf("INVALID\n");
    }
}