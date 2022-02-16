#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/matrix/matrix.h"

void swapRowsWithMinAndMaxElements(matrix m){
    position maxElementPos = getMaxValuePos(m);
    position minElementPos = getMinValuePos(m);

    swapRows(m, (maxElementPos).rowIndex, (minElementPos).rowIndex);
}

void insertionSortRowsByNonDecreasingMax(matrix m){
    insertionSortRowsByCriteria(m, getMax);
}

void insertionSortColsByNonDecreasingMin(matrix m){
    insertionSortColsByCriteria(m, getMin);
}

void getSquareOfMatrixIfSymmetric(matrix m){
    if(isSymmetricMatrix(m))
        mulMatrices(m, m);
}

void transposeIfMatrixHasEqualSumOfRows(matrix m){
    long long sumArr[10];
    for (int i = 0; i < (m).nRows; ++i)
        sumArr[i] = getSum(sumArr[i], (m).nCols);

    if(isUnique(sumArr, (m).nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    return isEMatrix(mulMatrices(m1, m2));
}

/***************** 7 задача *****************/

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



int getMinInArea(matrix m){
    position leftElement = getMaxValuePos(m);
    position rightElement = getMaxValuePos(m);

    int minElement = (m).values[(leftElement).rowIndex][(leftElement).colIndex];
    int subArr[10];
    int sizeSubArr = 1;
    while((leftElement).rowIndex >= 0 && (rightElement).rowIndex >= 0){
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

        minElement = getMin(subArr, sizeSubArr);

        (rightElement).rowIndex--;
        (rightElement).colIndex++;
        (leftElement).rowIndex--;
        (leftElement).colIndex--;
        sizeSubArr += 2;
    }

    return minElement;
}


int main() {
    matrix m = getMemMatrix(3, 4);

    inputMatrix(m);

    int min = getMinInArea(m);

    printf("%d", min);

    return 0;
}
