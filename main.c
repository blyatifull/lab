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

int main() {
    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);

    m = mulMatrices(m, m);

    outputMatrix(m);

    return 0;
}
