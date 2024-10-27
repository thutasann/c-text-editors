#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

extern size_t allocated_memory; // Declare as extern to use across files

void *allocate_memory(size_t size);
void *reallocate_memory(void *ptr, size_t new_size);
void free_memory(void *ptr);
size_t get_memory_usage();

#endif