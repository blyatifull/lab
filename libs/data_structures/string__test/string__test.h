#ifndef COURSE_STRING__TEST_H
#define COURSE_STRING__TEST_H

#include "C:/Users/blyatifull/CLionProjects/course/libs/data_structures/string_/string_.h"

void test_removeNonLetters_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters_withoutSpace() {
    char s[MAX_STRING_SIZE] = "kurapika";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters_allSpaceSymbols() {
    char s[MAX_STRING_SIZE] = "\t \n \n \t";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeNonLetters_withSpace() {
    char s[MAX_STRING_SIZE] = "k u\tr a p i\r\tk a";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

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
    char s[MAX_STRING_SIZE] = "kurapika";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeExtraSpaces_stringWithSpaces() {
    char s[MAX_STRING_SIZE] = " k ura pi k a ";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " k ura pi k a ";

    assert(strcmp_(s, expectation) == 0);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_allSpaces();
    test_removeExtraSpaces_stringWithoutSpaces();
    test_removeExtraSpaces_stringWithSpaces();
}

//void test_replace_emptyString() {
//    char s[MAX_STRING_SIZE] = "";
//    char w1[MAX_STRING_SIZE] = "kurapika";
//    char w2[MAX_STRING_SIZE] = "emo boy";
//
//    replace(s, w1, w2);
//
//    char expectation[MAX_STRING_SIZE] = "";
//
//    assert(strcmp_(s, expectation) == 0);
//}
//
//void test_replace_w1MoreW2() {
//    char s[MAX_STRING_SIZE] = "kurapi ka";
//    char w1[MAX_STRING_SIZE] = "ka";
//    char w2[MAX_STRING_SIZE] = "a";
//
//    replace(s, w1, w2);
//
//    char expectation[MAX_STRING_SIZE] = "kurapi a ";
//
//    assert(strcmp_(s, expectation) == 0);
//}
//
//void test_replace_w1EqualsW2() {
//    char s[MAX_STRING_SIZE] = "kurapi ka";
//    char w1[MAX_STRING_SIZE] = "ka";
//    char w2[MAX_STRING_SIZE] = "pa";
//
//    replace(s, w1, w2);
//
//    char expectation[MAX_STRING_SIZE] = "kurapi pa";
//
//    assert(strcmp_(s, expectation) == 0);
//}
//
//void test_replace_w1LessW2() {
//    char s[MAX_STRING_SIZE] = "kur a pik a";
//    char w1[MAX_STRING_SIZE] = "a";
//    char w2[MAX_STRING_SIZE] = "pico";
//
//    replace(s, w1, w2);
//
//    char expectation[MAX_STRING_SIZE] = "kur pico pik pico";
//
//    assert(strcmp_(s, expectation) == 0);
//}
//
//void test_replace() {
//    test_replace_emptyString();
//    test_replace_w1MoreW2();
//    test_replace_w1EqualsW2();
//    test_replace_w1LessW2();
//}


void test_areWordsOfStringLexicographicallyOrdered_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(isSortedByLexicographicDictionary(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_twoWordsEquals() {
    char s[MAX_STRING_SIZE] = "kurapika kurapika";

    assert(isSortedByLexicographicDictionary(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_w1LessW2() {
    char s[MAX_STRING_SIZE] = "kurapik kurapika";

    assert(isSortedByLexicographicDictionary(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_w1MoreW2() {
    char s[MAX_STRING_SIZE] = "kurapika kurapik";

    assert(isSortedByLexicographicDictionary(s) == false);
}

void test_areWordsOfStringLexicographicallyOrdered() {
    test_areWordsOfStringLexicographicallyOrdered_emptyString();
    test_areWordsOfStringLexicographicallyOrdered_twoWordsEquals();
    test_areWordsOfStringLexicographicallyOrdered_w1LessW2();
    test_areWordsOfStringLexicographicallyOrdered_w1MoreW2();
}


//void test_printWordsOfStringReverse() {
//    char s[MAX_STRING_SIZE] = "kurapik kurapika kur";
//
//    printWordsOfStringReverse(s);
//}
//

void test_getCountPoly_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(getCountPoly(s) == 0);
}

void test_getCountPoly_nonPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapik,BES,BOY";

    assert(getCountPoly(s) == 0);
}

void test_getCountPoly_onePalindrome() {
    char s[MAX_STRING_SIZE] = "BESSEB BOY";

    assert(getCountPoly(s) == 1);
}

void test_getCountPoly_allPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapikakiparuk BESTSEB BOYOB";

    assert(getCountPoly(s) == 3);
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
    char s[MAX_STRING_SIZE] = "kurapika";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseString_twoWord() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "kuruta kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseString_fewWord() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta zharik";

    reverseString(s);

    char expectation[MAX_STRING_SIZE] = "zharik kuruta kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_reverseWordsOfString() {
    test_reverseString_emptyString();
    test_reverseString_oneWord();
    test_reverseString_twoWord();
    test_reverseString_fewWord();
}


#endif //COURSE_STRING__TEST_H
