#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"


static void resize(DynamicArray*);
static void copy(DynamicArray*);

DynamicArray* create_dynamic_array()
{
    size_t len = sizeof(DynamicArray);
    DynamicArray* da = malloc(len);
    memset(da, 0, len);
    da->size = 0;
    da->capacity = BASECAPACITY;
    da->growth_rate = 1.5;

    return da;
}
void append(int);
void delete_at(size_t);
void insert_at(size_t);
void set(int, size_t);
void get(size_t);

