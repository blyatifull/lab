#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/matrix/matrix.h"

void swapRowsWithMinAndMaxElements(matrix m){
    position maxElementPos = getMaxValuePos(m);
    position minElementPos = getMinValuePos(m);

    swapRows(m, (maxElementPos).rowIndex, (minElementPos).rowIndex);
}

int main() {
    matrix x = getMemMatrix(3, 3);

    inputMatrix(x);

    swapRowsWithMinAndMaxElements(x);

    outputMatrix(x);

    return 0;
}
