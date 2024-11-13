/*
    You are given a grayscale image’s pixel values in a 2D array named image. The dimensions of the array are given by variables height and width.

    Your task is to convert the grayscale image to a black and white image. To do this, apply a simple thresholding technique.
    If a pixel value is less than 70 -> set it to 0, otherwise set it to 255.
 */
int height;
int width;
int image[0][0];

#include "imagelib.h"

int main()
{
    // Displays input image
    loadFile("input.png");

    // write your solution here
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = image[row][col] < 70 ? 0 : 255;
        }
    }

    // Displays modified image
    saveFile("output/modified.png");
}