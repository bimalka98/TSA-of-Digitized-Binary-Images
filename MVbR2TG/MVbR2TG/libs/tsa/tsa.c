/*
Paper Implementation:
"Topological Structural Analysis of Digitized Binary Images by Border Following"
by SATOSHI SUZUKI AND KEIICHI ABE

Author: Bimalka Piyaruwan 
Date Created: 2022/01/18
Last Modified: 2022/01/18

Algorithms can be effectively used in component counting, shrinking, and 
topological structural analysis of binary images, when a sequential digital computer is used.
*/

// ALGORITHM 1
#include "tsa.h"

int findContours(int binary_image[IMG_HEIGHT][IMG_WIDTH], int image_width, int image_height) {
    printf ("Calling findContours function...\n");
    // Set initially NBD to 1
    int _nbd  = 1; // the sequential number of the current border
    int _lnbd = 1; // the sequential number of the last border
    int _i2, _j2; 
    // Scan the picture with a TV raster and perform the following steps for each pixel such that fij # 0
    for(int i=1; i<image_height-1; i++) {
        // Every time we begin to scan a new row of the picture, reset LNBD to 1.
        _lnbd = 1;
        for(int j=1; j<image_width-1; j++) {
            printf ("%d\t", binary_image[i][j]);
            if ( binary_image[i][j] != 0 ) {
                // (1) Select one of the following:
                if ( binary_image[i][j] == 1 && binary_image[i][j - 1] == 0 ) {
                    // then decide that the pixel (i, j) is the border following 
                    // starting point of an outer border, 
                    //increment NBD, and (i2, j2) <- (i, j - 1).
                    _nbd++;
                    _i2 = i; _j2 = j - 1;

                } else if ( binary_image[i][j] >= 1 && binary_image[i][j + 1] == 0 ) {
                    // then decide that the pixel (i, j) is the border following 
                    // starting point of a hole border, 
                    // increment NBD, and (i2, j2) <- (i, j + 1).                   
                    _nbd++;
                    _i2 = i; _j2 = j + 1;
                    // and LNBD <- fij in case fij > 1.
                    if ( binary_image[i][j] > 1 ) {
                        _lnbd = binary_image[i][j];
                    }
                    
                } else {
                    // (c) Otherwise, go to (4).
                    //printf ("Else clause\n");
                }
                // (2) Depending on the types of 
                // 1. the newly found border and 
                // 2. the border with the sequential number LNBD (i.e., the last border met on the current row), 
                // decide the parent of the current border as shown in Table 1.

                // (3) From the starting point (i, j), follow the detected border: 
                // this is done by the following substeps (3.1) through (3.5).
            }            
        }
        printf ("\n");
    }
}
