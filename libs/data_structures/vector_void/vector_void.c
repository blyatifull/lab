#include "vector_void.h"

vectorVoid createVectorV(size_t size, size_t baseTypeSize){
    int *v = (void *)malloc(size * baseTypeSize);

    if (v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {v, 0, size, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (newCapacity == 0) {
        (v)->data = NULL;
    }
    else if (newCapacity < (v)->size) {
        (v)->size = newCapacity;
    }
    else if ((v)->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    (v)->data = (void *)realloc((v)->data, newCapacity * v->baseTypeSize);
    (v)->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, 0);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVector(vectorVoid  *v){
    free(v->data);
}



