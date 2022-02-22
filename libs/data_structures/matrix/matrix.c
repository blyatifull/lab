#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols){
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(sizeof(int) * nCols);
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

void inputMatrixF(matrixF m){
    for (int i = 0; i < (m).nRows; ++i)
        for (int j = 0; j < (m).nCols; ++j)
            scanf("%f", &(m).values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void inputMatricesF(matrixF *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        inputMatrixF(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < (m).nRows; ++i){
        for (int j = 0; j < (m).nCols; ++j)
            printf("%d ", (m).values[i][j]);

        printf("\b\b\n");
    }
}

void outputMatrixF(matrixF m) {
    for (int i = 0; i < (m).nRows; ++i){
        for (int j = 0; j < (m).nCols; ++j)
            printf("%f ", (m).values[i][j]);

        printf("\b\b\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        outputMatrix(ms[i]);
}

void outputMatricesF(matrixF *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i)
        outputMatrixF(ms[i]);
}

void swapRows(matrix m, int i1, int i2){
    swap((int*)&(m).values[i1], (int *)&(m).values[i2]);
}

void swapColumns(matrix m, int j1, int j2){
    for (int i = 0; i < (m).nRows; ++i)
        swap(&(m).values[i][j1], &(m).values[i][j2]);
}

bool isSquareMatrix(matrix m){
    return (m).nRows == (m).nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2){
    if ((m1).nRows != (m2).nRows || (m1).nCols != (m2).nCols)
        return false;

    for (int i = 0; i < (m1).nRows; ++i)
        if(!memcmp((m1).values[i], (m2).values[i], (m1).nCols))
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
        for (int j = i + 1; j < (m).nCols; ++j)
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
        for (int j = i + 1; j < (m).nCols; ++j)
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

void insertionSortMatrix(int *a, matrix *m, void (f)(matrix, int, int), int rowsOrCols){
    for (int i = 1; i < rowsOrCols; ++i) {
        int k = i;
        while (k > 0 && a[k - 1] >= a[k]){
            swap(&a[k - 1], &a[k]);
            f(*m, k - 1, k);

            k--;
        }
    }
}

void insertionSortRowsByCriteria(matrix m, int (criteria)(int *, int)){
    int criteriaArr[30];
    for (int i = 0; i < (m).nRows; ++i)
        criteriaArr[i] = criteria((m).values[i], (m).nCols);

    insertionSortMatrix(criteriaArr, &m, swapRows, (m).nRows);
}

void insertionSortColsByCriteria(matrix m, int (criteria)(int *, int)) {
    int criteriaArr[30];
    for (int i = 0; i < (m).nCols; ++i) {
        int tempArr[30];
        for (int j = 0; j < (m).nRows; ++j)
            tempArr[j] = (m).values[j][i];

        criteriaArr[i] = criteria(tempArr, (m).nRows);
    }

    insertionSortMatrix(criteriaArr, &m, swapColumns, (m).nCols);
}

int getMax(const int *row, int sizeRow){
    int maxElement = row[0];
    for (int i = 1; i < sizeRow; ++i)
        if (maxElement < row[i])
            maxElement = row[i];

    return maxElement;
}

int getMin(const int *row, int sizeRow){
    int minElement = row[0];
    for (int i = 0; i < sizeRow; ++i)
        if (minElement > row[i])
            minElement = row[i];

    return minElement;
}

matrix mulMatrices(matrix m1, matrix m2){
    if ((m1).nRows != (m2).nCols){
        fprintf(stderr, "(m1).nRows != (m2).nCols!");
    }

    matrix m3 = getMemMatrix((m2).nRows, (m1).nCols);
    for (int i = 0; i < (m1).nCols; ++i) {
        for (int j = 0; j < (m2).nRows; ++j) {
            (m3).values[i][j] = 0;
            for (int k = 0; k < (m1).nRows; ++k) {
                (m3).values[i][j] += (m1).values[i][k] * (m2).values[k][j];
            }
        }
    }

    return m3;
}

long long getSum(const int *row, int sizeRow){
    long long sum = 0;
    for (int i = 0; i < sizeRow; ++i)
        sum += row[i];

    return sum;
}

bool isUnique(const long long *arr, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            if (i != j && arr[i] == arr[j])
                return false;
            return true;
        }
}

int countNUnique(const long long *a, int size){
    int uniqueElements = 0;
    for (int i = 0; i < size; ++i) {
        bool isUnique = true;
        for (int j = 0; j < size; ++j) {
            if (i != j && a[i] == a[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
            uniqueElements++;
    }

    return uniqueElements;
}

