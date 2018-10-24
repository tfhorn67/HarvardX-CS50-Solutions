# Questions

## What's `stdint.h`?

ANSWER: stdint.h is a C Standard Library header file that provides typedef support for exact width integer types. In the context of bmp.h,
it is being used to map windows-specific data type keywords to corresponding exact width integer types in C. E.g. 'typedef uint8_t BYTE'.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

ANSWER: Because bitmaps store data sequentially without organizing by type or adding buffer space between different data points,
the exact width integer types make it feasible to parse through a series of consecutive bits and correctly delineate the boundaries of one
integers bytes from the former and the latter because it allows you to determine where the end of one datapoint is,
given its beginning offset and length

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

ANSWER: 1, 4, 4, and 2 bytes longs, respectively.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ANSWER: The first to bytes in a bitmap file must be the ASCII characters "B" and "M" ("0x42" and "0x4D" in hexadecimal, "66" and "77" in decimal).

## What's the difference between `bfSize` and `biSize`?

ANSWER: bfSize is the size, in bytes, of the overall bitmap file--the data and metadata;
biSize is the size, in bytes, of the structure containing the explicit image data

## What does it mean if `biHeight` is negative?

ANSWER: if biHeight is negative then the data in bytes is stored in order analogous to the image "Top-Down". e.g. the first (or top left) byte corresponds to the
top left pixel in the image, and the last (or bottom right) byte corresponds to the bottom right pixel in the image. By proxy, a positive biHeight
indicates that the first/top row of bytes corresponds to the last/bottom row of pixels in the image "Bottom-Up".

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

ANSWER: this is indicated by the biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

ANSWER: on line 24, it would return null if the file did not exist or some other issue prevented it from being accessed by fopen()
on line 32, it would return null if the file could not be created by fopen(). e.g. if another file with the same name already existed in the directory.

## Why is the third argument to `fread` always `1` in our code?

ANSWER: Because we are always using fread() to read single elements in the file. E.g. first we read the contents of the bitmapfileheader struct, then
we read the contents of the bitmapinfoheader struct, then we iterate through and read the individual rgbtriple structs. We are accessing and manipulating
individual structs within the bitmap, sequentially. Correspondingly, we set fread() third arg to 1.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

ANSWER: (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 ==> (4 - (3 * 3) % 4) % 4 ==> (4 - (9 % 4)) % 4 ==> (4 - 1) % 4 ==> 3 % 4 ==> 3.
Per line 63 and with a bi.biWidth == 3, padding = 3.

## What does `fseek` do?

ANSWER: fseek() is a c standard library function that sets the write pointer to a specified position within the stream. In other words, when programatically
writing to a file, fseek() can be used to set the cursor to the desired location within the file. e.g. if a txt file is open and being written to, and the
programmer desires to write a string starting 10 positions from the beginning of the file, she could do the following:

//set the cursor to the 10th position
fseek(currentOpenTxtFile, 10, SEEK_SET);
//write the string starting at position 10
fput("This string is written with the first char residing 10 steps from the beggining of the file");

## What is `SEEK_CUR`?

ANSWER: `SEEK_CUR` is the current position in a file to which the I/O stream is reading/writing. This can be thought of, intuitively, as the the cursor
position in a text editor. `SEEK_CUR` basically says "Wherever the cursor is now". This is complimented by `SEEK_SET` and `SEEK_END` point to
the beginning and end of the file, respectively and could be though of as analogous to moving the cursor to the beginning or end of the file in a text editor.
