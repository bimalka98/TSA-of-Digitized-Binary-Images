/*
Author: Bimalka Piyaruwan
Date Created: 2022/01/13
Last Modified: 2022/01/21
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Data structures to hold parameters of a pixel in an image

struct RGB { // Red, Green, Blue intensities of a pixel 
    char _r; // char holds 1 byte
    char _g;
    char _b;
};

struct Coordinate { // Coordinate of the pixel
    short _x; // short holds 2 bytes
    short _y;
};

struct Pixel { // Main strcuture to hold
    struct Coordinate _coord;
    struct RGB _rgb;
    short _pixelintensity;
    bool _binaryval;
};

struct Node { // Node of a linked list
    struct Pixel pixel;
    struct Node* nextnode;
    bool _childpresent;
};


void printList (struct Node* headnode);
void appendNode ( struct Node* currentnode, struct Pixel pixeldata);