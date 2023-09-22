#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long credit_card_number;
    do
    {
        credit_card_number = get_long_long("Number: ");
    } while (credit_card_number < 1);

    int length = 0;
    long long credit_card_number_copy = credit_card_number;
    while (credit_card_number_copy > 0)
    {
        credit_card_number_copy /= 10;
        length++;
    }

    if (length != 13 && length != 15 && length != 16 && length != 15)
    {
        printf("INVALID\n");
        return 0;
    }

    int first_two_digits = 0;
    credit_card_number_copy = credit_card_number;
    while (credit_card_number_copy > 100)
    {
        credit_card_number_copy /= 10;
    }

    first_two_digits = credit_card_number_copy;

    if (first_two_digits < 40 || first_two_digits > 55)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum = 0;
    credit_card_number_copy = credit_card_number;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            sum += credit_card_number_copy % 10;
        }
        credit_card_number_copy /= 10;
    }

    int sum2 = 0;
    credit_card_number_copy = credit_card_number;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 1)
        {
            int digit = credit_card_number_copy % 10;
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
            sum2 += digit;
        }
        credit_card_number_copy /= 10;
    }

    int total_sum = sum + sum2;

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (first_two_digits >= 40 && first_two_digits <= 49)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}