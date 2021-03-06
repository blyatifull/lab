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
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char* findSpace_(char *begin){
    while (*begin != '\0' && (isspace(*begin) || *begin == ',')){
        begin++;
    }
    return begin;
}

char* findNonSpaceReverse_(char *rbegin, const char *rend){
    while (rbegin != rend && !isspace(*rbegin)){
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse_(char *rbegin, const char *rend){
    while (rbegin != rend && isspace(*rbegin)){
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
    return beginSource + (endSource - beginSource);
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

int wordcmp(WordDescriptor w1, WordDescriptor w2) {
    while ((w1).begin != (w1).end && (w2).begin != (w2).end && *(w1).begin == *(w2).begin) {
        (w1).begin++;
        (w2).begin++;
    }

    if ((w1).begin == (w1).end && (w2).begin == (w2).end) {
        return 0;
    } else if ((w1).begin == (w1).end && (w2).begin != (w2).end) {
        return -(*(w2).begin);
    } else if ((w1).begin != (w1).end && (w2).begin == (w2).end) {
        return *(w1).begin;
    } else {
        return *(w1).begin - *(w2).begin;
    }
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

int getCountWords(char *s){
    WordDescriptor w;
    int wordsCounter = 0;
    while (getWord(s, &w)){
        wordsCounter++;

        s = (w).end;
    }

    return wordsCounter;
}

void inputArrayOfWords(char *s, BagOfWords *words){
    (words)->size = 0;
    WordDescriptor word;
    while (getWord(s, &word)){
        (words)->words[(words)->size] = word;
        s = word.end;

        (words)->size++;
    }
}

/********************************************* TASK 1 *************************************************/

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
        } else {
            *s = *begin;
            s++;
            begin++;
        }
    }

    *s = '\0';
}

/********************************************* TASK 3 *************************************************/

char _stringBuffer[1000];

int getWord (char *beginSearch, WordDescriptor *word){
    (word)->begin = findNonSpace_(beginSearch);
    if (*(word)->begin == '\0')
        return 0;

    (word)->end = findSpace_(word->begin);

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
            while (temp) {
                *s = ' ';

                temp--;
            }
        } else {
            *s = *startStringBuffer;
            s++;
            startStringBuffer++;
        }
    }

    *s = '\0';
}

/********************************************* TASK 5 *************************************************/

void replace (char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *startStringBuffer;
    if (w1Size >= w2Size)
        startStringBuffer = source;
    else {
        copy(source, getEndOfString(source), _stringBuffer);
        startStringBuffer = source;
    }

    WordDescriptor readWord;
    while (getWord(source, &readWord)) {
        if (isWordsEqual(word1, readWord) != 0)
            startStringBuffer = copy((word2).begin, (word2).end, startStringBuffer);
        else
            startStringBuffer = copy((readWord).begin, (readWord).end, startStringBuffer);

        *startStringBuffer++ = ' ';
        source = readWord.end;
    }

    *startStringBuffer = '\0';
}

/********************************************* TASK 6 *************************************************/

bool isSortedByLexicographicDictionary (char *s){
    WordDescriptor w1;
    if (!getWord(s, &w1))
        return true;

    WordDescriptor w2 = w1;
    char *begin = (w2).end;
    while (getWord(begin, &w1)){
        if (strcmp_((w1).begin, (w2).begin) > 0)
            return false;

        w2 = w1;
        begin = w2.end;
    }
    return true;
}


/********************************************* TASK 7 *************************************************/

void printWordsRevers(char *s){
    BagOfWords w;
    inputArrayOfWords(s, &w);

    char *temp = s;
    for (size_t i = (w).size - 1; i > 0; i--) {
        temp = copy((w).words[i].begin, (w).words[i].end, temp);
        *temp = '\0';

        printf("%s", temp);
    }
}

/********************************************* TASK 8 *************************************************/


bool isPoly(WordDescriptor w){
    while ((w).end != (w).begin)
        if (*(w).end - 1 != *(w).begin) {
            return false;
        }
    (w).end--; (w).begin++;

    return true;
}

int getCountPoly(char *s){
    WordDescriptor w;
    int polyCounter = 0;
    while (getWord(s, &w)){
        polyCounter += isPoly(w);

        s = (w).end + 1;
    }

    return polyCounter;
}

/********************************************* TASK 9 *************************************************/

char* getAlternatingWordsInString(char *s1, char *s2){
    char *buffer;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)), (isW2Found = getWord(beginSearch2, &word2)), isW1Found || isW2Found) {
        if (isW1Found){
            buffer = copy((word1).begin, (word1).end, buffer);
            *buffer = ' ';
            buffer++;

            beginSearch1 = (word1).end;
        }

        if (isW2Found){
            buffer = copy((word2).begin, (word2).end, buffer);
            *buffer = ' ';
            buffer++;

            beginSearch2 = (word2).end;
        }
    }

    *buffer = '\0';

    return buffer;
}

/********************************************* TASK 10 *************************************************/

char* reverseString (char *s){
    copy(s, getEndOfString(s), _stringBuffer);

    BagOfWords words;
    inputArrayOfWords(_stringBuffer, &words);

    char *result = s;
    while ((words).size--) {
        result = copy((words).words[(words).size].begin, (words).words[(words).size].end, result);
        *result = ' ';
        result++;
    }

    *(result - 1)= '\0';

    return result;
}

/********************************************* TASK 11 *************************************************/

char* findSymbolA (char *begin, const char *end){
    while (begin != end && *begin != 'a' && *begin != 'A')
        begin++;

    return begin;
}

void printWordBeforeFirstWordWithA (char *s){
    if (getCountWords(s) == 0){
        printf(EMPTY_STRING);
    }

    char *end = getEndOfString(s);
    if (findSymbolA(s, end) == end) {
        printf(NOT_FOUND_A_WORD_WITH_A);
    }

    WordDescriptor backWord;
    getWord(s, &backWord);
    char *nextWord = findSymbolA((backWord).begin, (backWord).end);
    if (*nextWord != 'a' && *nextWord != 'A')
        printf(FIRST_WORD_WITH_A);

    s = (backWord).end;
    WordDescriptor readWord;
    while (getWord(s, &readWord)){
        nextWord = findSymbolA((readWord).begin, (readWord).end);
        if (*nextWord == 'a' || *nextWord == 'A'){
            char *result = s;
            copy((readWord).begin, (readWord).end, result);
            printf("%s", result);
        }

        backWord = readWord;

        s = (readWord).end;
    }
}

/********************************************* TASK 12 *************************************************/

bool isWordsEqual (WordDescriptor w1, WordDescriptor w2){
    if(strcmp_((w1).begin, (w2).begin) == 0)
        return true;
    return false;
}

WordDescriptor getLastWordFirstStringThatIsInSecondString (char *s1, char *s2){
    BagOfWords fwords, swords;
    inputArrayOfWords(s1, &fwords);
    inputArrayOfWords(s2, &swords);

    WordDescriptor result;
    for (int i = 0; i < (fwords).size; ++i) {
        for (int j = 0; j < (swords).size; ++j) {
            if (isWordsEqual((fwords).words[i], (swords).words[j])) {
                result = ((fwords).words[i]);
            }
        }
    }
    return result;
}

/********************************************* TASK 13 *************************************************/

bool isSameWords (char *s){
    BagOfWords words;
    inputArrayOfWords(s, &words);

    for (int i = 0; i < (words).size; ++i) {
        for (int j = 0; j < (words).size; ++j) {
            if (i != j && isWordsEqual(((words).words[i]), (words).words[j])) {
                return true;
            }
        }
    }

    return false;
}

/********************************************* TASK 14 *************************************************/

bool task14 (char *s) {
    copy(s, getEndOfString(s), _stringBuffer);

    BagOfWords words;
    inputArrayOfWords(_stringBuffer, &words);

    for (int i = 0; i < (words).size; ++i) {
        qsort((words).words[i].begin, strlen_((words).words[i].begin), sizeof(BagOfWords), wordcmp);
    }

    for (int i = 0; i < (words).size; ++i) {
        for (int j = i + 1; j < (words).size; ++j) {
            if (isWordsEqual((words).words[i], (words).words[j]))
                return true;
        }
    }

    return false;
}

/********************************************* TASK 15 *************************************************/

void* removeAllWordsSimilarToTheLastWord(char *s){
    copy(s, getEndOfString(s), _stringBuffer);
    BagOfWords words;
    inputArrayOfWords(_stringBuffer, &words);
    char *result = s;
    for (int i = 0; i < (words).size - 1; ++i) {
        if (!isWordsEqual((words).words[i], (words).words[(words).size - 1]))
            copy((words).words[i].begin, (words).words[i].end - 1, result);

        *result = ' ';
        result++;
    }

    *result = '\0';

    return result;
}

/********************************************* TASK 16 *************************************************/

WordDescriptor getLastWordFirstStringThatIsInSecondString_ (char *s1, char *s2){
    BagOfWords fwords, swords;
    inputArrayOfWords(s1, &fwords);
    inputArrayOfWords(s2, &swords);

    WordDescriptor result;
    for (int i = 0; i < (fwords).size; ++i) {
        for (int j = 0; j < (swords).size; ++j) {
            if (isWordsEqual((fwords).words[i], (swords).words[j])) {
                result = (fwords).words[i];
            }
        }
    }
    return result;
}

/********************************************* TASK 17 *************************************************/

void deleteAllPolyWords(char *s){
    BagOfWords words;
    inputArrayOfWords(s, &words);

    char *buffer = s;
    for (int i = 0; i < (words).size; ++i) {
        if (!isPoly((words).words[i])) {
            copy((words).words[i].begin, (words).words[i].end, buffer);
            buffer++;
        }
    }
    *buffer = '\0';

    copy(buffer, getEndOfString(buffer), s);
}

/********************************************* TASK 18 *************************************************/

char* task18 (char *s1, char *s2){
    BagOfWords w1, w2;
    inputArrayOfWords(s1, &w1);
    inputArrayOfWords(s2, &w2);

    char *result = s1;
    if ((w1).size < (w2).size) {
        copy(s1, getEndOfString(s1), result);
        for (size_t i = (w1).size; i < (w2).size; ++i) {
            copy((w2).words[i].begin, (w2).words[i].end - 1, result);

            *result = '0';
            result++;
        }
    } else {
        copy(s2, getEndOfString(s2), result);
        for (size_t i = (w2).size; i < (w1).size; ++i) {
            copy((w1).words[i].begin, (w1).words[i].end - 1, result);

            *result = '0';
            result++;
        }
    }

    *result = '\0';

    return result;
}

/********************************************* TASK 19 *************************************************/

bool isAllSymbolsInString (char *s1, const char *s2){
    while (*s2 != '\0'){
        char *end = getEndOfString(s1);
        if (*find_(s1, end, *s2) == *end)
            return false;
    }
    return true;
}