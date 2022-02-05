#include "vector.h"

vector createVector(size_t size) {
    int *v = (int *)malloc(size * sizeof(int));

    if (v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    else if (size == 0){
        v = NULL;
    }

    return (vector) {v, 0, size};
}

void reserve(vector *v, size_t newCapacity){
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

    (v)->capacity = newCapacity;
}

void clear(vector *v){
    (v)->size = 0;
}

void shrinkToFit (vector *v) {
    if ((v)->size != (v)->capacity) {
        (v)->data = (int *) realloc((v)->data, sizeof(int) * (v)->size);

        (v)->capacity = (v)->size;
    }
}

void deleteVector(vector *v){
    free((v)->data);
}
