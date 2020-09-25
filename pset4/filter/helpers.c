#include "helpers.h"
#include <stdio.h>
#include <math.h>

// prototypes
void sepiaCheck(float *sepia, BYTE *image_pixel);
void swapPixels(BYTE *a, BYTE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // for each row
    for (int x = 0; x < height; x++)
    {
        // for each pixel
        for (int y = 0; y < width; y++)
        {
            // here is get the average between all three colors
            float average = (image[x][y].rgbtBlue + image[x][y].rgbtRed + image[x][y].rgbtGreen) / 3.0;

            // here is assigning the average to pixel colors
            image[x][y].rgbtBlue = round(average);
            image[x][y].rgbtRed = round(average);
            image[x][y].rgbtGreen = round(average);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            // here is getting the sepias value
            float sepiaRed = round(.393 * image[x][y].rgbtRed + .769 * image[x][y].rgbtGreen + .189 * image[x][y].rgbtBlue);
            float sepiaGreen = round(.349 * image[x][y].rgbtRed + .686 * image[x][y].rgbtGreen + .168 * image[x][y].rgbtBlue);
            float sepiaBlue = round(.272 * image[x][y].rgbtRed + .534 * image[x][y].rgbtGreen + .131 * image[x][y].rgbtBlue);

            // checks sepia
            sepiaCheck(&sepiaRed, &image[x][y].rgbtRed);
            sepiaCheck(&sepiaBlue, &image[x][y].rgbtBlue);
            sepiaCheck(&sepiaGreen, &image[x][y].rgbtGreen);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // creating a tmp image array
    RGBTRIPLE reflect[height][width];

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            // here is to get the forward pixel to swap
            int a = width - (y + 1);

            // swaping pixels
            swapPixels(&image[x][y].rgbtRed, &reflect[x][a].rgbtRed);
            swapPixels(&image[x][y].rgbtBlue, &reflect[x][a].rgbtBlue);
            swapPixels(&image[x][y].rgbtGreen, &reflect[x][a].rgbtGreen);
        }
    }

    // copy the tmp array on original array
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtRed = reflect[x][y].rgbtRed;
            image[x][y].rgbtGreen = reflect[x][y].rgbtGreen;
            image[x][y].rgbtBlue = reflect[x][y].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creating a tmp image array
    RGBTRIPLE blur[height][width];

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            // total values
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;

            // pixels count
            float count = 0;

            // averages
            float averageRed = 0;
            float averageGreen = 0;
            float averageBlue = 0;

            // making blur
            // iterating 1 row and 1 pixel ahead and behind the pixel that I want to apply the blur effect
            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    int l = x + a;
                    int m = y + b;
                    if (l >= 0 && m >= 0)
                    {
                        if (l <= height - 1 && m <= width - 1)
                        {
                            // sum the pixel amount of red, blue and green to the respectives total values
                            totalRed += image[l][m].rgbtRed;
                            totalBlue += image[l][m].rgbtBlue;
                            totalGreen += image[l][m].rgbtGreen;

                            // count here how much pixels that was iterated to get the average later
                            count += 1.0;
                        }
                    }
                }
            }

            // getting the averages values
            averageRed = totalRed / count;
            averageGreen = totalGreen / count;
            averageBlue = totalBlue / count;

            // putting this averages values on tmp array
            blur[x][y].rgbtRed = round(averageRed);
            blur[x][y].rgbtGreen = round(averageGreen);
            blur[x][y].rgbtBlue = round(averageBlue);
        }
    }

    // copy the tmp array on original array
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtRed = blur[x][y].rgbtRed;
            image[x][y].rgbtGreen = blur[x][y].rgbtGreen;
            image[x][y].rgbtBlue = blur[x][y].rgbtBlue;
        }
    }
}

// UTILS //
// sepia checks
void sepiaCheck(float *sepia, BYTE *image_pixel)
{
    // if sepia is bigger than 255, the sepia value will be equal to 255
    if (*sepia > 255)
    {
        *sepia = 255;
        *image_pixel = *sepia;
    }

    // else
    else
    {
        *image_pixel = *sepia;
    }

    // both statements the image pixel that is passed by argument will be equal to the sepia value
}

// swap pixels
void swapPixels(BYTE *a, BYTE *b)
{
    *b = *a;
}