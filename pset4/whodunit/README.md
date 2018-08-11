# Questions

## What's `stdint.h`?

stdint.h is a way of creating our own integer types using typedefs of certain widths
A bunch of typedefs and macros for making integer variables of custom sizes

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

You can fill up exactly the amount of space you want in a file which is good for things like bitmap headers.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 byte
DWORD = 4 bytes
LONG = 4 bytes
WORD = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

first two bytes is WORD and denote file type(bftype)
1st byte = 42 in hex, 66 in Decimal and B in ASCII
2nd byte = 4d in hex, 77 in Decimal and M in ASCII


## What's the difference between `bfSize` and `biSize`?

bfSize is the total number of bytes in the file (246 for smiley.bmp). include size of BITMAPFILEHEADER + IMAGE SIZE  + BITMAPINFOHEADER
biSize is the number of bytes in the info header (40 for a bitmap).

## What does it mean if `biHeight` is negative?

A negative value for biHeight suggests that the vertical orientation of the image is upside-down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount member of the BITMAPINFOHEADER structure determines the number of
bits that define each pixel and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

if the file is not present in the working directory

## Why is the third argument to `fread` always `1` in our code?

We want to copy one individual element, in this case, structure per read, e.g. a complete BITMAPINFOHEADER or an individual RGBTRIPLE.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

(4 - (3*3) % 4) % 4 = (4 - 9 % 4 ) % 4 = (4 - 1) % 4 = 3 % 4 =3

## What does `fseek` do?

puts the cursor to a particular position in a file when reading it

## What is `SEEK_CUR`?

indicates current position

## Whodunit?

It was professor plum with candlestick in the library
