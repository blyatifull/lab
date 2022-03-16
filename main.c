#include "libs/data_structures/time_test/time_test.h"

double GetTime (){
    clock_t start = clock();
    int size = 200000;
    int arr[200000];

    generateRandomArray(arr, size);

    int element, posElement;
    for (int i = 0; i < size; ++i) {
        element = arr[i];
        posElement = i - 1;
        while (posElement >= 0 && arr[posElement] > element){
            arr[posElement + 1] = arr[posElement];
            posElement = posElement - 1;
        }
        arr[posElement + 1] = element;
    }

    clock_t end = clock();
    clock_t sort = end - start;
    return (double) sort / CLOCKS_PER_SEC;
}

int main() {
    printf("%lf", GetTime());

    return 0;
}
