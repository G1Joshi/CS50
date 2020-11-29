#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            gray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);
            image[j][i].rgbtBlue = gray;
            image[j][i].rgbtGreen = gray;
            image[j][i].rgbtRed = gray;
        }
    }
}

int helper(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int blue;
    int red;
    int green;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            blue = helper(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));
            green = helper(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            red = helper(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));
            image[j][i].rgbtBlue = blue;
            image[j][i].rgbtGreen = green;
            image[j][i].rgbtRed = red;
        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            temp[0] = image[j][i].rgbtBlue;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtRed;
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;
            image[j][width - i - 1].rgbtBlue = temp[0];
            image[j][width - i - 1].rgbtGreen = temp[1];
            image[j][width - i - 1].rgbtRed = temp[2];
        }
    }
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Blue;
    int Green;
    int Red;
    float counter;
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Blue = 0;
            Green = 0;
            Red = 0;
            counter = 0.00;
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }
                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }
                    Blue += image[j + k][i + h].rgbtBlue;
                    Green += image[j + k][i + h].rgbtGreen;
                    Red += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }
            temp[j][i].rgbtBlue = round(Blue / counter);
            temp[j][i].rgbtGreen = round(Green / counter);
            temp[j][i].rgbtRed = round(Red / counter);
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
