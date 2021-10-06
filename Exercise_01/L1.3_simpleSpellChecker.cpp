//
// Created by arminveres on 10/5/21.
//

// two files as input, first a dict file containing words
// second a file whose contents must be checked

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
    ifstream dictIn(argv[1]);
    ifstream textIn(argv[2]);

    set<string> dictSet;
    string insertStr;

    vector<string> checkIt;

//    read file in with istream >>
    while (!dictIn.eof()) {
        dictIn >> insertStr;
        dictSet.insert(insertStr);
    }

//    words from the "to be checked" file are getting trimmed down, i.e. symbols are cut away.
//  Then they are pushed to the vector
    char c;
    string toVec;
    while (true) {
        textIn.get(c);
        if (!textIn.good()) break;
        if (c == '\n' || c == ' ' || c == '\t') {
//            toVec.append("\n");
            checkIt.push_back(toVec);
            toVec = "";
        }
        if (c >= 65 && c <= 90 || c >= 97 && c <= 122) toVec.push_back(c);
    }

    bool correct = true;
    for (string chk : checkIt) {
        for (string dict : dictSet) {
            if (dict == chk) {
                correct = true;
                break;
            } else {
                correct = false;
            }
        }
        if (!correct) cout << chk << endl;
    }

    return 0;
}

