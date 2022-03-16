#include "sort.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void RadixSort_(int *a, int *n) {
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = a; j < n; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = n - 1; j >= a; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = a; j < n; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void RadixSort(int *arr, int size) {
    RadixSort_(arr, arr + size);
}


void BubbleSort (int *arr, int size){
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
}

void InsertionSort (int *arr, int size){
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
}

void SelectionSort (int *arr, int size){
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

void CombSort(int *arr, int size) {
    int step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; j < size; ++i, ++j)
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
                swapped = 1;
            }
    }
}

void ShellSort (int *arr, int size){
    int i, j, step;
    int temp;
    for (step = size / 2; step > 0; step /= 2 ) {
        for (i = step; i < size; i++) {
            temp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (temp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
}

long long GetBubbleSortNComp(int *arr, int size) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < size - 1; i++)
        for (int j = size - 1; ++nComps && j > i; j--)
            if (++nComps && arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
            }
    return nComps;
}

long long GetSelectionSortNComp(int *arr, int size) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < size; i++) {
        int min = arr[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < size; j++)
            if (++nComps && arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&arr[i], &arr[minIndex]);
    }

    return nComps;
}

long long GetInsertionSortNComp(int *arr, int size) {
    long long nComps = 0;
    for (int i = 1; ++nComps && i < size; i++) {
        int t = arr[i];
        int j = i;
        while (++nComps && j > 0 && arr[j - 1] > t) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = t;
    }
    return nComps;
}

long long GetCombSortNComp(int *arr, int size) {
    int step = size;
    int swapped = 1;
    long long nComps = 0;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
                swapped = 1;
            }
    }
    return nComps;
}

long long GetShellSortNComp(int *arr, int size) {
    long long nComps = 0;
    int j;
    int tmp;
    for (int step = size / 2; ++nComps && step > 0; step /= 2)
        for (int i = step; ++nComps && i < size; i++) {
            tmp = arr[i];
            for (j = i; ++nComps && j >= step; j -= step) {
                if (++nComps && tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
    return nComps;
}

long long GetRadixSortNComps_(int *arr, int *size) {
    long long nComps = 0;
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = size - arr;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++)
            c[j] = 0;

        for (int *j = arr; ++nComps && j < size; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; ++nComps && j < M; j++)
            c[j] += c[j - 1];

        for (int *j = size - 1; ++nComps && j >= arr; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = arr; ++nComps && j < size; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
    return nComps;
}

void GetRadixSortNComps(int *arr, int size) {
    GetRadixSortNComps_(arr, arr + size);
}

