#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    float owed;
    int owedi;
    float q = 25.00, d = 10.00, n = 5.00, p = 1.00;
    int count = 0;
    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0.0);
    //changing dollars to cents
    owedi = roundf(owed * 100);
    while (true)
    {

        if (owedi < q)
        {
            break;
        }
        owedi = owedi - q;
        count++;
    }
    while (true)
    {
        if (owedi < d)
        {
            break;
        }
        owedi = owedi - d;
        count++;
    }
    while (true)
    {
        if (owedi < n)
        {
            break;
        }
        owedi = owedi - n;
        count++;
    }
    while (true)
    {
        if (owedi < p)
        {
            break;
        }
        owedi = owedi - p;
        count++;
    }
    printf("%i\n", count);
}