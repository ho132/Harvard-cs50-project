#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long card_number;
    do
    {
        card_number = get_long_long("Enter your credit card number: ");
    }
    while (card_number <= 0);

    int sum = 0;
    int digit_count = 0;
    long long temp = card_number;

    while (temp > 0)
    {
        if (digit_count % 2 == 0)
        {
            sum += temp % 10;
        }
        else
        {
            int double_digit = 2 * (temp % 10);
            sum += double_digit / 10 + double_digit % 10;
        }

        temp /= 10;
        digit_count++;
    }

    if (sum % 10 == 0)
    {
        if ((digit_count == 13 || digit_count == 16) && (card_number / 1000000000000 == 4))
        {
            printf("VISA\n");
        }
        else if (digit_count == 16)
        {
            int first_two_digits = card_number / 100000000000000;
            if (first_two_digits >= 51 && first_two_digits <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digit_count == 15)
        {
            int first_two_digits = card_number / 10000000000000;
            if (first_two_digits == 34 || first_two_digits == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
