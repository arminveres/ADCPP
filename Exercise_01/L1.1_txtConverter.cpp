//
// Created by arminveres on 10/4/21.
//

// converts unix style textToBeChecked files to MSDOS style and vice versa

// Unix uses \n
// MSDOS uses \r\n
// dealing with incorr. formatted unix textToBeChecked files?

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
//    argv[1]: from
//    argv[2]: to

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);
    char c;
    bool skip(false);

    while (true) {
        ifs.get(c);
        if (!ifs.good()) break;
//      since it's converting, if there's a \r the bool flag skip will be set for the following loop
//      to insert only a \n. This should circumvent any incorrectly formatted textToBeChecked files
        if (c == '\r') {
            ofs << "";
            skip = true;
        }
        else if (c == '\n' && skip) {
            ofs << "\n";
            skip = false;
        }
        else if (c == '\n') ofs << "\r\n";
        else ofs << c;
    }

}
