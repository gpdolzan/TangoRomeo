#ifndef __READER_H__
#define __READER_H__

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define FILETYPE 8
#define DIRTYPE 4

typedef struct file_t
{
    int name_size;
    char* name;
    int content_size;
    char* content;
}file_t;

// Main functions
int read_file(char* filePath, file_t* f);
int read_directory(char* dirPath);

// File functions
int file_init(file_t* f);
void print_file(file_t* f);
char* file_get_name(char* filePath);
int file_get_content_size(FILE* file);
char* file_get_content(FILE* file, int size);
int free_file(file_t* f);

#endif