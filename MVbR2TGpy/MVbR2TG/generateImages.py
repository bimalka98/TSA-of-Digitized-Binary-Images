# -*- coding: utf-8 -*-
"""
Created on Sun Jan 30 09:52:13 2022

@author: Bimalka Piyaruwan

Script to generate test images for my findContour algorithm
"""

ImageSizes = [256, 512, 1024, 2048]
path = 'E:\\MVbR2TG\\MVbR2TG\\MVbR2TG\\data\\raw\\ImageHeaders\\'

for size in ImageSizes:
    with open(path + 'image' + str(size)+ '.h', 'w') as imagefile:
        imagefile.write('#include "../../../libs/tsa/tsa.h"\n\n')
        imagefile.write('int BinaryImage' + str(size) + '[IMG_HEIGHT][IMG_WIDTH] = {\n')
        for i in range(size):
            imagefile.write('\t{')
            for j in range(size):
                if ( (i > size / 5) and (i < size * 4 / 5) and (j >size / 5) and (j < size * 4 / 5) ):
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
