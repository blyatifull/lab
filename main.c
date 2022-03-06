#include "libs/data_structures/string_/string_.h"
#include "libs/algorithms/array/array.h"
#include <math.h>
#include <assert.h>

int main() {
        char s[] = "tualetnyi123 intuzist";
        WordDescriptor word;
        char *beginSearch = s;
        while(getWord(beginSearch, &word)) {
            printf("%c %c", *(word).begin, *(word).end);
            printf("\n");
            digitToStart(word);
            beginSearch = (word).end;
            puts(s);
        }

    return 0;
}
