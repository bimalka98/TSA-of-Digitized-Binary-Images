#include "utilities.h"

void showImage (int binaryimage[IMG_HEIGHT][IMG_WIDTH]) {
    printf ("\n");
    for ( int i = 0; i < IMG_HEIGHT;i++ ) {
        for ( int j = 0; j < IMG_WIDTH; j++ ) {
            printf ("%d ", binaryimage[i][j]);
        }
        printf ("\n");
    }
}

