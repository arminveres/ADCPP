//
// Created by arminveres on 11/2/21.
//

#include "simplespellchecker.h"

using namespace std;

simplespellchecker::simplespellchecker(std::string &dictPath, std::string &textPath)
: dictionary(dictPath), textIn(textPath)
{
//    readText(textPath);
}
// reads into a vector for it to compare afterwards
void simplespellchecker::readText()
{
    char c;
    string toVec;
    while (true) {
        textIn.get(c);
        if (!textIn.good()) break;
        if (c == '\n' || c == ' ' || c == '\t') {
            textToBeChecked.push_back(toVec);
            toVec = "";
        }
        if (c >= 65 && c <= 90 || c >= 97 && c <= 122) toVec.push_back(c);
    }
}