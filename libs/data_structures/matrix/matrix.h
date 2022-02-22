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

// Возвращает пустую матрицу размером nRows на nCols
matrix getMemMatrix (int nRows, int nCols);

// Возвращает пустой массив матриц размером nMatrices, в котором
// имеют размер nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память матрицы m
void freeMemMatrix(matrix m);

// Освобождает память массива матриц ms размером nMatrices
void freeMemMatrices(matrix *ms, int nMatrices);

// Вводит матрицу m (тип int)
void inputMatrix(matrix m);

// Вводит матрицу m (тип float)
void inputMatrixF(matrixF m);

// Вводит массив матриц ms размером nMatrices (тип int)
void inputMatrices(matrix *ms, int nMatrices);

// Вводит массив матриц ms размером nMatrices (тип float)
void inputMatricesF(matrixF *ms, int nMatrices);

// Выводит матрицу m (тип int)
void outputMatrix(matrix m);

// Выводит матрицу m (тип float)
void outputMatrixF(matrixF m);

// Выводит массив матриц ms размером nMatrices (тип int)
void outputMatrices(matrix *ms, int nMatrices);

// Выводит массив матриц ms размером nMatrices (тип float)
void outputMatricesF(matrixF *ms, int nMatrices);

// Обменивает строки в матрице m друг с другом по индексам i1 и i2
void swapRows(matrix m, int i1, int i2);

// Обменивает столбцы в матрице m друг с другом по индексам j1 и j2
void swapColumns(matrix m, int j1, int j2);

// Возвращает True, если матрица m является квадратной,
// иначе - False
bool isSquareMatrix(matrix m);

// Возвращает True, если матрицы m1 и m2 являются одинаковыми,
// иначе - False
bool twoMatricesEqual(matrix m1, matrix m2);

// Возвращает True, если матрица m является еденичной,
// иначе - False
bool isEMatrix(matrix m);

// Возвращает True, если матрица m является симметричной,
// иначе - False
bool isSymmetricMatrix(matrix m);

// Транспонирует матрицу m
void  transposeSquareMatrix(matrix m);

// Возвращает позицию минимального элемента в матрице m
position getMinValuePos(matrix m);

// Возвращает позицию максимального элемента в матрице m
position getMaxValuePos(matrix m);

// Сортирует столбцы или строки (rowsOrCols) матрицы m вместе с массивом a
void insertionSortMatrix(int *a, matrix *m, void (f)(matrix, int, int), int rowsOrCols);

// Сортирует строки матрицы m по функции-критерию criteria, которая принимает
// массив и его размер
void insertionSortRowsByCriteria(matrix m, int (criteria)(int *, int));

// Сортирует столбцы матрицы m по функции-критерию criteria, которая принимает
// массив и его размер
void insertionSortColsByCriteria(matrix m, int (*criteria)(int *, int));

// Возвращает максимум в массиве row размера sizeRow
int getMax (int const *row, int sizeRow);

// Возвращает минимум в массиве row размера sizeRow
int getMin(const int *row, int sizeRow);

// Возвращает матрицу, которая является перемножением матриц m1 и m2
matrix mulMatrices (matrix m1, matrix m2);

// Возвращает сумму всех элементов массива row размера sizeRow
long long getSum(const int *row, int sizeRow);

// Возвращает True, если в массиве arr размера size нет повторяющихся элементов,
// иначе - false
bool isUnique(const long long *arr, int size);

// Возвращает кол-во уникальных элементов в массиве a размера size
int countNUnique(const long long *a, int size);

#endif //COURSE_MATRIX_H
