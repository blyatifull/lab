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

void swapRows(matrix m, int i1, int i2){
    swap((int*) &(m).values[i1], (int*) &(m).values[i2]);
}

void swapColumns(matrix m, int j1, int j2){
    for (int i = 0; i < (m).nRows; ++i)
        swap((int*) &(m).values[i][j2], (int*) &(m).values[i][j2]);
}

bool isSquareMatrix(matrix m){
    return (m).nRows == (m).nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2){
    if ((m1).nRows != (m2).nRows || (m1).nCols != (m2).nCols)
        return false;

    for (int i = 0; i < (m1).nRows; ++i)
        for (int j = 0; j < (m1).nCols; ++j)
            if ((m1).values[i][j] != (m2).values[i][j])
                return false;

    return true;
}

bool isEMatrix(matrix m){
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            if ((i != j && (m).values[i][j] != 0) || (i == j && (m).values[i][j] != 1))
                return false;

    return true;
}

bool isSymmetricMatrix(matrix m){
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            if ((m).values[i][j] != (m).values[j][i])
                return false;

    return true;
}

void  transposeSquareMatrix(matrix m){
    if (!isSquareMatrix(m)){
        fprintf(stderr, "bad index!");
        exit(1);
    }

    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            swap(&(m).values[i][j], &(m).values[j][i]);
}

position getMinValuePos(matrix m){
    int minValue = (m).values[0][0];
    position minPos = {0, 0};

    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            if ((m).values[i][j] < minValue){
                minValue = (m).values[i][j];
                (minPos).colIndex = j;
                (minPos).rowIndex = i;
            }
    return minPos;
}

position getMaxValuePos(matrix m){
    int maxValue = (m).values[0][0];
    position maxPos = {0, 0};

    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            if ((m).values[i][j] > maxValue){
                maxValue = (m).values[i][j];
                (maxPos).colIndex = j;
                (maxPos).rowIndex = i;
            }
    return maxPos;
}

void insertionSortMatrix(int *a, matrix *m, void (f)(matrix *, int, int), int rowOrCols){
    for (int i = 0; i < rowOrCols; ++i) {
        int k = i;
        while (k > 0 && a[i - 1] >= a[k]){
            swap(&a[i - 1], &a[k]);
            f(m, i - 1, k);

            k--;
        }
    }
}

void insertionSortRowsMatrixByRowsCriteria(matrix *m, int (*criteria)(int *, int)){
    int *rowsArrCriteria = (int *) malloc((m)->nRows * sizeof(int));
    for (int i = 0; i < (m)->nRows; ++i)
        rowsArrCriteria[i] = criteria((m)->values[i], (m)->nCols);

    insertionSortMatrix(rowsArrCriteria, m, swapRows, (m)->nRows);

    free(rowsArrCriteria);
}

void insertionSortRowsMatrixByColsCriteria(matrix *m, int (*criteria)(int *, int)){
    int *colsArrCriteria = (int*) malloc((m)->nCols * sizeof(int));
    for (int i = 0; i < (m)->nCols;++i){
        int *t = (int*) malloc((m)->nRows * sizeof (int));
        for (int j = 0; j < (m)->nRows; ++j) {
            t[i] = (m)->values[i][j];
        }
        colsArrCriteria[i] = criteria(t, m->nCols);

        free(t);
    }
    insertionSortMatrix(colsArrCriteria, m, swapColumns, (m)->nCols);

    free(colsArrCriteria);
}






