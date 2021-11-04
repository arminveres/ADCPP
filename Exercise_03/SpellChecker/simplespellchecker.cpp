//
// Created by arminveres on 11/2/21.
//

#include "iostream"

#include "simplespellchecker.h"

using namespace std;

simplespellchecker::simplespellchecker(std::string &dictPath, std::string &textPath)
: dictionary(dictPath), textIn(textPath)
{
    readText();
    checkText();
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

void simplespellchecker::checkText()
{

    for (auto word : textToBeChecked) {
        if (dictionary.count(word) == 0 && ignored.count(word) == 0) {
//            interactive part where the user may add unused word
            char c;
            cout << "found word: " << word << endl;
            cout << "add ignore or correct? [a,i,c]: ";
            cin >> c;
            cout << endl;

            switch (c) {
                case 'a': {
                    dictionary.insert(word);
                    break;
                }
                case 'i': {
                    ignored.insert(word);
                    break;
                }
                case 'c': {
                    string new_word;
                    cin >> new_word;
                    word = new_word;
                    cout << "new corrected word is" << word << endl;
                    break;
                }
                default:
                    cout << "wrong input, try again" << endl;
                    continue;
            }
        }
//        else cout << word << endl;
    }
}

simplespellchecker::~simplespellchecker() = default;
