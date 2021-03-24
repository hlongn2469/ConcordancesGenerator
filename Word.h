// Word.h
// @Author: Kray Nguyen
// 1/22/2021
// Class that stores instances of keyword, left and right context information

#include <string>
#include <iostream>

using namespace std;

class Word{

    // @param {ostream} the_stream - used for printing purposes
    // @param {Word} other - The targeted word to print
    // @pre: Word other is valid
    // @post: KWIC printed to console
    // @return: ostream the_stream
    // @function called: none
    friend ostream& operator<<(ostream &the_stream,const Word &other){
        the_stream.width(45); the_stream << right << other.left_context << " { " 
        << other.key << " } " << other.right_context << endl;
        
        return the_stream;
    }

public:

    // @param {string} left - left words of context
    // @param {string} right - right words of context
    // @param {string} key - keyword
    // @pre: left, right, key are all valid
    // @post: left,right, key are set within Word class
    // @return: none
    // @function called: none
    Word(string left, string right, string key);
    
    // getter
    // @return: left_context 
    // @function called: none
    string getLeftWord() const;

    // getter
    // @return: right_context 
    // @function called: none
    string getRightWord() const;

    // getter
    // @return: key
    // @function called: none
    string getKey() const;

private:
    string left_context, right_context, key;
};

