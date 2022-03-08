#ifndef COURSE_STRING__H
#define COURSE_STRING__H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100

typedef struct WordDescriptor {
    char *begin ;           // позиция начала слова
    char *end ;             // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords{
    WordDescriptor words[1000];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
}WordBeforeFirstWordWithAReturnCode;

int getWordReverse(char *rbeginSearch, const char *rend, WordDescriptor *word);

int getWord (char *beginSearch, WordDescriptor *word);

void digitToStart (WordDescriptor word);

// Возвращает кол-во символов (длину строки) в строке begin,
// не учитывая символ окончания строки
size_t strlen_ (const char *begin);

char* find_(char *begin, char *end, int ch);

// Возвращает адрес на первый не пробельный символ строки begin,
// если символ не найден, то вернёт адрес на первый символ окончания строки
char* findNonSpace_(char *begin);

// Возвращает адрес на первый пробельный символ строки begin,
// если символ не найден, то вернёт адрес на первый символ окончания строки
char* findSpace_(char *begin);

char* findNonSpaceReverse_(char *rbegin, const char *rend);

char* findSpaceReverse_(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char* copy(char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

bool isWordsEqual (WordDescriptor w1, WordDescriptor w2);




#endif //COURSE_STRING__H
