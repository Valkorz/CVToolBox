#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include <stdlib.h>

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