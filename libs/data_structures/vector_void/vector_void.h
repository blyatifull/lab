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

// Возвращает вектор размером n и размером типа baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// Резервирует память размером newCapacity для вектора v
void reserveV(vectorVoid *v, size_t newCapacity);

// Приравнивает capacity к size в векторе v
void shrinkToFitV(vectorVoid *v);

// Удаляет элементы из контейнера, но не освобождает выделенную память в векторе v
void clearV(vectorVoid *v);

// Удаляет вектор v
void deleteVectorV(vectorVoid *v);

// Возвращает True, если вектор v пустой, иначе - False
bool isEmptyV(vectorVoid *v);

// Возвращает True, если вектор v полный, иначе - False
bool isFullV(vectorVoid *v);

// Возвращает index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// Записывает в index-ый элемент вектора v значение source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// Удаляет последний элемент вектора v
void popBackV(vectorVoid *v);

// Добавляет в конец вектора v элемент по адресу source
void pushBackV(vectorVoid *v, void *source);

#endif //COURSE_VECTOR_VOID_H
