/*
Paper Implementation:
"Topological Structural Analysis of Digitized Binary Images by Border Following"
by SATOSHI SUZUKI AND KEIICHI ABE

Author          : Bimalka Piyaruwan 
Date Created    : 2022/01/18
Last Modified   : 2022/01/26

Algorithms can be effectively used in component counting, shrinking, and 
topological structural analysis of binary images, when a sequential digital computer is used.
*/

// ALGORITHM 1
#include "tsa.h"

/*
* #################################
* ##  Main Algorithm from Paper  ##
* #################################
*/

int findContours (int binary_image[IMG_HEIGHT][IMG_WIDTH], int image_width, int image_height) {
    
    printf ("Calling findContours function...\n");
    // Set initially NBD to 1
    int _nbd  = 1; // the sequential number of the current border
    int _lnbd = 1; // the sequential number of the last border
    struct Coordinate _ij;      // local variable to keep the current pixel
    struct Coordinate _i2j2;    // adjascent pixel depending on the type of the border 
    
    // Scan the picture with a TV raster and perform the following steps for each pixel such that fij # 0
    for ( int i = 1; i < image_height - 1; i++ ) {

        // Every time we begin to scan a new row of the picture, reset LNBD to 1.
        _lnbd = 1;

        for ( int j = 1; j < image_width - 1; j++ ) {

            if ( binary_image[i][j] != 0 ) {

                // (1) Select one of the following:
                if ( binary_image[i][j] == 1 && binary_image[i][j - 1] == 0 ) {
                    // then decide that the pixel (i, j) is the border following 
                    // starting point of an outer border, 
                    //increment NBD, and (i2, j2) <- (i, j - 1).
                    _nbd++;
                    _i2j2._x = i;
                    _i2j2._y = j - 1;

                } else if ( binary_image[i][j] >= 1 && binary_image[i][j + 1] == 0 ) {
                    // then decide that the pixel (i, j) is the border following 
                    // starting point of a hole border, 
                    // increment NBD, and (i2, j2) <- (i, j + 1).                   
                    _nbd++;
                    _i2j2._x = i;
                    _i2j2._y = j + 1;

                    // and LNBD <- fij in case fij > 1.
                    if ( binary_image[i][j] > 1 ) {
                        _lnbd = binary_image[i][j];
                    }

                } else {
                    // (c) Otherwise, go to (4).
                    // ( 4 ) If fij != 1, then LNBD = abs(fij) and resume the raster scan from the pixel
                    // (i, j + 1).The algorithm terminates when the scan reaches the lower right corner of the picture.
                    if ( binary_image[i][j] != 1 ) {
                        _lnbd = abs (binary_image[i][j]);
                    }
                }
                // (2) Depending on the types of 
                // 1. the newly found border and 
                // 2. the border with the sequential number LNBD (i.e., the last border met on the current row), 
                // decide the parent of the current border as shown in Table 1.

                // (3) From the starting point (i, j), follow the detected border: 
                // this is done by the following substeps (3.1) through (3.5).
            }
        }
    }
}

/*
* #################################
* ##    Supportive Algorithms    ##
* #################################
*/


// Moore-Neighbor Tracing for 3.1 
// http://www.imageprocessingplace.com/downloads_V3/root_downloads/tutorials/contour_tracing_Abeer_George_Ghuneim/moore.html

struct Coordinate findFirstNonZeroPixel (
            struct Coordinate ij,
            struct Coordinate i2j2, 
            int binaryimage[IMG_HEIGHT][IMG_WIDTH],
            int nbd) {
    /*
    (3.1) Starting from (i2, j2), look around clockwise the pixels in the neighborhood
    of (i, j) and find a nonzero pixel. Let (i1, j1) be the first found nonzero
    pixel. If no nonzero pixel is found, assign -NBD to fij and go to (4).
    */
      
    enum Direction _initialdirection = WEST; // starting pixel of an outer border: default
    if ( i2j2._y - ij._y == 1 ) _initialdirection = EAST; // starting pixel of a hole border


    struct Coordinate _neighbors[8] = {
        {-1,  0}, // NORTH
        {-1, +1}, // NORTH_EAST
        { 0, +1}, // EAST
        {+1, +1}, // SOUTH_EAST
        {+1,  0}, // SOUTH
        {+1, -1}, // SOUTH_WEST
        { 0, -1}, // WEST
        {-1, -1}  // NORTH_WEST
    };
  
    
    struct Coordinate _nonzeropixel;
    _nonzeropixel._x = -1;
    _nonzeropixel._y = -1;


    // traversing moore neighbour pixels starting from the
    int _i, _j;
    for ( int i = 0; i < 8; i++ ) {
        _i = ij._x + _neighbors[( int ) ( _initialdirection + i ) % 8]._x;
        _j = ij._y + _neighbors[( int ) ( _initialdirection + i ) % 8]._y;
        if ( binaryimage[_i][_j] != 0 ) {
            _nonzeropixel._x = _i;
            _nonzeropixel._y = _j;
            break;
        }
    }
    return _nonzeropixel;
}


// algorithm to follow a detected border
struct Node* followBorder (struct Coordinate ij, struct Coordinate* i2j2, int binary_image[IMG_HEIGHT][IMG_WIDTH], int nbd) {

    // creating a linked list to store the pixels of the following border
    struct Node* _headnode = NULL;
    struct Node* _currentnode = _headnode;
    struct Pixel _pixeldata;

    // 3.1 Let (i1, j1) be the first found nonzero pixel.
    struct Coordinate _i1j1 = findFirstNonZeroPixel (ij, *i2j2, binary_image, nbd);
   
    // If no nonzero pixel is found, assign - NBD to fij and go to (4).
    if ( _i1j1._x == -1 || _i1j1._y == -1 ) {
        binary_image[ij._x][ij._y] = -nbd;
        // Step (4) comes here.
        return;
    } else {
        // (3.2): (i2, j2) <= (i1, j1) and (i3, j3) <= (i, j).
        i2j2->_x = _i1j1._x;
        i2j2->_y = _i1j1._y;

        int _i3 = ij._x;
        int _j3 = ij._y;

        /*
        (3.3) Starting from the next element of the pixel (i2, j2)
        in the counterclockwise order, examine counterclockwise 
        the pixels in the neighborhood of the current pixel (i3, j3) 
        to find a nonzero pixel and let the first one be (i4, j4).
        */
    }


    return _headnode;
}

