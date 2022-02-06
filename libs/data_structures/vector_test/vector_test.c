#include "vector_test.h"

void test_pushBack_notEmptyVector(){
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    clear(&v);
}

void test_pushBack_EmptyVector(){

}