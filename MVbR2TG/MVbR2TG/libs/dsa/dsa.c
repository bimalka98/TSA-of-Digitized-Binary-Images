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
    struct Node* _ptr = headnode;
    
    if ( headnode == NULL ) {
        printf ("\nList is empty!");
        return 0;
    }
    
    //start from the beginning and continue until NULL pointer is found
    printf ("\n[ ");
    while ( _ptr != NULL ) {
        printf ("(%d,%d) ", _ptr->pixel._coord._x, _ptr->pixel._coord._y);
        _ptr = _ptr->nextnode;
    }
    printf (" ]");
}

// append new node at the end of the list
void appendNode (struct Node* headnode, struct Node* currentnode, struct Pixel pixeldata) {
    //create a node
    struct Node* _node = ( struct Node* ) malloc (sizeof (struct Node));
    // add new pixel data to the data field, pixel
    _node->pixel = pixeldata;
    
    if (headnode == NULL){
        // if the list is empty, then make the new node as head
        headnode = _node;
    } else {
        // if the list is not empty, then append the new node at the end
        currentnode->nextnode = _node;
    }
    currentnode = _node;
}

