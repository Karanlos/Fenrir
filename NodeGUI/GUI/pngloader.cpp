#include <iostream>
#include <fstream>
#include <sstream>

#include "pngloader.h"

bool valPNG(std::istream& source) {

    //Allocate a buffer of 8 bytes, where we can put the file signature.
    png_byte pngsig[PNGSIGSIZE];
    int is_png = 0;


    //Read the 8 bytes from the stream into the sig buffer.
    source.read((char*)pngsig, PNGSIGSIZE);

    //Check if the read worked...
    if (!source.good()) return false;

    //Let LibPNG check the sig. If this function returns 0, everything is OK.
    is_png = png_sig_cmp(pngsig, 0, PNGSIGSIZE);

    return (is_png == 0);

}

TexInfo loadPNG(const char *fileName) {

    char* buffer;

    TexInfo info;
    std::ifstream iFile;
    std::stringstream tempStream;
    size_t fileSize;

    info.buffer = 0;
    info.height = 0;
    info.width = 0;

    iFile.open(fileName, std::ios::binary);

    if(!iFile.is_open()) {
        std::cout << "Error while opening png file" << std::endl;
        return info;
    }

    iFile.seekg(0, std::ios::end);
    fileSize = iFile.tellg();
    iFile.seekg(0, std::ios::beg);

    buffer = new char[fileSize];

    iFile.read(buffer, fileSize);

    tempStream.write(buffer, fileSize);
    delete buffer;

    iFile.close();

    if(!valPNG(tempStream)) {
        std::cout << "Error while validating png file" << std::endl;
        return info;
    }

    png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);

    if (!pngPtr) {
        std::cerr << "ERROR: Couldn't initialize png read struct" << std::endl;
        return info;
    }

    png_infop infoPtr = png_create_info_struct(pngPtr);
    if (!infoPtr) {
        std::cerr << "ERROR: Couldn't initialize png info struct" << std::endl;
        png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
        return info;
    }

    png_set_read_fn(pngPtr,(void*)&tempStream, readPNGChunk);

    png_set_sig_bytes(pngPtr, PNGSIGSIZE);
    png_read_info(pngPtr, infoPtr);

    png_uint_32 imgWidth =  png_get_image_width(pngPtr, infoPtr);
    png_uint_32 imgHeight = png_get_image_height(pngPtr, infoPtr);

    png_uint_32 bitdepth   = png_get_bit_depth(pngPtr, infoPtr);

    png_uint_32 channels   = png_get_channels(pngPtr, infoPtr);

    png_uint_32 color_type = png_get_color_type(pngPtr, infoPtr);

    switch (color_type) {
        case PNG_COLOR_TYPE_PALETTE:
            png_set_palette_to_rgb(pngPtr);
            channels = 3;

            break;
        case PNG_COLOR_TYPE_GRAY:
            if (bitdepth < 8)
            png_set_expand_gray_1_2_4_to_8(pngPtr);
            bitdepth = 8;
            break;
    }

    if (png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS)) {
        png_set_tRNS_to_alpha(pngPtr);
        channels+=1;
    }

    if (bitdepth == 16)
        png_set_strip_16(pngPtr);

    png_bytep* rowPtrs = new png_bytep[imgHeight];


    buffer = new char[imgWidth * imgHeight * bitdepth * channels / 8];
    const unsigned int stride = imgWidth * bitdepth * channels / 8;


    for (size_t i = 0; i < imgHeight; i++) {

        png_uint_32 q = (imgHeight- i - 1) * stride;
        rowPtrs[i] = (png_bytep)buffer + q;
    }


    png_read_image(pngPtr, rowPtrs);

    delete[] (png_bytep)rowPtrs;

    png_destroy_read_struct(&pngPtr, &infoPtr,(png_infopp)0);

    info.buffer = buffer;
    info.width = imgWidth;
    info.height = imgHeight;

    return info;
}

void readPNGChunk(png_structp pngPtr, png_bytep data, png_size_t length) {

    png_voidp a = png_get_io_ptr(pngPtr);

    ((std::istream*)a)->read((char*)data, length);
}
