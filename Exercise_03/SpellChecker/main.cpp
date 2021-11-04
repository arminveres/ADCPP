//
// Created by arminveres on 11/2/21.
//

#include "fstream"
#include "iostream"

#include "simplespellchecker.h"

using namespace std;

int main(int argc, char **args) {
//    fstream dictionary(args[1]);
//    fstream text(args[2]);

//    fstream dictionary("dict.txt");
//    fstream text("text.txt");

//    string dictionary = args[1];
//    string text = args[2];
    string dictionary = "dict.txt";
    string text = "text.txt";

//    simplespellchecker ssc((string &) "dict.txt", (string &) "text.txt");
    simplespellchecker ssc(dictionary, text);
    return 0;
}