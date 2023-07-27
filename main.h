#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t _getline(char **lineptr, size_t *n);
int allocate_Buffer(char **lineptr, size_t *n);
size_t readInput_Buffer(char *buffer, size_t n);
void copyBufferContent(char *dest, const char *src, size_t len);
#endif
