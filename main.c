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

/***************** 8 задача *****************/

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



int main() {
    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);

    m = mulMatrices(m, m);

    outputMatrix(m);

    return 0;
}
