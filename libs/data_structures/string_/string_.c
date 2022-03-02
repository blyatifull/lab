#include "string_.h"

size_t strlen_ (const char *begin){
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find_(char *begin, char *end, int ch){
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char* findNonSpace_(char *begin){
    while (*begin != '\0') {
        if (!isspace(*begin))
            return begin;
        begin++;
    }
    return begin;
}

char* findSpace_(char *begin){
    while (*begin != '\0'){
        if (isspace(*begin))
            return begin;
        begin++;
    }
    return begin;
}

char* findNonSpaceReverse_(char *rbegin, const char *rend){
    while (rbegin != rend){
        if (!isspace(*rbegin))
            return rbegin;
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse_(char *rbegin, const char *rend){
    while (rbegin != rend){
        if (isspace(*rbegin))
            return rbegin;
        rbegin--;
    }
    return rbegin;
}

int strcmp(const char *lhs, const char *rhs){
    if (*lhs != '\0' && *rhs != '\0' && *rhs == *lhs)
        return strcmp(++lhs, ++rhs);
    return *rhs - *lhs;
}

char* copy(char *beginSource, const char *endSource, char *beginDestination){
    memcpy(beginSource, beginDestination, endSource - beginSource);
    return beginSource + (endSource - beginSource) + 1;
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)){
    while (beginSource != endSource){
        if (f(*beginSource)) {
            *beginDestination = *beginSource;

            beginDestination++;
        }

        beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){
    while (rendSource != rbeginSource){
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;

            beginDestination++;
        }

        rbeginSource--;
    }

    return beginDestination;
}

/********************************************* TASK 1 *************************************************/

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf (s, endSource, s, isgraph);
    *destination = '\0';
}

/********************************************* TASK 2 *************************************************/

void removeExtraSpaces(char *s) {
    char *begin = s + 1;
    s++;
    while (*s != '\0') {
        if (isspace(*begin) && isspace(*(s - 1))) {
            begin++;
            continue;
        }
        *s = *begin;
        s++;
        begin++;
    }

    *s = '\0';
}

/********************************************* TASK 3 *************************************************/

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin ;           // позиция начала слова
    char *end ;             // позиция первого символа, после последнего символа слова
} WordDescriptor;

int getWord (char *beginSearch, WordDescriptor *word){
    word->begin = findNonSpace_(beginSearch);
    if (*word -> begin == '\0')
        return 0;

    word->end = findSpace_(word -> begin );

    return 1;
}

void digitToStart (WordDescriptor word){
    char *endStringBuff = copy(word.begin, word.end, _stringBuffer);

    char *recPosition = copyIf(endStringBuff, _stringBuffer, word.end, isalpha);

    copyIf(_stringBuffer, endStringBuff, recPosition, isdigit);
}

int getWordReverse (char *rbeginSearch, const char *rend, WordDescriptor *word){
    word->begin = findNonSpaceReverse_(rbeginSearch, rend);
    if (*word->begin != *rend)
        return 0;

    word->end = findNonSpaceReverse_(word->begin, rend);

    return 1;
}


/********************************************* TASK 4 *************************************************/

void replaceNumberWithSpaces(char *s){
    char *getEndS = getEndOfString(s);
    char *startStringBuffer = _stringBuffer;
    char *stringBuffer = copy(s, getEndS, _stringBuffer);
    *stringBuffer = '\0';

    while (*startStringBuffer != '\0'){
        if (isdigit(*startStringBuffer)){
            int temp = *startStringBuffer - 48;
            while (temp--) {
                *s = ' ';
                s++;
            }
            continue;
        }

        *s = *startStringBuffer;
        s++;
        startStringBuffer++;
    }

    *s = '\0';
}


