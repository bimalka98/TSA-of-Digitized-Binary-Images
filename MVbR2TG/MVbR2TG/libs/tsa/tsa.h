/*
Paper Implementation:
"Topological Structural Analysis of Digitized Binary Images by Border Following"
by SATOSHI SUZUKI AND KEIICHI ABE

Author          : Bimalka Piyaruwan 
Date Created    : 2022/01/18
Last Modified   : 2022/01/27

Algorithms can be effectively used in component counting, shrinking, and 
topological structural analysis of binary images, when a sequential digital computer is used.
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../dsa/dsa.h"

// defining parameters of the image
#define IMG_HEIGHT 6
#define IMG_WIDTH  12

// type definitiions
enum Direction{
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST
};

// declaring the fucntion to find the contours of the binary image
struct Node* findContours (
    int binary_image[IMG_HEIGHT][IMG_WIDTH], 
    int image_width, 
    int image_height);


struct Coordinate findFirstNonZeroPixel (
    struct Coordinate ij,
    struct Coordinate i2j2, 
    int binaryimage[IMG_HEIGHT][IMG_WIDTH],
    bool cloclwise,
    bool examined[],
    struct Coordinate mooreneighborhood[]); // array is required only when traversing CCW(Counter Clock Wise) at step 3.4

struct Node* followBorder (
    struct Coordinate ij,
    struct Coordinate* i2j2,
    int binary_image[IMG_HEIGHT][IMG_WIDTH],
    int nbd,
    int* lnbd);