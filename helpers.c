#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //sfsdsgrsfhsth
    {
        for (int j = 0; j < width; j++) //sfsdsgrsfhsth
        {
            float b = image[i][j].rgbtBlue;
            float g = image[i][j].rgbtGreen;
            float r = image[i][j].rgbtRed;

            int avr = round((b + g + r) / 3);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avr; //sfsdsgrsfhsth
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) //sfsdsgrsfhsth
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //sfsdsgrsfhsth
        {
            float b = image[i][j].rgbtBlue;
            float g = image[i][j].rgbtGreen;
            float r = image[i][j].rgbtRed;

            int cr = round((b * 0.189) + (g * 0.769) + (r * 0.393));
            int cg = round((r * 0.349) + (g * 0.686) + (b * 0.168)); //sfsdsgrsfhsth
            int cb = round((r * 0.272) + (g * 0.534) + (b * 0.131)); //sfsdsgrsfhsth

            if (cr > 255) //sfsdsgrsfhsth
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = cr;
            }
            if (cg > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = cg;
            }
            if (cb > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = cb;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) //sfsdsgrsfhsth
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE val = image[i][j];
            image[i][j] = image[i][width - (j + 1)]; //sfsdsgrsfhsth
            image[i][width - (j + 1)] = val;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // to make a copy of our 2d array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) // the two preivous loops are for every single pixsel in copy
        {
            float totalr, totalg, totalb;
            totalr = totalg = totalb = 0.0;
            float count = 0.0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++) // these two inner loops are for taking the surrounding cells for a spceific pixcel
                {
                    int currentx = i + x;
                    int currenty = j + y;

                    if (currentx < 0 || currenty < 0 || currentx > height - 1 || currenty > width - 1) // to cheak invalid index
                    {
                        continue; // to skip them
                    }

                    float r = image[currentx][currenty].rgbtRed; //sfsdsgrsfhsth
                    float g = image[currentx][currenty].rgbtGreen; //sfsdsgrsfhsth
                    float b = image[currentx][currenty].rgbtBlue; //sfsdsgrsfhsth

                    totalr += r;
                    totalg += g;
                    totalb += b;
                    count ++;
                }
            }
            int avr = round(totalr / count);
            int avg = round(totalg / count);
            int avb = round(totalb / count);

            copy[i][j].rgbtRed = avr;
            copy[i][j].rgbtGreen = avg;
            copy[i][j].rgbtBlue = avb;
        }
    }

    for (int i = 0; i < height; i++) // now to recopy the output file
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}