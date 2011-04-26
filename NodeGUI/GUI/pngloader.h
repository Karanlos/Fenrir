#ifndef PNGLOADER_H
#define PNGLOADER_H

#include <png.h>

struct TexInfo {
    unsigned int width;
    unsigned int height;
    char* buffer;
};

#define PNGSIGSIZE 8

bool valPNG(std::istream& source);

TexInfo loadPNG(const char* fileName);

void readPNGChunk(png_structp pngPtr, png_bytep data, png_size_t length);

#endif // PNGLOADER_H
