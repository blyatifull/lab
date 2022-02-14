#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#include "C:/Users/blyatifull/cLionProjects/course/libs/algorithms/array/array.h"

typedef struct matrix {
    int **values;  // элементы матрицы
    int nRows;     // кол-во рядов
    int nCols;     // кол-во столбцов
} matrix;

typedef struct position {
    int rowIndex;  // индекс строки
    int colIndex;  // индекс столбца
} position;

matrix getMemMatrix (int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);


#endif //COURSE_MATRIX_H
