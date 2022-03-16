#include "dismath.h"

// 1
void setUnion(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    for (size_t i = 0; i < sizeA; ++i)
        c[i] = a[i];
    *sizeC = sizeA;

    for (size_t i = 0; i < sizeB; ++i) {
        bool isUnique = true;

        for (size_t j = 0; j < sizeA; ++j) {
            if (b[i] == a[j]){
                isUnique = false;
                break;
            }
        }

        if (isUnique){
            (*sizeC)++;
            c[*sizeC] = b[i];
        }
    }
}

// 2
void setIntersection(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int k = 0;
    for (int i = 0; i < sizeA; ++i) {
        bool isUnique = true;

        for (int j = 0; j < sizeB; ++j) {
            if (a[i] == b[j]){
                isUnique = false;
                break;
            }
        }

        if (!isUnique){
            c[k] = a[i];
            (*sizeC)++;
            k++;
        }
    }
}

// 3
void setDifference(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int k = 0;
    for (int i = 0; i < sizeA; ++i) {
        bool isNotInSecondArr = true;

        for (int j = 0; j < sizeB; ++j) {
            if (a[i] == b[j]){
                isNotInSecondArr = false;
                break;
            }
        }

        if (isNotInSecondArr){
            c[k] = a[i];
            (*sizeC)++;
            k++;
        }
    }
}

// 4
void setSymmetricDifference(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int k = 0;
    for (int i = 0; i < sizeA; ++i) {
        bool isUnique = true;

        for (int j = 0; j < sizeB; ++j) {
            if (a[i] == b[j]){
                isUnique = false;
                break;
            }
        }

        if (isUnique){
            c[k] = a[i];
            (*sizeC)++;
            k++;
        }
    }

    for (int i = 0; i < sizeB; ++i) {
        bool isUnique = true;

        for (int j = 0; j < sizeA; ++j) {
            if (b[i] == a[j]){
                isUnique = false;
                break;
            }
        }

        if (isUnique){
            c[k] = b[i];
            (*sizeC)++;
            k++;
        }
    }
}

// 5
bool setIsIdenticalValues(const int a[], const size_t sizeA, const int b[], const size_t sizeB){
    bool isFound = false;
    for (int i = 0; i < sizeA; ++i) {
        for (int j = 0; j < sizeB; ++j)
            if (b[j] == a[i]){
                isFound = true;
                break;
            }
        if (isFound)
            return false;
    }

    return true;
}

// 6
bool setIsEqual(const int a[], const size_t sizeA, const int b[], const size_t sizeB){
    int counter = 0;
    for (int i = 0; i < sizeA; ++i)
        for (int j = 0; j < sizeB; ++j)
            if (a[i] == b[j]){
                counter += 2;
                break;
            }

    return counter == sizeA + sizeB;
}

// 7
bool setIsNotIdenticalValues(const int a[], const size_t sizeA, const int b[], const size_t sizeB){
    for (int i = 0; i < sizeA; ++i)
        for (int j = 0; j < sizeB; ++j)
            if (a[i] == b[j])
                return false;

    return true;
}

// 8
void setOrderedUnion(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB){
        if (a[i] == b[j]){
            c[*sizeC] = a[i];
            i++;
            j++;
            (*sizeC)++;
        }
        else if (a[i] < b[j]){
            c[*sizeC] = a[i];
            i++;
            (*sizeC)++;
        }
        else{
            c[*sizeC] = b[j];
            j++;
            (*sizeC)++;
        }
    }

    for (int k = j; k < sizeB; ++k) {
        c[*sizeC] = b[k];
        (*sizeC)++;
    }

    for (int k = i; k < sizeA; ++k) {
        c[*sizeC] = a[k];
        (*sizeC)++;
    }
}

// 9
void setOrderedIntersection(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB){
        if (a[i] == b[j]){
            c[*sizeC] = a[i];
            i++;
            j++;
            (*sizeC)++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
}

// 10
void setOrderedDifference(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB){
        if (a[i] == b[j]){
            i++;
            j++;
        }
        else if (a[i] < b[j]){
            c[*sizeC] = a[i];
            i++;
            (*sizeC)++;
        }
        else
            j++;
    }


    for (int k = i; k < sizeA; ++k) {
        c[*sizeC] = a[k];
        (*sizeC)++;
    }
}

// 11
void setOrderedSymmetricDifference(const int a[], const size_t sizeA, const int b[], const size_t sizeB, int c[], size_t *sizeC){
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB){
        if (a[i] == b[j]){
            i++;
            j++;
        }
        else if (a[i] < b[j]){
            c[*sizeC] = a[i];
            i++;
            (*sizeC)++;
        }
        else{
            c[*sizeC] = b[j];
            j++;
            (*sizeC)++;
        }
    }

    for (int k = j; k < sizeB; ++k) {
        c[*sizeC] = b[k];
        (*sizeC)++;
    }

    for (int k = i; k < sizeA; ++k) {
        c[*sizeC] = a[k];
        (*sizeC)++;
    }
}

// 12
bool setOrderedIsEqual(const int A[], const size_t sizeA, const int B[], const size_t sizeB){
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB){
        if (A[i] == B[j]){
            i++;
            j++;
        }
        else if (B[j] < A[i])
            j++;
        else
            return false;
    }

    return i >= sizeA;
}

void task4a (){
    int A[100] = {1, 2, 3, 8};
    size_t a = 4;
    int B[100] = {3, 6, 7};
    size_t b = 3;
    int C[100] = {2, 3, 4, 5, 7};
    size_t c = 5;
    int D[100];
    size_t d = 0;
    int T1[100];
    size_t t1 = 0;
    int T2[100];
    size_t t2 = 0;
    int T3[100];
    size_t t3 = 0;

    setOrderedUnion(A, a, B, b, T1, &t1);
    setOrderedDifference(T1, t1, C, c, T2, &t2);
    setOrderedIntersection(A, a, B, b, T3, &t3);
    setOrderedUnion(T2, t2, T3, t3, D, &d);

    outputArray_(D, d);

}

void task4b (){
    int A[100] = {1, 2, 3, 4, 5, 6, 7};
    size_t a = 7;
    int B[100] = {2, 5, 6, 9, 10};
    size_t b = 5;
    int C[100] = {4, 7, 8, 11, 12};
    size_t c = 5;
    int D[100];
    size_t d = 0;
    int T1[100];
    size_t t1 = 0;
    int T2[100];
    size_t t2 = 0;
    int T3[100];
    size_t t3 = 0;

    setOrderedSymmetricDifference(A, a, C, c, T1, &t1);
    setOrderedDifference(T1, t1, B, b, T2, &t2);
    setOrderedDifference(B, b, A, a, T3, &t3);
    setOrderedUnion(T3, t3, T2, t2, D, &d);

    outputArray_(D, d);


}