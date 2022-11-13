#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Declare variable avarage
    int avarage;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Calculate avarage, use of 3.0 for round to work
            avarage = round((image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue = avarage;
            image[i][j].rgbtGreen = avarage;
            image[i][j].rgbtRed = avarage;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Declare integers to save values of sepia functions
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //To make sepia functions easier
            int a = image[i][j].rgbtBlue;
            int b = image[i][j].rgbtGreen;
            int c = image[i][j].rgbtRed;

            sepiaRed = round(( 0.393 * c) + ( 0.769 * b) + ( 0.189 * a));
            sepiaGreen = round(( 0.349 * c) + ( 0.686 * b) + ( 0.168 * a));
            sepiaBlue = round(( 0.272 * c) + ( 0.534 * b) + ( 0.131 * a));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //As else for if functions
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //For arrays with even numbers
            if (width % 2 == 0)
            {
                 for (int j = 0; j < width / 2; j++)
                 {
                    int tmpR = image[i][j].rgbtRed;
                    int tmpG = image[i][j].rgbtGreen;
                    int tmpB = image[i][j].rgbtBlue;
                    image[i][j].rgbtRed = image[i][width-(j+1)].rgbtRed;
                    image[i][j].rgbtGreen = image[i][width-(j+1)].rgbtGreen;
                    image[i][j].rgbtBlue = image[i][width-(j+1)].rgbtBlue ;
                    image[i][width-(j+1)].rgbtRed = tmpR;
                    image[i][width-(j+1)].rgbtGreen = tmpG;
                    image[i][width-(j+1)].rgbtBlue = tmpB;
            }

        }

        //For arrays with uneven numbers
        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                int tmpR = image[i][j].rgbtRed;
                int tmpG = image[i][j].rgbtGreen;
                int tmpB = image[i][j].rgbtBlue;
                image[i][j].rgbtRed = image[i][width-(j+1)].rgbtRed;
                image[i][j].rgbtGreen = image[i][width-(j+1)].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width-(j+1)].rgbtBlue ;
                image[i][width-(j+1)].rgbtRed = tmpR;
                image[i][width-(j+1)].rgbtGreen = tmpG;
                image[i][width-(j+1)].rgbtBlue = tmpB;
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Declare temp array to run all of blur calculations with and then replace image array
     RGBTRIPLE blur[height][width];

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Red = 0;
            int Blue = 0;
            int Green = 0;
            float counter = 0.00;

            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    //In order to find edges in array
                    if (i + a < 0 || i + a > height - 1 || j + b < 0 || j + b > width - 1)
                    {
                        continue;
                    }
                    //If surroundings then add up values by colors
                    Red += image[i + a][j + b].rgbtRed;
                    Green += image[i + a][j + b].rgbtGreen;
                    Blue += image[i + a][j + b].rgbtBlue;
                    counter++;
                }
            }
            //Save blur values in blur temp arrays
            blur[i][j].rgbtRed = round(Red / counter);
            blur[i][j].rgbtGreen = round(Green / counter);
            blur[i][j].rgbtBlue = round(Blue / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Replace image array values with blur
            image[i][j].rgbtRed = blur[i][j].rgbtRed;
            image[i][j].rgbtGreen = blur[i][j].rgbtGreen;
            image[i][j].rgbtBlue = blur[i][j].rgbtBlue;
        }
    }
    return;
}
