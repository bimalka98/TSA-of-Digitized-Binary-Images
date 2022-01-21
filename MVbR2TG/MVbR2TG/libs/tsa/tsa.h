#pragma once

#include <stdio.h>
#include <stdlib.h>

// defining parameters of the image
#define IMG_HEIGHT 6
#define IMG_WIDTH  12

// defclaring the fucntion to find the contours of the binary image
int findContours (int binary_image[IMG_HEIGHT][IMG_WIDTH], int image_width, int image_height);

