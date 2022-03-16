#ifndef COURSE_DISMATH_H
#define COURSE_DISMATH_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

#include "C:/Users/blyatifull/cLionProjects/course/libs/algorithms/array/array.h"

void setUnion(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

void setIntersection(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

void setDifference(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

void setSymmetricDifference(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

bool setIsIdenticalValues(const int a[], size_t sizeA, const int b[], size_t sizeB);

bool setIsEqual(const int a[], size_t sizeA, const int b[], size_t sizeB);

bool setIsNotIdenticalValues(const int a[], size_t sizeA, const int b[], size_t sizeB);

void setOrderedUnion(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

void setOrderedIntersection(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

void setOrderedDifference(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

void setOrderedSymmetricDifference(const int a[], size_t sizeA, const int b[], size_t sizeB, int c[], size_t *sizeC);

bool setOrderedIsEqual(const int A[], size_t sizeA, const int B[], size_t sizeB);

void task4a ();

void task4b ();

#endif


