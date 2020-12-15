#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover file\n");
        return 1;
    }
    char *file = argv[1];
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 2;
    }
    BYTE temp[512];
    int count = 0;
    char filename[8];
    FILE *optr = NULL;
    while (true)
    {
        size_t bytesRead = fread(temp, sizeof(BYTE), SIZE, ptr);
        if (bytesRead == 0 && feof(ptr))
        {
            break;
        }
        bool Jpeg = temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0;
        if (Jpeg && optr != NULL)
        {
            fclose(optr);
            count++;
        }
        if (Jpeg)
        {
            sprintf(filename, "%03i.jpg", count);
            optr = fopen(filename, "w");
        }
        if (optr != NULL)
        {
            fwrite(temp, sizeof(BYTE), bytesRead, optr);
        }
    }
    fclose(optr);
    fclose(ptr);
    return 0;
}
