#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //grab the cipher key
    string key = argv[1];
    //stop incorrect numbers of CL args
    if (argc != 2)
    {
        printf("The number of command line arguments is incorrect. Usage: ./vigenere k\n");
        return 1;
    }
    //stop improper CL arg formats
    int keyLength = strlen(key);
    for (int i = 0; i < keyLength; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("The key must be entirely alphabetical\n");
            return 1;
        }
    }
    //get the message to be ciphered
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    //and its length
    int plainLength = strlen(plaintext);
    int a = 0; //maps to our current index position on the keyword
    int b = 65; //value of ascii A
    int c = 97; //value of ascii a
    //loop through the message, cipher and print each character
    for (int i = 0; i < plainLength; i++)
    {
        if (plaintext[i] > 64 && plaintext[i] < 91) //step in if plaintext[i] is A-Z
        {
            char cipherCharUpp; //char to hold the ciphered analog of the plaintext char
            /* We need to know how much to shift by. The shift is supposed to equal the current key characters index within the alphabet. So a or A shift == 0,
            b or B shift == 1, c or C shift == 2 ... z or Z shift == 25. Since we're in uppercase now, we'll take the ascii key char to uppercase and subtract
            the ascii val to yield the correct shift.
            i.e. key == a --> key = A --> ascii A == 65 --> 65 - 65 == 0 --> shift == 0
            or   key == t --> key = T --> ascii T == 84 --> 84 - 65 == 19 --> shift == 19
            */
            int shift = toupper(key[a]) - b;
            //step in if plaintext[i] + shift exceeds range of ascii uppercase so we can loop back to bottom of ascii uppercase
            if (plaintext[i] + shift > 90)
            {
                cipherCharUpp = 64 + (plaintext[i] + shift - 90);
            }
            else
            {
                cipherCharUpp = plaintext[i] + shift;
            }
            printf("%c", cipherCharUpp);
            //increment a
            a++;
            //set a back to zero when keyLength is reached
            if (a == keyLength)
            {
                a = 0;
            }
        }
        else if (plaintext[i] > 96 && plaintext[i] < 123) //step in if plaintext[i] is a-z
        {
            char cipherCharLow;
            int shift = tolower(key[a]) - c;
            //step in if plaintext[i] + shift exceeds range of ascii lowercase so we can loop back to bottom of ascii lowercase
            if (plaintext[i] + shift > 122)
            {
                cipherCharLow = 96 + (plaintext[i] + shift - 122);
            }
            else
            {
                cipherCharLow = plaintext[i] + shift;
            }
            printf("%c", cipherCharLow);
            //increment a
            a++;
            //set a back to zero when keyLength is reached
            if (a == keyLength)
            {
                a = 0;
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    //then print a line break when the loop is done
    printf("\n");
}