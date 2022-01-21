/*
Author: Bimalka Piyaruwan 
Date Created: 2022/01/13
Last Modified: 2022/01/21
*/

// including libraries and dependancies
#include <stdio.h>
#include <stdlib.h>

// user defined libraries
#include "../libs/utilities/utilities.h"
#include "../libs/tsa/tsa.h"
#include "../libs/dsa/dsa.h"


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
    
    int k = findContours(BinaryImage, IMG_WIDTH, IMG_HEIGHT);
    struct HeadNode* _headnode = NULL;
    struct CurrentNode* _currentnode = NULL;

    struct Pixel _pixeldata;
    _pixeldata._coord._x = 10;
    _pixeldata._coord._y = 20;
    _pixeldata._binaryval = 0;

    printList (_headnode);
    appendNode (_headnode, _currentnode, _pixeldata);
    printList (_headnode);
    
    
    return 0;
}