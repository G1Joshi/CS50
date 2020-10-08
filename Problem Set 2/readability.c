#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    string str = get_string("Text: ");
    int l = 0, w = 1, s = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i]))
        {
            l++;
        }
        if (isspace(str[i]))
        {
            w++;
        }
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            s++;
        }
    }
    double L = 100 * (double) l / w;
    double S = 100 * (double) s / w;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}
