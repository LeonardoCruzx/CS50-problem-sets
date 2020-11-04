#include "helpers.h"
#include <stdio.h>
#include <math.h>

void copy_img(int height, int width, RGBTRIPLE dest[height][width], RGBTRIPLE src[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0f);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            int oriR = image[i][j].rgbtRed, oriG = image[i][j].rgbtGreen, oriB = image[i][j].rgbtBlue;
            float sepB, sepG, sepR;

            sepB = 0.272 * oriR + 0.534 * oriG + 0.131 * oriB;
            sepB = sepB > 255 ? 255 : round(sepB);

            sepG = 0.349 * oriR + 0.686 * oriG + 0.168 * oriB;
            sepG = sepG > 255 ? 255 : round(sepG);

            sepR = 0.393 * oriR + 0.769 * oriG + 0.189 * oriB;

            //printf("before round %f\n", sepR);
            sepR = sepR > 255 ? 255 : round(sepR);
            //printf("after round %f\n", sepR);

            image[i][j].rgbtBlue = sepB;
            image[i][j].rgbtGreen = sepG;
            image[i][j].rgbtRed = sepR;
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
            RGBTRIPLE imagetmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = imagetmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ori_image[height][width];
    copy_img(height, width, ori_image, image);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            
            int ok_pixels = 0, red_amount = 0, blue_amount = 0, green_amount = 0;
            
            for (int row = i - 1; row < i + 2; row++)
            {
                for (int col = j - 1; col < j + 2; col++)
                {
                    // verify if the col or row excedes the size of image
                    if (row < 0 || row >= height || col >= width || col < 0)
                    {
                        continue;
                    }
                    // increment if the pixel is valid
                    ok_pixels++;
                    // add to the amount the colors of the pixels around
                    red_amount += ori_image[row][col].rgbtRed;
                    blue_amount += ori_image[row][col].rgbtBlue;
                    green_amount += ori_image[row][col].rgbtGreen;
                }
            }
            // add the new color to the image
            image[i][j].rgbtRed = round(red_amount / (ok_pixels * 1.0f));
            image[i][j].rgbtBlue = round(blue_amount / (ok_pixels * 1.0f));
            image[i][j].rgbtGreen = round(green_amount / (ok_pixels * 1.0f)) ;
        }
    }
    return;
}


// copy the image to another matrix rgbttriple
void copy_img(int height, int width, RGBTRIPLE dest[height][width], RGBTRIPLE src[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            dest[i][j].rgbtBlue = src[i][j].rgbtBlue; 
            dest[i][j].rgbtGreen = src[i][j].rgbtGreen; 
            dest[i][j].rgbtRed = src[i][j].rgbtRed; 
        }
    }
}