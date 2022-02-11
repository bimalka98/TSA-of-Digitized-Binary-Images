# -*- coding: utf-8 -*-
"""
Created on Sun Jan 30 09:52:13 2022

@author: Bimalka Piyaruwan

Script to generate test images for my findContour algorithm
"""
import cv2 as cv
import numpy as np

ImageSizes = [256, 512, 1024]
path1 = "E:\\MVbR2TG\\MVbR2TG\\MVbR2TG\\data\\raw\\ImageHeaders\\"
path2 = 'E:\\MVbR2TG\\MVbR2TG\\MVbR2TG\\data\\raw\\ImageFiles\\'

for size in ImageSizes:
    Image = np.ones((size,size))*255
    with open(path1 + 'image' + str(size)+ '.h', 'w') as imagefile:
        imagefile.write('#include "../../../libs/tsa/tsa.h"\n\n')
        imagefile.write('short BinaryImage' + str(size) + '[IMG_HEIGHT][IMG_WIDTH] = {\n')
        for i in range(size):
            imagefile.write('\t{')
            for j in range(size):
                if ( (i > size / 5) and (i < size * 4 / 5) and (j >size / 5) and (j < size * 4 / 5) ):
                    Image[i][j] = 0 # for saving the image as a .png file
                    if j!=size-1:
                        imagefile.write('1, ')
                    else:
                        imagefile.write('1')
                
                else:
                    if j!=size-1:
                        imagefile.write('0, ')
                    else:
                        imagefile.write('0')
            if (i == size - 1):
                imagefile.write('}\n')
            else:
                imagefile.write('},\n')  
        imagefile.write('};\n')
    cv.imwrite(path2 + 'image' + str(size) + '.png', Image) 
