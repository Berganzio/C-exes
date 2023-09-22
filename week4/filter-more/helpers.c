#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // this function must look at the surrounding pixels and take the average of the colors
    // and then assign that average to the current pixel it is looking at
    // also prevent the case the pixel is on the edge of the image and there are no surrounding pixels in certain directions

    // create a temporary image to store the blurred image
    RGBTRIPLE(*temp)
    [width] = calloc(height, width * sizeof(RGBTRIPLE));

    // loop through the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // create variables to store the sum of the colors
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            // create a variable to store the number of pixels that are being averaged
            int count = 0;

            // loop through the surrounding pixels
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // check if the surrounding pixel is within the bounds of the image
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        // add the color values to the sum
                        sumBlue += image[i + k][j + l].rgbtBlue;
                        sumGreen += image[i + k][j + l].rgbtGreen;
                        sumRed += image[i + k][j + l].rgbtRed;
                        // increment the count
                        count++;
                    }
                }
            }

            // calculate the average of the colors
            int avgBlue = round(sumBlue / (float)count);
            int avgGreen = round(sumGreen / (float)count);
            int avgRed = round(sumRed / (float)count);

            // assign the average color values to the current pixel
            temp[i][j].rgbtBlue = avgBlue;
            temp[i][j].rgbtGreen = avgGreen;
            temp[i][j].rgbtRed = avgRed;
        }
    }

    // copy the blurred image to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    // free the memory allocated to the temporary image
    free(temp);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*temp)
    [width] = calloc(height, width * sizeof(RGBTRIPLE));

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxBlue = 0;
            int GxGreen = 0;
            int GxRed = 0;
            int GyBlue = 0;
            int GyGreen = 0;
            int GyRed = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        GxBlue += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                        GxGreen += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        GxRed += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        GyBlue += image[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                        GyGreen += image[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        GyRed += image[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    }
                }
            }

            int sumBlue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));
            int sumGreen = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            int sumRed = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));

            if (sumBlue > 255)
            {
                sumBlue = 255;
            }
            if (sumGreen > 255)
            {
                sumGreen = 255;
            }
            if (sumRed > 255)
            {
                sumRed = 255;
            }

            temp[i][j].rgbtBlue = sumBlue;
            temp[i][j].rgbtGreen = sumGreen;
            temp[i][j].rgbtRed = sumRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    free(temp);
    return;
}
