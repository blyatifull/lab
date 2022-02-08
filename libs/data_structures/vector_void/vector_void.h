#ifndef COURSE_VECTOR_VOID_H
#define COURSE_VECTOR_VOID_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#include "C:/Users/blyatifull/cLionProjects/course/libs/algorithms/array/array.h"

typedef struct vectorVoid{
    void *data;                 // указатель на нулевой элемент вектора
    size_t size;                // размер вектора
    size_t capacity;            // вместимость вектора
    size_t baseTypeSize;        // размер базового типа
}vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);


#endif //COURSE_VECTOR_VOID_H
