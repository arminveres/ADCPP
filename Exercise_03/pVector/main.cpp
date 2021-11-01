//
// Created by arminveres on 10/30/21.
//

#include <iostream>
#include "string"
#include "pvector.h"
#include "pset.h"

using namespace std;

int main() {
    string chartxt = "chars.txt";
//    pVector<char> charVec(chartxt);
//    charVec.push_back('a');
//    charVec.push_back('r');
//    charVec.push_back('m');
//    charVec.push_back('i');
//    charVec.push_back('n');


    string intstxt = "ints.txt";
    pVector<int> intVec(intstxt);
//    intVec.push_back(5);
//    intVec.push_back(4);
//    intVec.push_back(3);
//    intVec.push_back(2);
//    intVec.push_back(1);

    string stringtxt = "stringtxt.txt";
    pVector<string> stringVec(stringtxt);
//    stringVec.push_back("hello");
//    stringVec.push_back("armin");
//    stringVec.push_back("how are");
//    stringVec.push_back("you");
//    charVec.printVector();
//    intVec.printVector();
//    stringVec.printVector();

    string setstring = "setstring.txt";
    pSet<string> stringset(setstring);
//    stringset.insert("hello sweethear");
//    stringset.insert("ah generel kenobi");
//    stringset.insert("hello there");
//    stringset.insert("armin is here");
//    stringset.insert("duplicate");
    stringset.printSet();

    return 0;
}
