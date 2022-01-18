/*
Author: Bimalka Piyaruwan 
Date Created: 2022/01/13
Last Modified: 2022/01/13
*/

// including libraries and dependancies
#include <stdio.h>
#include <stdlib.h>
#include "../libs/utilities/utilities.h"
#include "../libs/tsa/tsa.h"

// #define STB_IMAGE_IMPLEMENTATION
// #include "../libs/public/stb_image.h"
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "../libs/public/stb_image_write.h"


/*
Varable declaration convention
Global Variables        : Start with capital, Combine with Capital letters
Local Variables         : Start with underscore & a simple letter, combine with simple letters
Function Arguments      : Start with simple letters, combine with simple letters
#def define constants   : All Capitals and combined with underscore
*/

// global variable declarations

#define IMG_WIDTH  12
#define IMG_HEIGHT 6

int BinaryImage[IMG_HEIGHT][IMG_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int main () {
    
    int k = findContours(BinaryImage, IMG_WIDTH, IMG_HEIGHT);
    return 0;
}