#include "vector_test.h"

void test_pushBack_notEmptyVector(){
    vector v = createVector(5);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 5);

    deleteVector(&v);
}

void test_pushBack_EmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmpty(){
    vector v = createVector(0);
    pushBack(&v, 42);
    pushBack(&v, 126);
    pushBack(&v, 84);

    assert(atVector(&v, 0) == &v.data[0]);
    assert(atVector(&v, 1) == &v.data[1]);
    assert(atVector(&v, 2) == &v.data[2]);

    deleteVector(&v);
}

void test_atVector_requestToLastElement(){
    vector v = createVector(0);
    pushBack(&v, 42);

    assert(atVector(&v, v.size - 1) == &v.data[v.size - 1]);

    deleteVector(&v);
}

void test_back_oneElementInVector(){
    vector v = createVector(0);
    pushBack(&v, 42);

    assert(back(&v) == &v.data[0]);

    deleteVector(&v);
}

void test_front_oneElementInVector(){
    vector v = createVector(0);
    pushBack(&v, 42);

    assert(front(&v) == &v.data[0]);

    deleteVector(&v);
}

void test_vector(){
    test_pushBack_notEmptyVector();
    test_pushBack_EmptyVector();

    test_atVector_notEmpty();
    test_atVector_requestToLastElement();

    test_back_oneElementInVector();
    test_front_oneElementInVector();
}