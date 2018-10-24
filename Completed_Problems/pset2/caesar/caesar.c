#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) //kick those suckers out if they're going to get away with that
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    //convert the command line arg into an int
    int key = atoi(argv[1]);
    printf("%d", key);

    //prompt the user for the message to be encrypted
    string plainText = get_string("plaintext: ");
    //figure out how long the message is. We pay by the word.
    int length = strlen(plainText);

    for (int i = 0; i < length; i++)
    {
        if (plainText[i] > 64 && plainText[i] < 91)
        {
            //rotate the cipher within the uppercase range
            for (int j = 0; j < key; j++)
            {
                //increment the ascii value
                plainText[i]++;
                //return to the bottom of the range if incremented out the top of the range
                if (plainText[i] == 91)
                {
                    plainText[i] = 65;
                }
            }
        }
        else if (plainText[i] > 96 && plainText[i] < 123)
        {
            //rotate the cipher within the lowercase range
            for (int k = 0; k < key; k++)
            {
                //increment the ascii value
                plainText[i]++;
                //return to the bottom of the range if incremented out the top of the range
                if (plainText[i] == 123)
                {
                    plainText[i] = 97;
                }
            }
        }
        else
        {
            //Just leave it be. What did it ever do to deserve this?
        }
    }
    printf("ciphertext: %s\n", plainText);
}