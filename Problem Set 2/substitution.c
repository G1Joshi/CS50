#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int c = 0;
    int arr[26] = {0};
    for (int i = 0; argv[1][i]; i++)
    {
        c++;
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        argv[1][i] = toupper(argv[1][i]);
        arr[argv[1][i] - 65]++;
    }
    if (c != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 1)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    string str = get_string("plaintext: ");
    for (int i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]))
        {
            str[i] = argv[1][str[i] - 65];
        }
        else if (islower(str[i]))
        {
            str[i] = tolower(argv[1][str[i] - 97]);
        }
    }
    printf("ciphertext: %s\n", str);
    return 0;
}
