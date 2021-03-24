// KeywordManager.h
// @Author: Kray Nguyen
// 1/22/2021
// Class that facilitates words from files and store words and KWIC
// into appropriate LinkedList or/and Binary Search Tree

#include "Bst.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

class KeywordManager{
public:
    ~KeywordManager();

    // @param {ifstream} fileName - file name of stopwords
    // @pre: KeywordManager object is created
    // @post: all stopwords from file are stored in stopword vector
    // @return: none
    // @function called: getline(), check(), push_back()
    void processStopWord(ifstream& fileName);

    // @param {ifstream} corpusFile - file name of corpus
    // @pre: KeywordManager object is created
    // @post: all words from corpus file are stored in corpus vector
    // @return: none
    // @function called: push_back()
    void storeCorpus(ifstream& fileName);

    // @param {ifstream} fileName - file name of corpus
    // @pre: KeywordManager object is created
    // @post: if file name not found in directory, end program.
    // if found, collect words into corpus vector, then insert each 
    // keyword into BST and LList
    // @return: none
    // @function called: cleanPunc(), isWord(), isNotStopWord(), findLeft()
    // findRight(), Insert(), insert(), retrieve()
    void processCorpus();

    // @pre: KeywordManager object is created
    // @post: Print out BST inorder
    // @return: none
    // @function called: none
    void report();

private:
    Bst wordCollections;
    LList* retrieve_value;
    LList* new_value;
    vector <string> stopword;
    vector <string> corpus;
    vector <string> reverse_list;
    string stopword_info;
    string corpus_info;
    string key, left, right;
    int count_index;

    // @param {string} word - word to check leading and trailing punctuation
    // and clean if necessary
    // @pre: KeywordManager object is created, word is not null
    // @post: leading and trailing punctuation are removed from input word 
    // and input word will change, otherwise word stay the same 
    // @return: none
    // @function called: erase(), pop_back()
    void cleanPunc(string &word);

    // @param {vector<string>} list - vector storing reversing list 
    // for adjust left context words output 
    // @param {string} left - left context words
    // @pre: KeywordManager object is created, param is not null
    // @post: the left context words are reversed for correct output 
    // @return: none
    // @function called: size(), push_back(), at(), check(), getline()
    void reverse(vector<string> list, string&left);

    // @param {int} key_index - index of keyword in terms of vector 
    // @param {string} left - left context words
    // @pre: KeywordManager object is created, param is not null
    // @post: collect left context of words to the passed in string
    // @return: none
    // @function called: reverse(), cleanPunc()
    void findLeft(int key_index, string& left);

    // @param {int} key_index - index of keyword in terms of vector 
    // @param {string} right - right context words
    // @pre: KeywordManager object is created, param is not null
    // @post: collect right context of words to the passed in string
    // @return: none
    // @function called: cleanPunc()
    void findRight(int key_index, string &right);

    // @param {string} word - word to check if it's a word
    // @pre: KeywordManager object is created, word is not null
    // @post: none
    // @return: true or false whether string is empty
    // @function called: none
    bool isWord(string word);

    // @param {string} word - word to check if it's a stopword
    // @pre: KeywordManager object is created, word is not null
    // @post: none  
    // @return: true or false whether word is not a stopword
    // @function called: none
    bool isNotStopWord(string word);
};