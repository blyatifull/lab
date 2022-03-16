#ifndef COURSE_SORT_H
#define COURSE_SORT_H

#include <malloc.h>

void swap (int *a, int *b);

void RadixSort(int *arr, int size);

void BubbleSort (int *arr, int size);

void InsertionSort (int *arr, int size);

void SelectionSort (int *arr, int size);

void ShellSort (int *arr, int size);

void CombSort(int *arr, int size);

long long GetBubbleSortNComp(int *arr, int size);

long long GetSelectionSortNComp(int *arr, int size);

long long GetInsertionSortNComp(int *arr, int size);

long long GetCombSortNComp(int *arr, int size);

long long GetShellSortNComp(int *arr, int size);

void GetRadixSortNComps(int *arr, int size);

#endif //COURSE_SORT_H
