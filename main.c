#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(15);
    reserve(&v, 11);

    printf("%d", (v).size);

    return 0;
}
