#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/matrix/matrix.h"
#include <math.h>

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

int cmp_long_long(const void *pa, const void *pb){
    long long arg1 = *(const long long*)pa;
    long long arg2 = *(const long long*)pb;

    if (arg1 < arg2)
        return -1;
    else if(arg1 > arg2)
        return 1;
    else
        return 0;
}

int countNUnique(const long long *a, int size){
    int counterUnique = 0;
    for (int left = -1, middle = 0, right = 1; middle < size; ++middle)
        if (a[left] != a[middle] && a[middle] != a[right])
            counterUnique++;

    return counterUnique;
}

int countEqClassesByRowsSum(matrix m){
    long long arrayRowSum[15];
    for (int i = 0; i < (m).nRows; ++i) {
        arrayRowSum[i] = getSum((m).values[i], (m).nCols);
    }

    qsort(arrayRowSum, (m).nCols, sizeof(long long), cmp_long_long);

    int counterClasses = 1;
    for (int i = 0; i < (m).nRows - 1; ++i)
        if (arrayRowSum[i] != arrayRowSum[i + 1])
            counterClasses++;

    int counterUniqueElements = countNUnique(arrayRowSum, (m).nCols);

    return counterClasses - counterUniqueElements;
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




int main() {
    matrix m = getMemMatrix(6, 2);

    inputMatrix(m);

    printf("%d", countEqClassesByRowsSum(m));

    return 0;
}
