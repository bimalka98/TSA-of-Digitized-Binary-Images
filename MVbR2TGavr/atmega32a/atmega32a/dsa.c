// Data structures and Algorithms
/*
Author: Bimalka Piyaruwan
Date Created: 2022/01/13
Last Modified: 2022/01/25
*/

#include "dsa.h"

/*
* #################################
* ##      1. Linked Lists        ##
* #################################
*/

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

// latest implementation of the append fucntion
void appendNodeToLinkedList (struct Node** headnode, struct Node** currentnode, struct Pixel pixeldata) {
    
    // create a node in the heap
    struct Node* _node = ( struct Node* ) malloc (sizeof (struct Node));
    
    // newly created node is the last node of the linked list. Make its nextnode NULL
    _node->nextnode = NULL;

    // add data to the pixel data field of the node
    _node->pixel = pixeldata;

    // check whether the linked list is empty at the moment of fucntion call
    if ( (*headnode) == NULL ) {
        // if list is empty make newly created node the head.
        (*headnode) = _node; 
    } else 	{
        // if the list is not empty make connection between current node and newly created node
        (*currentnode)->nextnode = _node;
    }
    
    // point the currnt node pointer to the newly ce\reated node   
    (*currentnode) = _node;
}

void printLinkedList (struct Node* headnode) {
    
    // if the headnode is null that means there is no node in the list.
    if ( headnode == NULL ) {
        printf ("\nLinked List is empty!");
        return;
    }
    
    // creating a local variable to keep the pointer
    struct Node* _tempnode = headnode;
    
    // printing the linked list's elements if it is not empty
    printf ("\n{");
    while ( _tempnode != NULL ) {
        printf ("(%d, %d), ", _tempnode->pixel._coord._x, _tempnode->pixel._coord._y);
        _tempnode = _tempnode->nextnode;
    }
    printf ("\b\b}");
}
