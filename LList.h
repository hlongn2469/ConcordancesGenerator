// LList.h
// @Author: Kray Nguyen
// 1/22/2021
// Linked List class that stores blocks of KWIC information

#include <iostream>
#include "Word.h"

using namespace std;

class LList {

    // @param {ostream} the_stream - used for printing purposes
    // @param {LList} other - The targeted Linked List to print
    // @pre: LList other is valid
    // @post: KWIC printed to console
    // @return: ostream the_stream
    // @function called: none
    friend ostream& operator<<(ostream &the_stream,const LList &other){
        Node* current = other.head_;
        while(current != nullptr){
            the_stream << *current->node_word << endl;
            current = current->next_;
        }
        return the_stream;
    }
public:

    LList();
    ~LList();

    // @param {Word*} the_word - KWIC needed to be inserted 
    // @pre: Word* the_word is valid
    // @post: KWIC added to Linked list
    // @return: true or false whether sucessfully added 
    // @function called: none
    bool Insert(Word* the_word);

    // @pre: LList object is created
    // @post: none:
    // @return: true or false whether linked list is empty
    // @function called: none
    bool isEmpty() const;

    // @pre: LList object is created
    // @post: all node deleted from Linked list
    // @return: none
    // @function called: none
    void DeleteList();

private:
    struct Node{
        Word* node_word;
        Node *next_;
    };
    Node* head_;
};