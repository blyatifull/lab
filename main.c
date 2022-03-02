#include "libs/data_structures/string_/string_.h"
#include "libs/algorithms/array/array.h"
#include <math.h>
#include <assert.h>

int main() {
    char s[] = "111222";
    removeAdjacentEqualLetters(s);

    assert(*s == "12");

    return 0;
}
