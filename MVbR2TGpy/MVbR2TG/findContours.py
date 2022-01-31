# -*- coding: utf-8 -*-
"""
Created on Fri Jan 28 15:29:46 2022

@author: Bimalka Piyaruwan
"""
"""
    Script for timing analysis of findcontour fucntion in openCV

 """
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
import time

size = 4096*2
Image = np.zeros((size,size))
TimingAnalysis = []

for row in range(size):
        for col in range(size):
            if ((row > int(size/5) and row < int (size*4/5)) and (col > int(size/5) and col < int(size*4/5))):
                Image[row][col] = 1
            else:
                Image[row][col] = 0

# Calculating time it takes to run the function for 100 times.
experiments = 10
trials = 100
times = []
for i in range(experiments):
    start = time.time()
    for i in range(trials):
        contours,_ = cv.findContours(Image.astype('uint8'), cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    end = time.time()
    times.append(end-start)
    
print("Image size: {}, Average execution time: {}.".format(size, np.mean(times)/trials))

print(type(contours))
print(len(contours))
# Visualizing contours (-1 argument to plot all the contours)
im_contours_belt = np.zeros((Image.shape[0],Image.shape[1],3), np.uint8)
conts = cv.drawContours(im_contours_belt, contours, -1, (0,255,0), 3).astype('uint8')
plt.imshow(conts), plt.show()

 
