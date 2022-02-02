#include "utilities.h"

void showImage (int binaryimage[IMG_HEIGHT][IMG_WIDTH]) {
    printf ("\n");
    for ( int i = 0; i < IMG_HEIGHT;i++ ) {
        for ( int j = 0; j < IMG_WIDTH; j++ ) {
            printf ("%d", binaryimage[i][j]);
        }
        printf ("\n");
    }
}

void writeImage (short binaryimage[IMG_HEIGHT][IMG_WIDTH], FILE** fptr, char const* filepath) {

    // opening the file in the safe mood
    errno_t _errorcode = fopen_s (fptr, filepath, "w");
    if ( _errorcode != NULL ) {

        // if there's an error opening the file inform that to the user.
        printf ("\nError! Failed to open file in %c mode!", 'w');

    }   else {

        // if the file succesfully open. save the image to the file
        printf ("\nWriting the processed image to the file...");

        for ( int i = 0; i < IMG_HEIGHT; i++ ) {
            for ( int j = 0; j < IMG_WIDTH; j++ ) {
                fprintf (*fptr, "%d ", binaryimage[i][j]);
            }
            fprintf (*fptr, "\n");
        }
        fclose (*fptr);

        printf ("\nWrote image successfully to the file.\a");
    }
}
