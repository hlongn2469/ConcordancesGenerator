// Word.cpp
// @Author: Kray Nguyen
// 1/22/2021
// Class that stores instances of keyword, left and right context information

#include "Word.h"
#include <string>

using namespace std;

// @param {string} left - left words of context
// @param {string} right - right words of context
// @param {string} key - keyword
// @pre: left, right, key are all valid
// @post: left,right, key are set within Word class
// @return: none
// @function called: none
Word::Word(string left, string right, string key){
    left_context = left;
    right_context = right;
    this -> key = key;
}

// getter
// @return: left_context 
// @function called: none
string Word:: getLeftWord() const {
    return left_context;
}

// getter
// @return: right_context 
// @function called: none
string Word:: getRightWord() const {
    return right_context;
}

// getter
// @return: key
// @function called: none
string Word:: getKey() const {
    return key;
}

