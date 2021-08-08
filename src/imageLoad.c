#include <stdio.h>
#include <stdlib.h>
#include <endian.h>

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

struct IMAGE loadBmp(char*);
struct IMAGE loadJpg(char*);
struct IMAGE loadPng(char*);

struct IMAGE getImageData(char* path)
{
    //open image file
    FILE* fd = fopen(path, "rb");

    //check if image file exist
    if(fd == NULL) { printf("Failed to open file %s\nCheck if file path is correct\n", path); exit(1); }
    
    //read image file header
    unsigned long header;
    fread(&header, 1, 8, fd);
    header = le64toh(header);

    //close image file
    fclose(fd);

    //identify file from file header
    //cleaner solution wanted

    //is BMP
    if((header >> 48) == 0x424D) { return loadBmp(path); }

    //is JPG
    if((header >> 32) == 0xFFD8FFE0) { return loadJpg(path); }

    //is PNG
    if((header >> 32) == 0x89504E47) { return loadPng(path); }

    return (struct IMAGE){0U, 0U, 0U, (void*)0};
}