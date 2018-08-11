// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    // convert the duration fraction to integer value as required
    int X, Y, tmp, dur;
    X = atoi(fraction); // return only first character
    // fraction is a string of form X/Y, we need only Y to return for particular note. So reversing string
    tmp = fraction[0];
    fraction[0] = fraction[2];
    fraction[2] = tmp;
    Y = atoi(fraction); // returns only first character as int because next character is ' / '
    dur = (8 / Y) * X;
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    int basef = 440, n, oct, f;
    float freq;
    oct = note[strlen(note) - 1] - 48; // substracting 48 to adjust ascii value
    char letter = note[0];
    switch (oct)
    {
        case 0 :
            basef /= 16;
            break;
        case 1 :
            basef /= 8 ;
            break;
        case 2 :
            basef /= 4 ;
            break;
        case 3 :
            basef /= 2 ;
            break;
        case 5 :
            basef *= 2 ;
            break;
        case 6 :
            basef *= 4 ;
            break;
        case 7 :
            basef *= 8 ;
            break;
        case 8 :
            basef *= 16;
            break;
        default :
            basef = 440;
            break;
    }
    // finding the letter
    switch (letter)
    {
        case 'A' :
            n = 0;
            break;
        case 'B' :
            n = 2;
            break;
        case 'C' :
            n = -9;
            break;
        case 'D' :
            n = -7;
            break;
        case 'E' :
            n = -5;
            break;
        case 'F' :
            n = -4;
            break;
        case 'G' :
            n = -2;
            break;
    }
    if (strlen(note) == 3)
    {
        if (note[1] == '#')
        {
            if (letter != 'E' && letter != 'B')
            {
                n += 1;
            }
        }
        else if (note[1] == 'b')
        {
            if (letter != 'C' && letter != 'F')
            {
                n -= 1;
            }
        }
    }
    freq = basef * pow(2.0, (n / 12.0));
    f = roundf(freq);
    return f;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    //check for space which indicates a rest between notes
    if (strcmp(s, "") == 0)
    {
        return true;
    }

    return false;
}
