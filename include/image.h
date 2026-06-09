#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include <stdlib.h>

/*
 * PLANNED — PARTIAL (structs only, no implementation)
 *
 * This module is part of the MLP image recognition pipeline.
 * It will provide image loading and pixel-to-array conversion so that
 * image data can be fed into the MultilayerPerceptron as a feature vector.
 *
 * img_load() and img_save() are declared but not yet implemented.
 * Implementation lives in src/image.c (to be created).
 */

typedef struct Color{
    double r;
    double g;
    double b;
    double a;
}Color;

typedef struct Image{
    char* name;
    int width;
    int height;
    Color* data;
}Image;

Image* img_load(char* fpath);
void img_save(char* fpath);

#endif
