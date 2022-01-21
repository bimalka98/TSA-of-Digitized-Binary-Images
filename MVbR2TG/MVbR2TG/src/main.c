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
    
    struct Node _headnode;
    struct Node* _currentnode = &_headnode;
    struct Pixel _pixeldata;

    // values for first node
    _pixeldata._coord._x = 10;
    _pixeldata._coord._y = 20;
    // append node to the list
    appendNode (_currentnode, _pixeldata);
    
    // adjust pointer to the next list
    _currentnode = _currentnode->nextnode;

    // values for the next node
    _pixeldata._coord._x = 20;
    _pixeldata._coord._y = 30;

    // append node to the list
    appendNode ( _currentnode, _pixeldata);
    
    printList (&_headnode);
    
    

    return 0;
}