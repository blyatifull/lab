#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#include "C:/Users/blyatifull/cLionProjects/course/libs/algorithms/array/array.h"

typedef struct vector {
    int *data;        // указатель на элементы вектора
    size_t size;      // размера вектора
    size_t capacity;  // выделенная память
} vector;

// Возвращает вектор размером size, в котором хранится мусор
vector createVector(size_t size);

// Резервирует память размером newCapacity для вектора v
void reserve(vector *v, size_t newCapacity);

// Удаляет элементы из контейнера, но не освобождает выделенную память в векторе v
void clear(vector *v);

// Приравнивает capacity к size в векторе v
void shrinkToFit (vector *v);

// Удаляет вектор v
void deleteVector(vector *v);

// Возвращает True, если вектор v пустой, иначе - False
bool isEmpty (vector *v);

// Возвращает True, если вектор v полный, иначе - False
bool isFull (vector *v);

// Возвращает значение элемента по индексу i в векторе v
int getVectorValue(vector *v, size_t i);

// Добавляет в вектор v элемент x
void pushBack(vector *v, int x);

// Добавляет в вектор v элемент x
void popBack (vector *v);

// Возвращает адрес элемента по индексу i в векторе v
int* atVector(vector *v, size_t i);

// Возвращает адрес последнего элемента в векторе v
int* back(vector *v);

// Возвращает адрес первого элемента в векторе v
int* front(vector  *v);

#endif //COURSE_VECTOR_H
