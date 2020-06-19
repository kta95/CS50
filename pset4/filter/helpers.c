#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get the pixels
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            // get the average colour
            float ag = (round(red) + round(green) + round(blue)) / 3;
            int avg = round(ag);
            // change the colour of the pixels
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get the pixels
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            // change the colour of the pixels
            if (sepiaRed < 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaGreen < 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaBlue < 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tempr = image[i][j].rgbtRed;  // get the first pixel and store in a temp variable
            int red = image[i][width - 1 - j].rgbtRed;  // get the opposite pixel of previous one
            // swap the two pixels
            image[i][j].rgbtRed = red;
            image[i][width - 1 - j].rgbtRed = tempr;
            // swap the two pixels
            int tempg = image[i][j].rgbtGreen;  // get the first pixel and store in a temp variable
            int green = image[i][width - 1 - j].rgbtGreen;  // get the opposite pixel of previous one
            image[i][j].rgbtGreen = green;
            image[i][width - 1 - j].rgbtGreen = tempg;

            // swap the two pixels
            int tempb = image[i][j].rgbtBlue;  // get the first pixel and store in a temp variable
            int blue = image[i][width - 1 - j].rgbtBlue;  // get the opposite pixel of previous one
            image[i][j].rgbtBlue = blue;
            image[i][width - 1 - j].rgbtBlue = tempb;

        }
    }
    return;
}

// Blur image
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
    return;  // I am not very honest in blur :'(
}
