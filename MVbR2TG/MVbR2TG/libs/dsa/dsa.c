// Data structures and Algorithms
/*
Author: Bimalka Piyaruwan
Date Created: 2022/01/13
Last Modified: 2022/01/21
*/

#include "dsa.h"

// 1. Linked Lists

// fucntion to display the linked list
void printList (struct Node* headnode) {

    struct Node* p = headnode;
    int count = 0;
    while ( p->_childpresent != 0 ) {
        printf ("\nNode %d x coordinate: %d", count, p->pixel._coord._x);
        printf ("\nNode %d y coordinate: %d", count, p->pixel._coord._y);
        p = p->nextnode;
        count++;
    }
}

// append new node at the end of the list
void appendNode ( struct Node* currentnode, struct Pixel pixeldata) {
    
    //create a node in the heap
    struct Node* _node = ( struct Node* ) malloc (sizeof (struct Node));
    _node->_childpresent = 0;

    // add new pixel data to the data field, pixel
    currentnode->pixel = pixeldata;

    currentnode->_childpresent = 1;

    // update the pointer
    currentnode->nextnode = _node;
}

