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
        if (isspace(*begin) && *begin == ',')
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

int strcmp_(const char *lhs, const char *rhs){
    if (*lhs != '\0' && *rhs != '\0' && *rhs == *lhs)
        return strcmp_(++lhs, ++rhs);
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

char _stringBuffer[1000];

int getWord (char *beginSearch, WordDescriptor *word){
    (word)->begin = findNonSpace_(beginSearch);
    if (*(word)->begin == '\0')
        return 0;

    (word)->end = findSpace_(word->begin );

    return 1;
}

void digitToStart (WordDescriptor word){
    char *endStringBuff = copy((word).begin, (word).end, _stringBuffer);

    char *recPosition = copyIf(endStringBuff, _stringBuffer, (word).end, isalpha);

    copyIf(_stringBuffer, endStringBuff, recPosition, isdigit);
}

int getWordReverse(char *rbeginSearch, const char *rend, WordDescriptor *word) {
    (word)->end = findNonSpaceReverse_(rbeginSearch, rend);
    if((word)->end == rend) {
        return 0;
    }

    (word)->begin = findNonSpaceReverse_((word)->end, rend);

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

/********************************************* TASK 5 *************************************************/

void replace (char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size){
        readPtr = source;
        recPtr = source;
        } else {
        copy (source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }



}

/********************************************* TASK 6 *************************************************/

bool isSortedByLexicographicDictionary (char *s){
    WordDescriptor w1;
    if (!getWord(s, &w1))
        return true;

    s = (w1).end;

    WordDescriptor w2;

    while (1){

    }
}


/********************************************* TASK 7 *************************************************/

/********************************************* TASK 8 *************************************************/


bool isPoly(WordDescriptor w){
    if (((w).end - (w).begin) % 2)
        return false;

    while ((w).end != (w).begin)
        if (*(w).end++ != *(w).begin++)
            return false;

    return true;
}

int getCountPoly(char *s){
    WordDescriptor w;
    int polyCounter = 0;
    while (getWord(s, &w)){
        polyCounter += isPoly(w);

        s = (w).end;
    }

    return polyCounter;
}

