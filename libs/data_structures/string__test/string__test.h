#ifndef COURSE_STRING__TEST_H
#define COURSE_STRING__TEST_H

#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/string_/string_.h"

#include <assert.h>

void test_strlen_stringEmpty() {
    char *s = "";

    assert(strlen_(s) == 0);
}

void test_strlen_stringWithoutSpace() {
    char *s = "horoshayalaba";

    assert(strlen_(s) == 13);
}

void test_strlen_stringWithSpace() {
    char *s = "Hello world!";

    assert(strlen_(s) == 12);

}

void test_strlen() {
    test_strlen_stringEmpty();
    test_strlen_stringWithoutSpace();
    test_strlen_stringWithSpace();
}

#include <stdio.h>

void test_find_stringNoElement() {
    char *s = "blyatifull";

    assert(*(find_(s, &s[strlen_(s)], 'w')) == '\0');
}

void test_find_stringIsElement() {
    char *s = "blyatifull";

    assert(*(find_(s, "\0", 'f')) == 'f');
}

void test_find() {
    test_find_stringNoElement();
    test_find_stringIsElement();
}

void test_findNonSpace_stringEmpty() {
    char *s = "";

    assert(*(findNonSpace_(s)) == '\0');
}

void test_findNonSpace_stringSpace() {
    char *s = " ";

    assert(*(findNonSpace_(s)) == '\0');
}

void test_findNonSpace_stringWithoutSpace() {
    char *s = "blyatifull";

    assert(*(findNonSpace_(s)) == 'b');
}

void test_findNonSpace_stringWithSpace() {
    char *s = "\t \n \r \t \r w";

    assert(*(findNonSpace_(s)) == 'w');
}

void test_findNonSpace() {
    test_findNonSpace_stringEmpty();
    test_findNonSpace_stringSpace();
    test_findNonSpace_stringWithoutSpace();
    test_findNonSpace_stringWithSpace();
}

void test_findSpace_stringEmpty() {
    char *s = "";

    assert(*(findSpace_(s)) == '\0');
}

void test_findSpace_stringWithoutSpace() {
    char *s = "space";

    assert(*(findSpace_(s)) == '\0');
}

void test_findSpace_stringWithSpace() {
    char *s = "space space";

    assert(*(findSpace_(s)) == *(s + 6));
}

void test_findSpace() {
    test_findSpace_stringEmpty();
    test_findSpace_stringWithoutSpace();
    test_findSpace_stringWithSpace();
}

void test_findNonSpaceReverse_stringEmpty() {
    char *s = "";

    assert(*(findNonSpaceReverse_(s, s - 1)) == '\0');
}

void test_findNonSpaceReverse_stringWithoutSpace() {
    char *s = "blyatifull";

    assert(*(findNonSpaceReverse_(s + 10, s - 1)) == 'l');
}

void test_findNonSpaceReverse_stringWithSpace() {
    char *s = " \t \t b ti full\t \r \t";

    assert(*(findNonSpaceReverse_(s + 19, s - 1)) == 'l');
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_stringEmpty();
    test_findNonSpaceReverse_stringWithoutSpace();
    test_findNonSpaceReverse_stringWithSpace();
}

void test_findSpaceReverse_stringSpace() {
    char *s = "";

    assert(*(findSpaceReverse_(s, s - 1)) == '\0');
}

void test_findSpaceReverse_stringWithoutSpace() {
    char *s = "helloHi";

    assert(*(findSpaceReverse_(s + 7, s - 1)) == *(s - 1));
}

void test_findSpaceReverse_stringWithSpace() {
    char *s = " \t \t ho ho ho ho\t \r \t";

    assert(*(findSpaceReverse_(s + 21, s - 1)) == '\t');
}

void test_findSpaceReverse() {
    test_findSpaceReverse_stringSpace();
    test_findSpaceReverse_stringWithoutSpace();
    test_findSpaceReverse_stringWithSpace();
}

void test_strcmp_stringEqual() {
    char *s1 = "borat";
    char *s2 = "borat";

    assert(strcmp_(s1, s2) == 0);
}

void test_strcmp_stringNonEqual_firstGreaterSecond() {
    char *s1 = "red";
    char *s2 = "blue";

    assert(strcmp_(s1, s2) == 'r' - 'b');
}

void test_strcmp_stringNonEqual_secondGreaterFirst() {
    char *s1 = "hto";
    char *s2 = "Ya";

    assert(strcmp_(s1, s2) == 'h' - 'Y');
}

void test_strcmp() {
    test_strcmp_stringEqual();
    test_strcmp_stringNonEqual_firstGreaterSecond();
    test_strcmp_stringNonEqual_secondGreaterFirst();
}

void test_copy_fullString() {
    char s1[MAX_STRING_SIZE] = "blyatifull";
    char s2[MAX_STRING_SIZE] = " ";

    char *dst = copy(s1, s1 + 10, s2);

    char expectation[MAX_STRING_SIZE] = "blyatifull";

    assert(strcmp_(s2, expectation) == 0 && dst == &s2[strlen_(s2)]);
}

void test_copy_partString() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = " pico";

    char *dst = copy(s1 + 4, s1 + 8, s2);

    char
            expectation[MAX_STRING_SIZE] = "pikapico";

    assert(strcmp_(s2, expectation) == 0 && dst == &s2[strlen_(s2) - 4]);
}

void test_copy() {
    test_copy_fullString();
    test_copy_partString();
}

void test_copyIf_digit() {
    char s1[MAX_STRING_SIZE] = "k2r8p1k3";
    char s2[MAX_STRING_SIZE] = " pico";

    char *dst = copyIf(s1 + 4, s1 + 8, s2, isdigit);

    char expectation[MAX_STRING_SIZE] = "13pico";

    assert(strcmp_(s2, expectation) == 0 && dst == &s2[strlen_(s2) - 4]);
}

void test_copyIf() {
    test_copyIf_digit();
}

void test_copyIfReverse_digit() {
    char s1[MAX_STRING_SIZE] = "k2r8p1k3";
    char s2[MAX_STRING_SIZE] = " pico";

    char *dst = copyIfReverse(s1 + 8, s1, s2, isdigit);

    char expectation[MAX_STRING_SIZE] = "3182pico";

    assert(strcmp_(s2, expectation) == 0 && dst == &s2[strlen_(s2) - 4]);
}

void test_copyIfReverse() {
    test_copyIfReverse_digit();
}

void test_functions() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

void test_removeNonLetters_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters_withoutSpace() {
    char s[MAX_STRING_SIZE] = "blyatifull";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "blyatifull";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters_allSpaceSymbols() {
    char s[MAX_STRING_SIZE] = "\t \n \n \t";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters_withSpace() {
    char s[MAX_STRING_SIZE] = "b y\ta t i f\r\tu l";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "blyatifull";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters() {
    test_removeNonLetters_emptyString();
    test_removeNonLetters_withoutSpace();
    test_removeNonLetters_allSpaceSymbols();
    test_removeNonLetters_withSpace();
}


void test_removeExtraSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeExtraSpaces_allSpaces() {
    char s[MAX_STRING_SIZE] = " ";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " ";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeExtraSpaces_stringWithoutSpaces() {
    char s[MAX_STRING_SIZE] = "blyatifull";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "blyatifull";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeExtraSpaces_stringWithSpaces() {
    char s[MAX_STRING_SIZE] = " b l y at if ul l";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " b l y at if ul l";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_allSpaces();
    test_removeExtraSpaces_stringWithoutSpaces();
    test_removeExtraSpaces_stringWithSpaces();
}

void test_replace_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    char w1[MAX_STRING_SIZE] = "blyatifull";
    char w2[MAX_STRING_SIZE] = "emo boy";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_replace_w1MoreW2() {
    char s[MAX_STRING_SIZE] = "blyatifull";
    char w1[MAX_STRING_SIZE] = "ll";
    char w2[MAX_STRING_SIZE] = "l";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "blyatifu l";

    assert(strcmp_(s, expectation) == 0);
}

void test_replace_w1EqualsW2() {
    char s[MAX_STRING_SIZE] = "blyatifu ll";
    char w1[MAX_STRING_SIZE] = "ll";
    char w2[MAX_STRING_SIZE] = "fu";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "blyatifu fu";

    assert(strcmp_(s, expectation) == 0);
}

void test_replace_w1LessW2() {
    char s[MAX_STRING_SIZE] = "bly atif ull";
    char w1[MAX_STRING_SIZE] = "a";
    char w2[MAX_STRING_SIZE] = "ded";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "bly a atif ded ull";

    assert(strcmp_(s, expectation) == 0);
}

void test_replace() {
    test_replace_emptyString();
    test_replace_w1MoreW2();
    test_replace_w1EqualsW2();
    test_replace_w1LessW2();
}


void test_areWordsOfStringLexicographicallyOrdered_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(isSortedByLexicographicDictionary(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_twoWordsEquals() {
    char s[MAX_STRING_SIZE] = "blyatifull blyatifull";

    assert(isSortedByLexicographicDictionary(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_w1LessW2() {
    char s[MAX_STRING_SIZE] = "blyatifull blyatifull";

    assert(isSortedByLexicographicDictionary(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_w1MoreW2() {
    char s[MAX_STRING_SIZE] = "blyatifull blyatiful";

    assert(isSortedByLexicographicDictionary(s) == false);
}

void test_areWordsOfStringLexicographicallyOrdered() {
    test_areWordsOfStringLexicographicallyOrdered_emptyString();
    test_areWordsOfStringLexicographicallyOrdered_twoWordsEquals();
    test_areWordsOfStringLexicographicallyOrdered_w1LessW2();
    test_areWordsOfStringLexicographicallyOrdered_w1MoreW2();
}

void test_getCountPoly_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(getCountPoly(s) == 0);
}

void test_getCountPoly_nonPalindrome() {
    char s[MAX_STRING_SIZE] = "blyatifull emo boy";

    assert(getCountPoly(s) == 0);
}

void test_getCountPoly_onePalindrome() {
    char s[MAX_STRING_SIZE] = "BESSEB";

    assert(getCountPoly(s) == 1);
}

void test_getCountPoly_allPalindrome() {
    char s[MAX_STRING_SIZE] = "blyatifullllufiraylb emoome";

    assert(getCountPoly(s) == 2);
}

void test_getCountOfWordsPalindromes() {
    test_getCountPoly_emptyString();
    test_getCountPoly_nonPalindrome();
    test_getCountPoly_onePalindrome();
    test_getCountPoly_allPalindrome();
}

void test_reverseString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseString_oneWord() {
    char s[MAX_STRING_SIZE] = "blyatifull";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "blyatifull";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseString_twoWord() {
    char s[MAX_STRING_SIZE] = "blyatifull blyatifu";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "blyatifu blyatifull";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseString_fewWord() {
    char s[MAX_STRING_SIZE] = "blyatifull blyatifu blyati";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "blyati blyatifu blyatifull";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseWordsOfString() {
    test_reverseString_emptyString();
    test_reverseString_oneWord();
    test_reverseString_twoWord();
    test_reverseString_fewWord();
}


#endif //COURSE_STRING__TEST_H
