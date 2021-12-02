#include <string>
#include <regex>

#include "../../Exercise_03/pVector/pvector.h"
#include "../../Exercise_03/pVector/pset.h"

using namespace std;

void spellcheck(string &dictionary, string &file) {
    pSet<string> dict(dictionary);
    pVector<string> text(file);
    regex reg_word("\\w+");

    // first every words gets read in
    for (string line : text) {
        auto words_begin = sregex_iterator(line.begin(), line.end(), reg_word);
        auto words_end = sregex_iterator();
        for (sregex_iterator regit = words_begin; regit != words_end; ++regit) {
            smatch match = *regit;
            string match_str = match.str();

            // now we match against the regexes in the dict
            for (const string &reg_dict : dict) {
                regex reg_in_dict(reg_dict);
                /* if (regex_match(match_str, reg_in_dict)) { */
                /*     cout << "Found matching word: " <<  match_str << endl; */
                /*     break; */
                /* } */
                if (!regex_match(match_str, reg_in_dict)) {
                    cout << "Found non-matching word: " << match_str << endl;
                    break;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 3) {
        string dict(argv[1]), text(argv[2]);
        spellcheck(dict, text);
        return 0;
    }
    return 1;
}

/* sregex_iterator with "(\\w+)" as RE to parse full words from input (omitting punct. and other 
* chars -> just use a text file, easier and faster */
