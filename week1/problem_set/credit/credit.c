#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for a number
    long long cc_number = get_long_long("Number: ");

    // get the length of the number
    int length = 0;
    long long cc_number_copy = cc_number;
    while (cc_number_copy > 0)
    {
        cc_number_copy /= 10;
        length++;
    }

    // check if the length is valid
    if (length != 13 && length != 15 && length != 16 && length != 15)
    {
        printf("INVALID\n");
        return 0;
    }

    // get the first two digits
    int first_two_digits = 0;
    cc_number_copy = cc_number;
    while (cc_number_copy > 99)
    {
        cc_number_copy /= 10;
    }
    first_two_digits = cc_number_copy;

    // get the sum of the digits that weren't multiplied by 2
    int sum = 0;
    cc_number_copy = cc_number;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            sum += cc_number_copy % 10;
        }
        cc_number_copy /= 10;
    }

    // get the sum of the digits that were multiplied by 2
    int sum2 = 0;
    cc_number_copy = cc_number;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 1)
        {
            int digit = cc_number_copy % 10;
            digit *= 2;
            if (digit > 9)
            {
                sum2 += digit % 10;
                digit /= 10;
            }
            sum2 += digit;
        }
        cc_number_copy /= 10;
    }

    // check if the sum is valid
    if ((sum + sum2) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // the card is AMEX
    if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
        return 0;
    }

    // check if the card is MASTERCARD
    if (first_two_digits >= 51 && first_two_digits <= 55)
    {
        printf("MASTERCARD\n");
        return 0;
    }

    // check if the card is VISA
    if (first_two_digits / 10 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    // the card is invalid
    printf("INVALID\n");
    return 0;
}