// Bst.cpp
// @Author: Kray Nguyen
// 1/22/2021
// Binary search tree that stores key-pair value of Word-LList

#include "Bst.h"
#include <string>
#include <iostream>

using namespace std;

Bst::Bst() {
    root_ = nullptr;
}

Bst::~Bst() {
    flush();
}

// @pre: BST object is created
// @post: none
// @return: true or false whether BST is empty
// @function called: none
bool Bst::isEmpty()const{
    return root_ == nullptr;
}

// @pre: BSt object is created
// @post: all root node are deleted from BST
// @return: none
// @function called: flushHelper()
void Bst::flush(){
    if(root_ != nullptr){
        flushHelper(root_);
    }
    root_ = nullptr;
}

// @param {BSTNode} root - root of tree/subtree
// @pre: BSt object is created
// @post: all root node are deleted from BST
// @return: none
// @function called: flushHelper()
void Bst::flushHelper(BSTNode* root){
    if(root != nullptr){
        flushHelper(root -> left);
        flushHelper(root -> right);
        root->value->DeleteList();
        delete root;
    }
}

// @param {Word} the-word - look up key word
// @param {LList} value - retrieving KWIC value
// @pre: BSt object is created, param is valid
// @post: LList value is changed/retrieved
// @return: true or false whether retrieve sucessfully
// @function called: retrieveHelper()
bool Bst::retrieve(Word*the_word, LList *& value){
    return retrieveHelper(root_, the_word, value);
}

// @param {BSTNode} current - current root of subtrees 
// @param {Word} the-word - look up key word
// @param {LList} value - retrieving KWIC value
// @pre: BSt object is created, param is valid
// @post: LList value is changed/retrieved
// @return: true or false whether retrieve sucessfully
// @function called: transform(), retrieveHelper()
bool Bst::retrieveHelper(BSTNode* current, Word* the_word, LList *& value){
    // base case 
    if(current == nullptr){
        value = nullptr;
        return false;

    } else {
        // transform comparing keyword to lower case
        key_current = the_word->getKey();
        key_compare = current->node_word->getKey();
        transform(key_current.begin(), key_current.end(), key_current.begin(), ::tolower);
        transform(key_compare.begin(), key_compare.end(), key_compare.begin(), ::tolower);
        // less case    
        if (key_current < key_compare){
            return retrieveHelper(current -> left, the_word, value);

        // greater case
        } else if (key_current > key_compare){
            return retrieveHelper(current -> right, the_word, value);
    
        // found
        } else {
            value = current -> value;
            return true;
        }
        return false;
    }
}

// @param {Word} the-word - inserted word
// @param {LList} value - inserted KWIC value
// @pre: BSt object is created, param is valid
// @post: the_word and value are inserted into the BSTNode
// @return: true or false whether insert sucessfully
// @function called: insertHelper()
bool Bst::insert(Word* the_word, LList* value){
    // empty tree case
    if(root_ == nullptr){
        root_ = new BSTNode {the_word,value, nullptr, nullptr};
        return true;
    } else {
        return insertHelper(root_, the_word, value);
    }
}

//@ param {BSTNode} root - subtree root node
// @param {Word} the-word - look up key word
// @param {LList} value - retrieving KWIC value
// @pre: BSt object is created, param is valid
// @post: the_word and value are inserted into the BSTNode
// @return: true or false whether insert sucessfully
// @function called: insertHelper(), transform()
bool Bst::insertHelper(BSTNode*& root, Word* the_word,LList* value){ 
    // base case/correct placing order
    if(root == nullptr){
        root = new BSTNode {the_word, value, nullptr, nullptr};  
    } else {
        // transform comparing keyword to lower case
        key_current = the_word->getKey();
        key_compare = root->node_word->getKey();
        transform(key_current.begin(), key_current.end(), key_current.begin(), ::tolower);
        transform(key_compare.begin(), key_compare.end(), key_compare.begin(), ::tolower);
        // less case  
        if ( key_current < key_compare){
            return insertHelper(root ->left, the_word, value);

        // greater case    
        } else if (key_current > key_compare){
            return insertHelper(root ->right, the_word, value);

        } else {
            return false;
        }
    }
    return true;
}

// @param {ostream} the_stream - for printing purposes
// @pre: BSt object is created, ostream is valid
// @post: Print tree alphabetically by keyword
// @return: none
// @function called: printHelper()
void Bst::print(ostream & the_stream) const{
    printHelper(the_stream,root_);
}

// @param {ostream} the_stream - for printing purposes
// @param {BSTNode} root - root node of tree/subtree
// @pre: BSt object is created, ostream is valid
// @post: Print tree alphabetically by keyword
// @return: none
// @function called: printHelper()
void Bst::printHelper(ostream & the_stream, BSTNode* root) const{
    if(root == nullptr){
        return;
    } else {
        printHelper(the_stream, root->left);
        the_stream << *root->value << endl;
        printHelper(the_stream, root->right);
    }
}






