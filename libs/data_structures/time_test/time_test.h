#ifndef COURSE_TIME_TEST_H
#define COURSE_TIME_TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/sort/sort.h"
#include "C:/Users/blyatifull/cLionProjects/course/libs/algorithms/array/array.h"

#define TIME_TEST(testCode, time){ \
    clock_t start_time = clock () ; \
        testCode \
    clock_t end_time = clock () ;\
    clock_t sort_time = end_time - start_time ; \
    time = ( double ) sort_time / CLOCKS_PER_SEC ; \
}


#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])


typedef struct SortFunc {
    void (*sort) (int *arr, int size);

    char arr[64];
} SortFunc;

typedef struct GeneratingFunc{
    void (*generate)(int *arr, int size);

    char arr[64];
} GeneratingFunc;

void generateOrderedArray (int *a, int size){
    for (int i = 0; i < size; ++i) {
        a[i] = i;
    }
}

void generateOrderedBackwards (int *a, int size){
    for (int i = 0; i < size; ++i) {
        a[i] = size - i;
    }
}

void generateRandomArray (int *a, int size){
    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 10000;
    }
}

double getTime() {
    clock_t start_time = clock();

    clock_t end_time = clock();
    clock_t sort_time = end_time - start_time;
    return (double) sort_time / CLOCKS_PER_SEC;
}

bool isOrdered(int *arr, int size){
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

void checkTime (void (*sortFunc) (int *, int), void (*generateFunc) (int*, int), int size, char *experimentName) {
    static int runCounter = 1;
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%d| ", runCounter++);
    printf("Name : %s\n", experimentName);

    double time;
    TIME_TEST({ sortFunc(innerBuffer, size); }, time)
    // результаты замера
    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);
// запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", "experiment");
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong !\n");

// вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);
        exit(1);
    }
}

//{SelectionSort, "SelectionSort"},
//{InsertionSort, "InsertionSort"},
//{ShellSort, "ShellSort"},
//{BubbleSort, "BubbleSort"},
//{CombSort, "CombSort"}
//{RadixSort, "RadixSort"}

//{generateRandomArray, "random"} ,
//{generateOrderedArray, "ordered"} ,
//{generateOrderedBackwards, "orderedBackwards"}

void timeExperiment () {
    // описание функций сортировки
    SortFunc sorts [] = {
            {SelectionSort, "SelectionSort"},
            {InsertionSort, "InsertionSort"},
            {ShellSort, "ShellSort"},
            {BubbleSort, "BubbleSort"},
            {CombSort, "CombSort"},
            {RadixSort, "RadixSort"}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs [] = {
            {generateRandomArray, "random"} ,
            {generateOrderedArray, "ordered"} ,
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (int size = 10000; size <= 100000; size += 10000) {
        printf ("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n") ;
        printf (" Size : %d\n", size );
        for (int i = 0; i < FUNCS_N ; i ++){
            for (int j = 0; j < CASES_N ; j ++){
                // генерация имени файла
                static char filename [128];
                sprintf(filename, "%s_%s_time ", sorts[i].arr, generatingFuncs[j].arr);
                checkTime (sorts[i].sort, generatingFuncs[j].generate, size, filename);
            }
        }
        printf ("\n");
    }
}

void checkComps(long long (*sortFunc)(int *, int),
                void (*generateFunc)(int *, int),
                int size) {
    static int runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu | ", runCounter++);

    long long comps = sortFunc(innerBuffer, size);


    // результаты замера
    printf("Status:  ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK!\n");

        printf("%zu; %lld\n", size, comps);
    }else
        printf("NO!\n");
}

#endif //COURSE_TIME_TEST_H
