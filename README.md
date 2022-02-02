# *Paper: Topological Structural Analysis of Digitized Binary Images by Border Following*
> Authors of the Paper : SATOSHI SUZUKI, KEIICHI ABE

## Implementations found on GitHub: <br>

https://github.com/RaphaelJ/friday/blob/master/src/Vision/Image/Contour.hs
https://github.com/lagadic/visp/blob/master/modules/imgproc/src/vpContours.cpp
https://github.com/lagadic/visp/blob/master/modules/imgproc/include/visp3/imgproc/vpContours.h
https://github.com/JuliaImages/juliaimages.github.io/blob/source/docs/examples/contours/contour_detection.jl

## Abstract

"*Two border following algorithms are proposed for the topological analysis of digitized
binary images. The first one determines the surroundness relations among the borders
of a binary image. Since the outer borders and the hole borders have a one-to-one
correspondence to the connected components of l-pixels and to the holes, respectively,
the proposed algorithm yields a representation of a binary image, from which one
can extract some sort of features without reconstructing the image. The second
algorithm, which is a modified version of the first, follows only the outermost borders
(i.e., the outer borders which are not surrounded by holes). These algorithms can be
effectively used in component counting, shrinking, and topological structural analysis
of binary images, when a sequential digital computer is used. o 1985 Academic press, IC."*

---

## How far Have I done?

I was able to implemet the algorithm upto the point where it can detect a contour in a test image and assign  a label to it. However there is a bug which results in running the same contour detection algorithm several times for a contour detected prevoisly. I was not able to find the reason for that.

|Folder Name|What is inside|
|:-----:|:----|
|MVbR2TG|Implementaion of the paper in pure C language using Visual Studio 2019|
|MVbR2TGavr|Implementaion of the paper to run in an AVR microcontroller. This was not successful due to the very limited storage and the processing power of the AVR (Atmel ATMEGA32A), `uint8_t` branch consists of an alternate approach which ues `uint8_t` data type instead of `int` type.|
|MVbR2TGpy|Includes random python scripts to 1. Generate test images and saves them in header files 2. Measure time it takes to run the `findcontour` function in OpenCV inorder to compare it with my algorithm 3. Visualize the processed images by the first algorithm (MVbR2TG)|
