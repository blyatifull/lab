#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

#include "C:/Users/blyatifull/cLionProjects/course/libs/algorithms/array/array.h"

typedef struct{
    int **values;  // элементы матрицы
    int nRows;     // кол-во рядов
    int nCols;     // кол-во столбцов
} matrix;

typedef struct{
    float **values;  // элементы матрицы
    int nRows;     // кол-во рядов
    int nCols;     // кол-во столбцов
} matrixF;

typedef struct position {
    int rowIndex;  // индекс строки
    int colIndex;  // индекс столбца
} position;

matrix getMemMatrix (int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrixF(matrixF m);

void inputMatrices(matrix *ms, int nMatrices);

void inputMatricesF(matrixF *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrixF(matrixF m);

void outputMatrices(matrix *ms, int nMatrices);

void outputMatricesF(matrixF *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void  transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

void insertionSortMatrix(int *a, matrix *m, void (f)(matrix, int, int), int rowsOrCols);

void insertionSortRowsByCriteria(matrix m, int (criteria)(int *, int));

void insertionSortColsByCriteria(matrix m, int (*criteria)(int *, int));

int getMax (int const *row, int sizeRow);

int getMin(const int *row, int sizeRow);

matrix mulMatrices (matrix m1, matrix m2);

long long getSum(const int *row, int sizeRow);

bool isUnique(const long long *arr, int size);

#endif //COURSE_MATRIX_H
