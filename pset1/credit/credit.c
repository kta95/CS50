#include<cs50.h>
#include<stdio.h>

int main(void)
{

    long number = get_long("Number: ");   // prmopt the user for card number

    int digit1 = 0;
    int digit2 = 0;
    int num_digits = 0;
    int odds = 0;
    int evens = 0;

    while (number > 0)  // checksum
    {

        digit2 = digit1;
        digit1 = number % 10;   // get the first digit

        if (num_digits % 2 == 0)
        {
            evens += digit1;    // sum of the even digits
        }
        else
        {
            int multiple = 2 * digit1;
            odds += (multiple / 10) + (multiple % 10); // sum of the odd digits
        }

        number /= 10;
        num_digits++;
    }
    // checkcard
    bool is_valid = (evens + odds) % 10 == 0;
    int first_two_digits = (digit1 * 10) + digit2;

    if (digit1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid)
    {
        printf("VISA\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num_digits == 16 && is_valid)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && num_digits == 15 && is_valid)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    // this problem confuses me the most
}



