// LList.cpp
// @Author: Kray Nguyen
// 1/22/2021
// Linked List class that stores blocks of KWIC information

#include "LList.h"
using namespace std;

LList::LList(){
    this->head_ = nullptr;
}

LList::~LList(){
    // DeleteList();
    delete head_;
}

// @pre: LList object is created
// @post: all node deleted from Linked list
// @return: none
// @function called: none
void LList:: DeleteList(){
    Node* temp_;
    while(head_ != nullptr){
        temp_ = head_;
        head_ = head_ -> next_;
        delete temp_->node_word;
        delete temp_;
        temp_ = nullptr;
    }
    head_ = nullptr;

}

// @pre: LList object is created
// @post: none:
// @return: true or false whether linked list is empty
// @function called: none
bool LList::isEmpty() const{
    return this->head_ == nullptr;
}

// @param {Word*} the_word - KWIC needed to be inserted 
// @pre: Word* the_word is valid
// @post: KWIC added to Linked list
// @return: true or false whether sucessfully added 
// @function called: none
bool LList::Insert(Word* the_word){
    Node* tempNode = new Node;
    Node* current_;

    tempNode -> node_word = the_word;

    //if nothing in the list yet
    if(this->isEmpty()){
        tempNode -> next_ = head_;
        head_ = tempNode;

    // otherwise, link the node appropriately to insert
    } else {
        current_ = head_;
        while(current_ -> next_ != nullptr){
            current_ = current_ -> next_;
        }
        current_-> next_ = tempNode;
        tempNode -> next_ = nullptr;
    }

    return true;
}

