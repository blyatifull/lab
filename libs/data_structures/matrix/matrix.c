#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols){
    int **values = (int **) malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(nCols * sizeof(int));
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols){
    matrix *ms = (matrix*) malloc(nMatrices * sizeof(matrix));
    for (int i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < (m).nRows; ++i)
        free((m).values[i]);

    free((m).values);
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);

    free((ms)->values);
}

void inputMatrix(matrix m){
    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            scanf("%d", &(m).values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < (m).nRows; ++i){
        for (int j = 0; j < (m).nCols; ++j)
            printf("%d ", (m).values[i][j]);

        printf("\b\b\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        outputMatrix(ms[i]);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRows(matrix m, int i1, int i2){
    swap((int*) &(m).values[i1], (int*) &(m).values[i2]);
}

void swapColumns(matrix m, int j1, int j2){
    for (int i = 0; i < (m).nRows; ++i)
        swap((int*) &(m).values[i][j2], (int*) &(m).values[i][j2]);
}






