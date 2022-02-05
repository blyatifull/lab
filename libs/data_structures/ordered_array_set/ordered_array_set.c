#include "ordered_array_set.h"

int compare_ints2(const void *a, const void *b)
{
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a){
    if(a->size != a->capacity){
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);

        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create(size_t capacity){
    return (ordered_array_set){malloc(capacity * sizeof(int)), 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size){
    ordered_array_set set = ordered_array_set_create(size);
    for (register size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value){
    size_t searchNumberIndex = binarySearch_(set->data, set->size, value);
    return searchNumberIndex != set->size ? searchNumberIndex : set->size;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2){
    if (set1.size != set2.size)
        return false;

    return memcmp(set1.data, set2.data, set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set){
    ordered_array_set intersectionSet = ordered_array_set_intersection(set, subset);
    return ordered_array_set_isEqual(subset, intersectionSet);
}

void ordered_array_set_isAbleAppend(ordered_array_set *set){
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        append_(set->data, &set->size, value);
        qsort(set->data, set->size, sizeof(int) * set->size, compare_ints2);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value){
    size_t indexValue = ordered_array_set_in(set, value);

    assert(set->size != indexValue);

    set->data[set->size - 1] = set->data[indexValue];
    set->size--;
    ordered_array_set_shrinkToFit(set);
    qsort(set->data, set->size, sizeof(int) * set->size, compare_ints2);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    size_t newSize = set1.size;
    int *set3 = (int *) malloc(newSize * sizeof(int));
    memcpy(set3, set1.data, set1.size * sizeof(int));

    size_t i = 0;
    while (i < set1.size){
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size)
            append_(set3, &newSize, set2.data[i]);
        i++;
    }

    qsort(set3, newSize, sizeof(int) * newSize, compare_ints2);
    return (ordered_array_set) {set3, newSize, set1.capacity};
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2){
    size_t newSize = set1.size;
    int *set3 = (int *) malloc(newSize * sizeof(int));

    size_t i = 0;
    while (i < set2.size){
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size)
            append_(set3, &newSize, set2.data[i]);
        i++;
    }

    qsort(set3, newSize, sizeof(int) * newSize, compare_ints1);
    return (ordered_array_set) {set3, newSize, set2.capacity};
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    int *set3 = (int *) malloc(set1.size * sizeof(int));
    size_t sizeOfNewSet = set1.size;

    size_t i = 0;
    while (i < set2.size) {
        size_t j = ordered_array_set_in(&set1, set2.data[i]);
        if (j != sizeOfNewSet)
            append_(set3, &sizeOfNewSet, set1.data[i]);
        else
            sizeOfNewSet--;
        i++;
    }

    qsort(set3, sizeOfNewSet, sizeof(int) * sizeOfNewSet, compare_ints1);
    ordered_array_set_shrinkToFit(&(ordered_array_set) {set3, sizeOfNewSet, set1.capacity});
    return (ordered_array_set) {set3, sizeOfNewSet, set1.capacity};
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set resultSet1 = ordered_array_set_difference(set1, set2);
    ordered_array_set resultSet2 = ordered_array_set_difference(set2, set1);
    ordered_array_set result = ordered_array_set_union(resultSet1, resultSet2);

    ordered_array_set_delete(resultSet1);
    ordered_array_set_delete(resultSet2);

    return result;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet){
    return ordered_array_set_union(set, universumSet);
}


void ordered_array_set_print(ordered_array_set set){
    printf("{");

    for (register size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set){
    free(set.data);
}

void test_ordered_array_set_in1(){
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    int value = 1;
    size_t resSet = ordered_array_set_in(&set, value);
    size_t needRes = 0;

    assert(needRes == resSet);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_in2(){
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = -1;
    size_t resSet = ordered_array_set_in(&set, value);
    size_t needRes = 3;

    assert(needRes == resSet);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_in3(){
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 0, 1, 2, 3, 4}, 9);
    int value = 0;
    size_t resSet = ordered_array_set_in(&set, value);
    size_t needRes = 4;

    assert(needRes == resSet);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_in(){
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
}

void test_ordered_array_set_isSubset1(){
    ordered_array_set subSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    bool resSet = ordered_array_set_isSubset(subSet, set);
    bool needRes = 1;

    assert(needRes == resSet);

    ordered_array_set_delete(subSet);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset2(){
    ordered_array_set subSet = ordered_array_set_create_from_array((int[]) {1, 2, 3, 6}, 4);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    bool resSet = ordered_array_set_isSubset(subSet, set);
    bool needRes = 0;

    assert(needRes == resSet);

    ordered_array_set_delete(subSet);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset3(){
    ordered_array_set subSet = ordered_array_set_create_from_array((int[]) {0}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0}, 0);
    bool resSet = ordered_array_set_isSubset(subSet, set);
    bool needRes = 0;

    assert(needRes == resSet);

    ordered_array_set_delete(subSet);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset(){
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
}

void test_ordered_array_set_insert1(){
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-4, -3, -2, -1}, 5);
    int value = -5;
    ordered_array_set_insert(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-1, -3, -2, -4, -5}, 5);

    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_insert2(){
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {1, 3, 2, 4}, 5);
    int value = 0;
    ordered_array_set_insert(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){0, 1, 2, 3, 4}, 5);

    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_insert3(){
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-4, -3, -2, -1}, 4);
    int value = -4;
    ordered_array_set_insert(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-4, -3, -2, -1}, 4);

    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_insert(){
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
    test_ordered_array_set_insert3();
}

void test_ordered_array_set_deleteElement1(){
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = -5;
    ordered_array_set_deleteElement(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-3, -2, -1}, 3);

    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_deleteElement2(){
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = -3;
    ordered_array_set_deleteElement(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-5, -2, -1}, 3);

    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_deleteElement3(){
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = 3;
    ordered_array_set_deleteElement(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-5, -3, -2, -1}, 4);

    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_deleteElement(){
    test_ordered_array_set_deleteElement1();
    test_ordered_array_set_deleteElement2();
    test_ordered_array_set_deleteElement3();
}

void test_ordered_array_set_union1(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 1, 2, 3}, 7);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_union2(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-3, -2, -1}, 3);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_union3(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 2, 3}, 6);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_union(){
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
    test_ordered_array_set_union3();
}

void test_ordered_array_set_intersection1(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {0}, 0);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_intersection2(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-1}, 1);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_intersection3(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 1, 2, 3, 5, 6}, 9);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-9, 2, 3, 6}, 4);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {2, 3, 6}, 3);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_intersection(){
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
    test_ordered_array_set_intersection3();
}

void test_ordered_array_set_difference1(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 5}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {0, 3, 6}, 3);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_difference2(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4, 5, 63}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {5, 63}, 2);


    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_difference3(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-4, 1, 3, 5, 7, 9}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, 3, 5, 7, 9}, 5);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1}, 1);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}


void test_ordered_array_set_difference(){
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
    test_ordered_array_set_difference3();
}
void test_ordered_array_set_symmetricDifference1(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 5, 6, 7}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, 3, 5, 7, 9}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, -4, 6, 2, 9, 3}, 6);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_symmetricDifference2(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_symmetricDifference3(){
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -4, -2, 5, 6}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-5, -4, -2, 5, 6}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {0}, 0);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_symmetricDifference(){
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
    test_ordered_array_set_symmetricDifference3();
}

void test_ordered_array_set_complement1(){
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 3, 5}, 3);
    ordered_array_set setUniverse = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set, setUniverse);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set);
    ordered_array_set_delete(setUniverse);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_complement2(){
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set setUniverse = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set, setUniverse);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set);
    ordered_array_set_delete(setUniverse);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_complement3(){
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0}, 0);
    ordered_array_set setUniverse = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set, setUniverse);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    assert (ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set);
    ordered_array_set_delete(setUniverse);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}

void test_ordered_array_set_complement(){
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
    test_ordered_array_set_complement3();
}

void test_ordered_array_set(){
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}