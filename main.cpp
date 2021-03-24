// main.cpp
// @Author: Kray Nguyen
// 1/22/2021
// Input: file name of the corpus file within the directory
// Output: keyword in context that is presented alphabetically 
// by keyword
// Usage: ./a.out fileName 
// Assumption: All KWIC are stored into Word class after being extracted from 
// the file
// Assumption: the program stops if not found the corpus file
// Assumption: the program continues if there is no stopwords.txt
// Major algorithms: BST storing key-pair value of KWIC. In this case, 
// key as Word object and value as LList object
// Major algorithms: LList storing chains of KWIC within the same keyword
#include "KeywordManager.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <ostream>
#include <fstream>
#include <algorithm> 


using namespace std;

int main(int argc, char *argv[]){
    KeywordManager manager;
    ifstream stopwordFile("stopwords.txt");
    manager.processStopWord(stopwordFile);
    string file_name = argv[1];
    file_name += ".txt"; 
    
    ifstream corpusFile(file_name);
    manager.storeCorpus(corpusFile);
    manager.processCorpus();
    manager.report();

    return 0;
}   