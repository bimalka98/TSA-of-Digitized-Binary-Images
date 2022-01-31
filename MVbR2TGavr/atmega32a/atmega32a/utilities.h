#pragma once

#include "tsa.h"
#include <stdio.h>
#include <stdlib.h>

void showImage (int binaryimage[IMG_HEIGHT][IMG_WIDTH]);
void writeImage (int binaryimage[IMG_HEIGHT][IMG_WIDTH], FILE** _fptr, char const* filepath);
