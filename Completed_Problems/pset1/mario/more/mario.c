#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get user input for pyramid h from 0 to 23 lines
    int h;
    do
    {
        h = get_int("height of pyramid: ");
    }
    while (h < 0 || h > 23);

    int n; //loop through each level of the pyramid and build the string to represent it
    for (n = 0; n < h; n++)
    {

        /* left side: gets h-(n+1) spaces and n+1 hashes
           center always gets 2 spaces
           right side gets n+1 hashes and a line break */

        int i; //loop once for each left side space and print it
        for (i = n + 1; i < h; i++)
        {
            printf(" ");   //left side spaces
        }

        int j; //loop once for each left side hash and print it
        for (j = 0; j < n + 1; j++)
        {
            printf("#");   //left side hashes
        }

        printf("  ");     //print the two center spaces

        int k; //loop once for each right side hash and print it
        for (k = 0; k < n + 1; k++)
        {
            printf("#");
        }

        printf("\n");          //print the line break before repeating the cycle for the next level down the pyramid
    }
}