#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/matrix/matrix.h"
#include <math.h>

#define EPS 0.000001

/********************************** 1 TASK ******************************/

void swapRowsWithMinAndMaxElements(matrix m){
    position maxElementPos = getMaxValuePos(m);
    position minElementPos = getMinValuePos(m);

    swapRows(m, (maxElementPos).rowIndex, (minElementPos).rowIndex);
}

/********************************** 2 TASK ******************************/

void insertionSortRowsByNonDecreasingMax(matrix m){
    insertionSortRowsByCriteria(m, getMax);
}

/********************************** 3 TASK ******************************/
void insertionSortColsByNonDecreasingMin(matrix m){
    insertionSortColsByCriteria(m, getMin);
}

/********************************** 4 TASK ******************************/

void getSquareOfMatrixIfSymmetric(matrix m){
    if(isSymmetricMatrix(m))
        mulMatrices(m, m);
}

/********************************** 5 TASK ******************************/

void transposeIfMatrixHasEqualSumOfRows(matrix m){
    long long sumArr[10];
    for (int i = 0; i < (m).nRows; ++i)
        sumArr[i] = getSum(sumArr[i], (m).nCols);

    if(isUnique(sumArr, (m).nRows))
        transposeSquareMatrix(m);
}

/********************************** 6 TASK ******************************/

bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    return isEMatrix(mulMatrices(m1, m2));
}

/********************************** 7 TASK ******************************/

int getMaxDiagonalElement(matrix m, int iRow, int iCol){
    int maxElement = (m).values[iRow][iCol];
    while (iRow < (m).nRows && iCol < (m).nCols)
        maxElement = max(maxElement, (m).values[iRow++][iCol++]);

    return maxElement;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m){
    long long sumElement = 0;
    for (int i = 1; i < (m).nRows; ++i)
        sumElement += getMaxDiagonalElement(m, i, 0);

    for (int i = 0; i < (m).nCols; ++i)
        sumElement += getMaxDiagonalElement(m, 0, i);

    return sumElement;
}

/********************************** 8 TASK ******************************/

int getMinInArea(matrix m){
    position leftElement = getMaxValuePos(m);
    position rightElement = getMaxValuePos(m);

    int minElement = (m).values[(leftElement).rowIndex][(leftElement).colIndex];
    int minInSubArray = (m).values[(leftElement).rowIndex][(leftElement).colIndex];
    int subArr[10];
    int sizeSubArr = 1;
    while((leftElement).rowIndex >= 0){
        if ((leftElement).colIndex == -1) {
            (leftElement).colIndex++;
            sizeSubArr--;
        }

        if ((rightElement).colIndex == m.nCols) {
            (rightElement).colIndex--;
            sizeSubArr--;
        }

        int i = 0;
        while(i < sizeSubArr){
            subArr[i] = (m).values[(leftElement).rowIndex][(leftElement).colIndex + i];
            i++;
        }

        minInSubArray = getMin(subArr, sizeSubArr);
        if(minElement > minInSubArray)
            minElement = minInSubArray;

        (rightElement).rowIndex--;
        (rightElement).colIndex++;
        (leftElement).rowIndex--;
        (leftElement).colIndex--;
        sizeSubArr += 2;
    }

    return minElement;
}

/********************************** 9 TASK *******************************/

float getDistance(int *a, int size){
    double distance = 0;
    for (int i = 0; i < size; ++i) {
        distance += pow(a[i], 2);
    }

    return sqrt(distance);
}

void insertionSortMatrixF(float *a, matrix *m, void (f)(matrix, int, int), int rowsOrCols){
    for (int i = 1; i < rowsOrCols; ++i) {
        int k = i;
        while (k > 0 && a[k - 1] >= a[k]){
            swap(&a[k - 1], &a[k]);
            f(*m, k - 1, k);

            k--;
        }
    }
}

void insertionSortRowsByCriteriaF(matrix m, float (criteria)(int *, int)){
    float criteriaArr[30];
    for (int i = 0; i < (m).nRows; ++i)
        criteriaArr[i] = criteria((m).values[i], (m).nCols);

    insertionSortMatrixF(criteriaArr, &m, swapRows, (m).nRows);
}

void sortByDistances(matrix m){
    insertionSortRowsByCriteriaF(m, getDistance);
}

/********************************** 10 TASK ******************************/

int compare_long_long(const void *a, const void *b) {
    long long arg1 = *(const long long *) a;
    long long arg2 = *(const long long *) b;

    if (arg1 < arg2) {
        return -1;
    }

    if (arg1 > arg2) {
        return 1;
    }

    return 0;
}

int countEqClassesByRowsSum(matrix m){
    long long arrayRowSum[15];
    for (int i = 0; i < (m).nRows; ++i) {
        arrayRowSum[i] = getSum((m).values[i], (m).nCols);
    }

    qsort(arrayRowSum, (m).nRows, sizeof(long long), compare_long_long);

    int counterClasses = 0;
    for (int i = 1; i < (m).nRows; ++i) {
        if (arrayRowSum[i] != arrayRowSum[i - 1]){
            if (counterClasses == 0)
                counterClasses++;

            counterClasses++;
        }
    }

    return counterClasses;
}


/********************************** 11 TASK ******************************/

int getNSpecialElement(matrix m){
    long long sumColArray[10];
    int colArray[10];
    for (int i = 0; i < (m).nCols; ++i) {
        for (int j = 0; j < (m).nRows; ++j) {
            colArray[i] = (m).values[j][i];
        }
        sumColArray[i] = getSum(colArray, (m).nRows);
    }

    int counter = 0;
    for (int i = 0; i < (m).nCols; ++i)
        for (int j = 0; j < (m).nRows; ++j)
            if (sumColArray[i] - (m).values[j][i] < sumColArray[i])
            counter++;

    return counter;
}

/********************************** 12 TASK ******************************/

position getLeftMin(matrix m){
    position minElementPos = {0, 0};
    int minValue = (m).values[0][0];
    for (int i = 0; i < (m).nRows; ++i) {
        for (int j = 0; j < (m).nCols; ++j) {
            if (minValue > (m).values[i][j]){
                minValue = (m).values[i][j];
                (minElementPos).rowIndex = i;
                (minElementPos).colIndex = j;
            }
        }
    }

    return minElementPos;
}

void swapPenultimateRow(matrix m){
    int penultimateRow = (m).nRows - 2;
    position leftMinPos = getLeftMin(m);
    int colArr[10];
    for (int i = 0; i < (m).nRows; ++i) {
        colArr[i] = (m).values[i][(leftMinPos).colIndex];
    }

    for (int i = 0; i < (m).nCols; ++i) {
        (m).values[penultimateRow][i] = colArr[i];
    }
}

/********************************** 13 TASK ******************************/

bool isNonDescendingSorted(const int *a, const int n){
    for (int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m){
    for (int i = 0; i < (m).nRows; ++i)
        if (!isNonDescendingSorted((m).values[i], (m).nRows))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){
    int counterSortedMatrices = 0;
    for (int i = 0; i < nMatrix; ++i)
        counterSortedMatrices += hasAllNonDescendingRows(ms[i]);

    return counterSortedMatrices;
}

/********************************** 14 TASK ******************************/

int countValues(const int *a, int n, int value){
    int counterValue = 0;
    for (int i = 0; i < n; ++i)
        counterValue += a[i] == value;

    return counterValue;
}

int countZeroRows(matrix m){
    int counterZeroRows = 0;
    for (int i = 0; i < (m).nRows; ++i)
        counterZeroRows += countValues((m).values[i], (m).nCols, 0) == (m).nCols;

    return counterZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix){
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; ++i) {
        int counterZeroRows = countZeroRows(ms[i]);
        if (maxZeroRows < counterZeroRows)
            maxZeroRows = counterZeroRows;
    }

    for (int i = 0; i < nMatrix; ++i) {
        if (countZeroRows(ms[i]) == maxZeroRows)
            outputMatrix(ms[i]);
    }
}

/********************************** 15 TASK ******************************/

float getAbsoluteMax(matrixF m){
    float absoluteMax = fabs((m).values[0][0]);
    for (int i = 0; i < (m).nRows; ++i) {
        for (int j = 0; j < (m).nCols; ++j) {
            float absValue = fabs((m).values[i][j]);
            if (absoluteMax < absValue)
                absoluteMax = absValue;
        }
    }

    return absoluteMax;
}

void printMatrixWithMinNormMax(matrixF *ms, int nMatrix){
    float minAbsoluteMax = getAbsoluteMax(ms[0]);
    for (int i = 1; i < nMatrix; ++i) {
        float absoluteMax = getAbsoluteMax(ms[i]);
        if (minAbsoluteMax > absoluteMax)
            minAbsoluteMax = absoluteMax;
    }

    for (int i = 0; i < nMatrix; ++i) {
        if (getAbsoluteMax(ms[i]) - minAbsoluteMax < EPS)
            outputMatrixF(ms[i]);
    }
}

int main() {
    matrixF *ms = getMemArrayOfMatrices(3, 2, 2);
    int nMatrices = 3;
    inputMatricesF(ms, nMatrices);

    printMatrixWithMinNormMax(ms, nMatrices);

    freeMemMatrices(ms, nMatrices);

    return 0;
}
