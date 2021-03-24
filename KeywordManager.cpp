// KeywordManager.cpp
// @Author: Kray Nguyen
// 1/22/2021
// Class that facilitates words from files and store words and KWIC
// into appropriate LinkedList or/and Binary Search Tree
#include "KeywordManager.h"

KeywordManager::~KeywordManager(){

}

// @param {ifstream} fileName - file name of stopwords
// @pre: KeywordManager object is created
// @post: all stopwords from file are stored in stopword vector
// @return: none
// @function called: getline(), check(), push_back()
void KeywordManager::processStopWord(ifstream& stopwordFile){
    if(stopwordFile){
        while(!stopwordFile.eof()){
            string each_word;
            stopwordFile >> each_word;
            cleanPunc(each_word);
            stopword.push_back(each_word);
        }
    }
    
}

// @param {ifstream} corpusFile - file name of corpus
// @pre: KeywordManager object is created
// @post: all words from corpus file are stored in corpus vector
// @return: none
// @function called: push_back()
void KeywordManager::storeCorpus(ifstream& corpusFile){
    if(!corpusFile){
        cerr << "Corpus file not found, end the program now" << endl;
        return;
    }
    while(!corpusFile.eof()){
        string each_word;
        corpusFile >> each_word;
        corpus.push_back(each_word);
    }
}

// @param {string} word - word to check leading and trailing punctuation
// and clean if necessary
// @pre: KeywordManager object is created, word is not null
// @post: leading and trailing punctuation are removed from input word 
// and input word will change, otherwise word stay the same 
// @return: none
// @function called: erase(), pop_back()
void KeywordManager::cleanPunc(string &word){
    int front = 0;
    
    //check and clean leading punctuation
    while(ispunct(word[front])){
        word.erase(0,1);
    }
    int back = word.size() - 1;

    //check and clean trailing punctuation
    while(ispunct(word[back--])){   
        word.pop_back();
    }
}

// @param {string} word - word to check if it's a word
// @pre: KeywordManager object is created, word is not null
// @post: none
// @return: true or false whether string is empty
// @function called: none
bool KeywordManager::isWord(string word){
    return word != "";
}

// @param {string} word - word to check if it's a stopword
// @pre: KeywordManager object is created, word is not null
// @post: none  
// @return: true or false whether word is not a stopword
// @function called: none
bool KeywordManager::isNotStopWord(string word){
    string word_insensitive = word;
    transform(word_insensitive.begin(), word_insensitive.end(), word_insensitive.begin(), ::tolower);
    for(int i = 0; i < stopword.size(); i++){
        string compare = stopword.at(i);
        transform(compare.begin(), compare.end(), compare.begin(), ::tolower);
        if(compare == word_insensitive){
            return false;
        }
    }
    return true;
}

// @param {vector<string>} list - vector storing reversing list 
// for adjust left context words output 
// @param {string} left - left context words
// @pre: KeywordManager object is created, param is not null
// @post: the left context words are reversed for correct output 
// @return: none
// @function called: size(), push_back(), at(), check(), getline()
void KeywordManager::reverse(vector<string> list, string&left){
    // store left context words into a vector
    string each_word = left;
    stringstream check(each_word);
    while(getline(check,each_word, ' ')){
        list.push_back(each_word);
    }

    // swap list of left context words symmetrically
    if(list.size() > 1){
        for(int i = 0; i < list.size()/2; i++){
            string temp = list.at(i);
            list.at(i) = list.at(list.size()-1-i);
            list.at(list.size()-1-i) = temp;
        }
    }

    // modify left context word string
    left = "";
    for(int i = 0; i < list.size(); i++){
        left += list.at(i);
        left += " ";
    }

}

// @param {int} key_index - index of keyword in terms of vector 
// @param {string} left - left context words
// @pre: KeywordManager object is created, param is not null
// @post: collect left context of words to the passed in string
// @return: none
// @function called: reverse(), cleanPunc()
void KeywordManager::findLeft(int key_index, string& left){
    for(int i = 0; i < 5; i++){
        if(key_index > 0){
            key_index--;
            cleanPunc(corpus.at(key_index));
            left += corpus.at(key_index);
            left += " ";
        }
    }
    reverse(reverse_list, left);
}

// @param {int} key_index - index of keyword in terms of vector 
// @param {string} right - right context words
// @pre: KeywordManager object is created, param is not null
// @post: collect right context of words to the passed in string
// @return: none
// @function called: cleanPunc()
void KeywordManager::findRight(int key_index, string& right){
    right+= " ";
    for(int i = 0; i < 5; i++){
        if(key_index < corpus.size() - 1){
            key_index++;
            cleanPunc(corpus.at(key_index));
            right += corpus.at(key_index);
            right += " ";
        }
    }
}

// @param {ifstream} fileName - file name of corpus
// @pre: KeywordManager object is created
// @post: if file name not found in directory, end program.
// if found, collect words into corpus vector, then insert each 
// keyword into BST and LList
// @return: none
// @function called: cleanPunc(), isWord(), isNotStopWord(), findLeft()
// findRight(), Insert(), insert(), retrieve()
void KeywordManager::processCorpus(){
    count_index = 0;

    // for each word in corpus
    
    for(int i = 0; i < corpus.size(); i++){ 
        string each_word = corpus.at(i);
    // while(getline(check1,each_word,' ')){
        // check and clean trailing punctuation
        cleanPunc(each_word);

        // if that word is considered a word and not a stop word
        if(isWord(each_word)&& isNotStopWord(each_word)){
            key = each_word;
            left = "";
            right = "";
            
            // find left context info
            findLeft(count_index, left);
            
            // find right context info
            findRight(count_index, right);

            Word* new_word = new Word(left, right, key);

            // if the word already in BST, insert that word into the linkedlist
            // then add the word and linkedlist into BST
            if(wordCollections.retrieve(new_word, retrieve_value)){
                retrieve_value->Insert(new_word);
                //wordCollections.insert(new_word, retrieve_value);

            // otherwise, create a new Linked List and insert the word and new
            // linkedlist into BST
            } else {
                LList*list_value = new LList();
                list_value->Insert(new_word);
                wordCollections.insert(new_word, list_value);
            }
        }
         
        count_index++;
    }
}

// @pre: KeywordManager object is created
// @post: Print out BST inorder
// @return: none
// @function called: none
void KeywordManager::report(){
    cout << wordCollections << endl;
}