#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
    
int main(int argc, string argv[])
{
    if (argc == 2 && atoi(argv[1]) > 0)
    {
        for (int i = 0; argv[1][i]; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi((argv[1]));
        string str = get_string("plaintext: ");
        for (int i = 0; i < strlen(str); i++)
        {
            if (isupper(str[i]))
            {
                str[i] = (((str[i] - 'A') + key) % 26) + 'A';
            }
            else if (islower(str[i]))
            {
                str[i] = (((str[i] - 'a') + key) % 26) + 'a';
            }
        }
        printf("ciphertext: %s\n", str);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
