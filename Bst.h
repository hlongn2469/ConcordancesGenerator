// Bst.h
// @Author: Kray Nguyen
// 1/22/2021
// Binary search tree that stores key-pair value of Word-LList

#include <iostream>
#include <string>
#include "LList.h"
#include <algorithm>

using namespace std;

class Bst {
    friend ostream& operator<<(ostream & the_stream, const Bst& rhs){
        rhs.print(the_stream);
        return the_stream;
    }
public:
    Bst();
    ~Bst();

    // @pre: BST object is created
    // @post: none
    // @return: true or false whether BST is empty
    // @function called: none
    bool isEmpty() const;

    // @pre: BSt object is created
    // @post: all root node are deleted from BST
    // @return: none
    // @function called: flushHelper()
    void flush();

    // @param {Word} the-word - look up key word
    // @param {LList} value - retrieving KWIC value
    // @pre: BSt object is created, param is valid
    // @post: LList value is changed/retrieved
    // @return: true or false whether retrieve sucessfully
    // @function called: retrieveHelper()
    bool retrieve(Word*the_word, LList *& value);

    // @param {Word} the-word - inserted word
    // @param {LList} value - inserted KWIC value
    // @pre: BSt object is created, param is valid
    // @post: the_word and value are inserted into the BSTNode
    // @return: true or false whether insert sucessfully
    // @function called: insertHelper()
    bool insert(Word* the_word, LList* value);

private:
    struct BSTNode{
        Word* node_word;
        LList* value;
        BSTNode* left;
        BSTNode* right;
    };

    string key_current, key_compare;
    BSTNode* root_;

    // @param {BSTNode} current - current root of subtrees 
    // @param {Word} the-word - look up key word
    // @param {LList} value - retrieving KWIC value
    // @pre: BSt object is created, param is valid
    // @post: LList value is changed/retrieved
    // @return: true or false whether retrieve sucessfully
    // @function called: transform(), retrieveHelper()
    bool retrieveHelper(BSTNode* current, Word* the_word, LList *& value);

    //@ param {BSTNode} root - subtree root node
    // @param {Word} the-word - look up key word
    // @param {LList} value - retrieving KWIC value
    // @pre: BSt object is created, param is valid
    // @post: the_word and value are inserted into the BSTNode
    // @return: true or false whether insert sucessfully
    // @function called: insertHelper(), transform()
    bool insertHelper(BSTNode*& root, Word* the_word, LList* value);

    // @param {BSTNode} root - root of tree/subtree
    // @pre: BSt object is created
    // @post: all root node are deleted from BST
    // @return: none
    // @function called: flushHelper()
    void flushHelper(BSTNode* root);

    // @param {ostream} the_stream - for printing purposes
    // @param {BSTNode} root - root node of tree/subtree
    // @pre: BSt object is created, ostream is valid
    // @post: Print tree alphabetically by keyword
    // @return: none
    // @function called: printHelper()
    void printHelper(ostream & the_stream, BSTNode* root) const;

    // @param {ostream} the_stream - for printing purposes
    // @pre: BSt object is created, ostream is valid
    // @post: Print tree alphabetically by keyword
    // @return: none
    // @function called: printHelper()
    void print(ostream & the_stream) const;
};