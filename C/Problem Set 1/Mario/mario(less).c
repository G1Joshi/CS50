//Mario
#include<stdio.h>
#include<cs50.h>
int main()
{
    int h;
    do
    {
        //Prompt user for input
        printf("Height: ");
        scanf("%d", &h);
    }
    while (h < 1 || h > 8);
    for (int i = 0; i < h; i++)
    {
        for (int j = h  - 1; j > i; j--)
        {
            printf(" ");
        }
        for (int j = i; j >= 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}