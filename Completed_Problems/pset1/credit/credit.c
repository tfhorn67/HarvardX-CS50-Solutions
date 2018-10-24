/*Goal: implement Luhn's algorithm in C so that we can use the program to validate credit card numbers.
  If number is not valid return "INVALID" otherwise return "AMEX" "VISA" or "MASTERCARD", accordingly
  Mfgr key: Amex starts with 34 or 37
            Mastercard starts with 51, 52, 53, 54, or 55
            Visa starts with 4
  Luhn's Algorithm: starting with the last digit, take out every other digit moving back and add them all together store aside (a).
                    take the remaining digits and multiply them all by two. Add them all together store aside (b).
                    add a to b. if (a + b) mod 10 = 0, card is valid. otherwise invalid.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long ccNum;
    do
    {
        ccNum = get_long_long("credit card number: "); //get the card number
    }
    while (ccNum < 0);   //re-prompt if ccNum.length is too long or short

    int length = floor(log10(llabs(ccNum))) + 1; //get length of number so you can make an array(s) of correct length
    int a = 0; //for sum of split digits of first set of multiplied nums
    int b = 0; //second set of numbers (to be summed immediately)
    int c; //to hold first digit of card number
    int d; //to hold second digit of card number

    int i; //access each digit of ccNum by taking mod 10 then dividing by 10 and repeating.
    for (i = 0; i < length; i++)
    {
        //create the two sums
        if (i % 2 == 1)
        {
            int aTemp = (ccNum % 10) * 2; //placeholder for the doubled value prior to splitting into its individual digits
            int aTempLength = floor(log10(llabs(aTemp))) + 1; //need to know how many times to split aTemp
            int j; //for the loop in switch case 1
            for (j = 0; j < aTempLength; j++)
            {
                a += aTemp % 10;
                aTemp /= 10;
            }
        }
        if (i % 2 == 0)
        {
            b += ccNum % 10;
        }

        //catch the first two digits for mfgr identification
        if (i == length - 1)
        {
            c = ccNum % 10;
        }
        if (i == length - 2)
        {
            d = ccNum % 10;
        }
        //reduce ccNum to prep it for the next round in the loop
        ccNum /= 10;
    }

    //check if card number passes algorithm test
    if ((a + b) % 10 == 0 && length > 12 && length < 17)
    {
        //check validity by mfgr
        if (c == 4 && length > 12 && length < 17)
        {
            printf("VISA\n");
        }
        if (c == 5 && (d == 1 || d == 2 || d == 3 || d == 4 || d == 5) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        if (c == 3 && (d == 4 || d == 7) && length == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((a + b) % 10 != 0 || length < 13 || length > 16)
    {
        printf("INVALID\n");
    }
}