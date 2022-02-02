/*
Paper Implementation:
"Topological Structural Analysis of Digitized Binary Images by Border Following"
by SATOSHI SUZUKI AND KEIICHI ABE

Author          : Bimalka Piyaruwan
Date Created    : 2022/01/18
Last Modified   : 2022/02/02

Algorithms can be effectively used in component counting, shrinking, and
topological structural analysis of binary images, when a sequential digital computer is used.
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "dsa.h"

// defining parameters of the image
#define IMG_HEIGHT 32
#define IMG_WIDTH  32

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
struct Node* findContours (uint8_t binary_image[IMG_HEIGHT][IMG_WIDTH], uint8_t image_width, uint8_t image_height);

struct Coordinate findFirstNonZeroPixel (
    struct Coordinate ij,
    struct Coordinate i2j2,
    uint8_t binaryimage[IMG_HEIGHT][IMG_WIDTH],
    bool cloclwise,
    char examined[],
    struct Coordinate mooreneighborhood[]); // array is required only when traversing CCW(Counter Clock Wise) at step 3.4

struct Node* followBorder (
    struct Coordinate ij,
    struct Coordinate* i2j2,
    uint8_t binary_image[IMG_HEIGHT][IMG_WIDTH],
    uint8_t nbd,
    uint8_t* lnbd);

struct Coordinate getPreviouslyExaminedPixel (
    struct Coordinate centerpixel,
    char examinedpixels[],
    struct Coordinate mooreneighborhood[]); // This fucntion was not used inside the algorithm. Found a new way of doing the same thing.
