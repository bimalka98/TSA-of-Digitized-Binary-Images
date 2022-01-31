# -*- coding: utf-8 -*-
"""
Created on Mon Jan 31 10:05:05 2022

@author: Bimalka Piyaruwan

Script to visualize processed images through my findContour algorithm
"""

# import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

path = "E:\\MVbR2TG\\MVbR2TG\\MVbR2TG\\data\\processed\\ImageTexts\\"
size = 1024
filename= "image"+ str(size)+ ".txt"

# read the file and save it as a python array
image = []
with open(path + filename, "r") as f:
    lines = f.readlines()
    for line in lines:
        image.append(line.split())

image = np.array(image).astype('uint8').reshape((size,size))
image = (image>1).astype("uint8")
plt.imshow(image, cmap = 'gray'), plt.show()
