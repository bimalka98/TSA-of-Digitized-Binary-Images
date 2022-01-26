/*
Author: Bimalka Piyaruwan 
Date Created: 2022/01/13
Last Modified: 2022/01/25
*/

// including libraries and dependancies
#include <stdio.h>
#include <stdlib.h>

// user defined libraries
#include "../libs/utilities/utilities.h" // Misscelaneous functions
#include "../libs/tsa/tsa.h" // Paper: "Topological Structural Analysis of Digitized Binary Images by Border Following"
#include "../libs/dsa/dsa.h" // Data structures and Algorithms


/*
Varable declaration convention
Global Variables        : Start with capital, Combine with Capital letters
Local Variables         : Start with underscore & a simple letter, combine with simple letters
Function Arguments      : Start with simple letters, combine with simple letters
#def define constants   : All Capitals and combined with underscore
*/

// global variable declarations

// sample binary image for contour detection
int BinaryImage[IMG_HEIGHT][IMG_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};



int main () {
    
    // get the directions of the eight neighbours of the pixel (0,0)
    struct Coordinate _ij = {1, 2};
    struct Coordinate _i2j2 = {1, 1};

    //struct Coordinate fnzpixel = findFirstNonZeroPixel(_ij, _i2j2, BinaryImage, 1);
    enum Direction dirr = EAST;
    struct Coordinate fnzp = findFirstNonZeroPixel (_ij, _i2j2, BinaryImage, 1);
    printf ("\nFirst Non Zero pixel: (%d, %d)", fnzp._x, fnzp._y);

    return 0;
}