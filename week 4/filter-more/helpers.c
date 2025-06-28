#include "helpers.h"
#include<math.h>
#include<stddef.h>

void swap(BYTE *a, BYTE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;
            float ded = round(average);

            image[i][j].rgbtBlue = ded;
            image[i][j].rgbtGreen = ded;
            image[i][j].rgbtRed = ded;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaGreen;
    int sepiaRed;
    int sepiaBlue;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
            sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
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
            swap(&image[i][j].rgbtRed, &image[i][width - 1 - j].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][width - 1 - j].rgbtGreen);
            swap(&image[i][j].rgbtBlue, &image[i][width - 1 - j].rgbtBlue);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int totalred = 0, totalgreen = 0, totalblue = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentx = i + x;
                    int currenty = j + y;

                    if (currentx < 0 || currenty < 0 || currentx > (height - 1) || currenty > (width - 1))
                    {
                        continue;
                    }

                    totalred += image[currentx][currenty].rgbtRed;
                    totalgreen += image[currentx][currenty].rgbtGreen;
                    totalblue += image[currentx][currenty].rgbtBlue;

                    counter++;
                }
            }
            copy[i][j].rgbtRed = round(totalred / counter);
            copy[i][j].rgbtGreen = round(totalgreen / counter);
            copy[i][j].rgbtBlue = round(totalblue / counter);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
        }
    }
    return;
}

void swap(BYTE *a, BYTE *b)
{
    BYTE tmp = *a;
    *a = *b;
    *b = tmp;
}


int clamp(int value)
{
    return (value < 0) ? 0 : (value > 255) ? 255 : value;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)

        {
    int Gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

            // Initialize the sums for each color channel
            int sumredx = 0, sumgreenx = 0, sumbluex = 0;
            int sumredy = 0, sumgreeny = 0, sumbluey = 0;

            // Iterate over the filter matrix
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // Calculate the current position
                    int currentx = i + x;
                    int currenty = j + y;

                    // Check if the current position is within the image bounds
                    if (currentx >= 0 && currentx < height && currenty >= 0 && currenty < width)
                    {
                        // Calculate the index for filter coefficients
                        int index = (x + 1) * 3 + (y + 1);

                        // Accumulate the products of filter coefficients and pixel values
                        sumredx += Gx[index] * image[currentx][currenty].rgbtRed;
                        sumgreenx += Gx[index] * image[currentx][currenty].rgbtGreen;
                        sumbluex += Gx[index] * image[currentx][currenty].rgbtBlue;

                        sumredy += Gy[index] * image[currentx][currenty].rgbtRed;
                        sumgreeny += Gy[index] * image[currentx][currenty].rgbtGreen;
                        sumbluey += Gy[index] * image[currentx][currenty].rgbtBlue;
                    }
                }
            }

            // Calculate the final values using the Sobel operator and clamp
            int finalred = clamp(round(sqrt(pow(sumredx, 2) + pow(sumredy, 2))));
            int finalgreen = clamp(round(sqrt(pow(sumgreenx, 2) + pow(sumgreeny, 2))));
            int finalblue = clamp(round(sqrt(pow(sumbluex, 2) + pow(sumbluey, 2))));

            // Update the temporary image with the final values
            temp[i][j].rgbtRed = finalred;
            temp[i][j].rgbtGreen = finalgreen;
            temp[i][j].rgbtBlue = finalblue;
        }
    }

    // Copy the temporary image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
