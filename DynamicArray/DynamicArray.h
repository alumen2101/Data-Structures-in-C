#ifndef _DYNAMICARRAY_
#define _DYNAMICARRAY_

#include <stddef.h>
#include <stdlib.h>

#define BASECAPACITY 16

typedef struct {
    size_t capacity;
    size_t size;
    int array[BASECAPACITY];
    float growth_rate;
} DynamicArray ;

static void resize(DynamicArray*);
static void copy(DynamicArray*);

DynamicArray* create_dynamic_array();
void append(int);
void delete_at(size_t);
void insert_at(size_t);
void set(int, size_t);
void get(size_t);



#endif
