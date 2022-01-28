/*
Author: Bimalka Piyaruwan 
Date Created: 2022/01/13
Last Modified: 2022/01/27
*/

// including libraries and dependancies
#include <stdio.h>
#include <stdlib.h>


// user defined libraries
#include "../libs/utilities/utilities.h" // Misscelaneous functions
#include "../libs/tsa/tsa.h" // Paper: "Topological Structural Analysis of Digitized Binary Images by Border Following"
#include "../libs/dsa/dsa.h" // Data structures and Algorithms
//#include "tsa.h"

/*
Varable declaration convention
Global Variables        : Start with capital, Combine with Capital letters
Local Variables         : Start with underscore & a simple letter, combine with simple letters
Function Arguments      : Start with simple letters, combine with simple letters
#def define constants   : All Capitals and combined with underscore
*/

// global variable declarations

#include <time.h>


// sample binary image for contour detection
/*
int BinaryImage[IMG_HEIGHT][IMG_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
*/

int BinaryImage[IMG_HEIGHT][IMG_WIDTH] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };


int main () {

    // Represent the image

    int image[IMG_HEIGHT][IMG_WIDTH];
    for ( int i = 0; i < IMG_HEIGHT;i++ ) {
        for ( int j = 0; j < IMG_WIDTH; j++ ) {
            if ( (i > IMG_HEIGHT / 5) && (i < IMG_HEIGHT * 4 / 5) && (j >IMG_WIDTH / 5) && (j < IMG_WIDTH * 4 / 5) ) {
                image[i][j] = 1;
            } else {
                image[i][j] = 0;
            }
        }
    }
    printf ("Image: %p", ( void* ) image);
    clock_t start, end;
    double cpu_time_used;

    start = clock (); 
    struct Node* contours = findContours (image, IMG_WIDTH, IMG_HEIGHT);
    end = clock ();
    
    cpu_time_used = ( (( double ) ( end - start )) / CLOCKS_PER_SEC );
    //printf ("\nExecution time: %f", cpu_time_used);
    printf ("\nStart: %ld", start);
    printf ("\nEnd: %ld", end);
    printf ("\nExecution time: %f", cpu_time_used);
    // Represent the image
    //showImage (BinaryImage2);
    
    return 0;
}