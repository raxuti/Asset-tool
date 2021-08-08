#include <stdio.h>

struct IMAGE
{
    //image dimensions
    unsigned int width;
    unsigned int heigth;

    //bytes per channel
    unsigned int bpc;

    //data format as RGBA
    void* data;
};

struct IMAGE getImageData(char*);

int main(int argc, char** argv)
{
    char* imgIn;
    char* imgOut;
    //Handle args

    //Get image
    struct IMAGE img = getImageData(imgIn);
}