#include "libs/data_structures/vector/vector.h"
#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/vector_test/vector_test.h"

void test_pushBack_notEmptyVector(){
    vector v = createVector(5);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 5);

    clear(&v);
}

void test_pushBack_EmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    clear(&v);
}

int main() {
    test_pushBack_notEmptyVector();

    return 0;
}
