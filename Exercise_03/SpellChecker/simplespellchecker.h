//
// Created by arminveres on 11/2/21.
//

#ifndef ADCPP_SIMPLESPELLCHECKER_H
#define ADCPP_SIMPLESPELLCHECKER_H

#include "string"
#include "vector"
#include "fstream"

//#include "../pVector/pvector.h"
#include "../pVector/pset.h"

class simplespellchecker {
//    file gets initialized
    pSet<std::string> dictionary;
//    get file into filestream
    std::ifstream textIn;
//    a vector with all the strings to be checked
    std::vector<std::string> textToBeChecked;

//    reads text into textToBeChecked
    void readText();

public:
    simplespellchecker(std::string &dictPath, std::string &textPath);
};


#endif //ADCPP_SIMPLESPELLCHECKER_H
