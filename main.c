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

int main() {
    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);

    m = mulMatrices(m, m);

    outputMatrix(m);

    return 0;
}
