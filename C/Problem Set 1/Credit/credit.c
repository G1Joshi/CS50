#include <cs50.h>
#include <stdio.h>

int isValid(long num)
{
    long rem, sum = 0, left = 0, one, two, first, c = 0, valid;
    while (num)
    {
        left += (num % 10);
        c++;
        one = num % 10;
        num /= 10;
        rem = (num % 10) * 2;
        while (rem)
        {
            sum += (rem % 10);
            rem /= 10;
        }
        c++;
        two = num % 10;
        num /= 10;
        c++;
    }
    if (c < 13)
    {
        return 0;
    }
    if (c % 2)
    {
        first = one;
    }
    else
    {
        first = two;
    }
    valid = (left + sum) % 10;
    if (valid == 0 && first == 4)
    {
        return 2;
    }
    if (valid == 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    long credit;
    do
    {
        credit = get_long("Number: ");
    }
    while (credit < 0);
    int valid;
    valid = isValid(credit);
    if (valid == 2)
    {
        printf("VISA\n");
    }
    else if (valid == 1)
    {
        if ((credit / 10000000000000) == 34 || (credit / 10000000000000) == 37)
        {
            printf("AMEX\n");
        }
        else if ((credit / 100000000000000) >= 51 && (credit / 100000000000000) <= 55)
        {
            printf("MASTERCARD\n");
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
