#include "vector_void.h"

vectorVoid createVectorV(size_t size, size_t baseTypeSize){
    void *v = (void *)malloc(size * baseTypeSize);

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

    (v)->data = (void *)realloc((v)->data, newCapacity * (v)->baseTypeSize);
    (v)->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v){
    reserveV((v), 0);
}

void clearV(vectorVoid *v){
    (v)->size = 0;
}

void deleteVector(vectorVoid  *v){
    free((v)->data);
}

bool isFullV(vectorVoid *v){
    return (v)->size == (v)->capacity;
}

bool isEmpty(vectorVoid *v){
    return (v)->size == 0;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index < (v)->size) {
        char *source = (char *) (v)->data + index * (v)->baseTypeSize;
        memcpy(destination, source, (v)->baseTypeSize);
        return;
    }

    fprintf(stderr, "indexError: index[%u] is not exist", index);
    exit(1);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index < (v)->capacity) {
        char *destination = (char *) (v)->data + index * (v)->baseTypeSize;
        memcpy(destination, source, (v)->baseTypeSize);
        return;
    }

    fprintf(stderr, "indexError: index[%u] is not exist", index);
    exit(1);
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v))
        reserveV(v, (v)->capacity * 2);
    else if((v)->capacity == 0)
        reserveV(v, 1);

    char *lastElement = (char *) (v)->data + (v)->size * (v)->baseTypeSize;
    memcpy(lastElement, source, (v)->baseTypeSize);
}

void popBackV(vectorVoid *v){
    if(isEmptyV(v)){
        fprintf(stderr, "Is empty vector!");
        exit(1);
    }

    (v)->size--;
}



