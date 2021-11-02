//
// Created by arminveres on 11/2/21.
//

#include "iostream"
#include "string"

#include "rpn.h"
#include "../../Exercise_02/fraction.h"
//#include "/home/arminveres/GitHubFiles/JaanWilli_Cpp2020/ex1_2/fraction.h"
//#include "/home/arminveres/GitHubFiles/JaanWilli_Cpp2020/ex3_3/rpn.h"

using namespace std;

template <typename T>
int run_rpn(RPN<T> &rpn) {
    T in;
    string commands;

    for (;;) {
        cout << "Enter command: ";
        getline(cin, commands);        
        istringstream argstream(commands);
        string args;

        while (argstream >> args) {
            if (args == "n") {
                argstream >> in;
                rpn.push(in);
            } else if (args == "q") {
                cout << "quitting..." << endl;
                return 0;
            } else if (args == "d") {
                cout << "popping:" << rpn.pop() << endl;
            } else if (args == "+") {
                rpn.add();
            } else if (args == "-") {
                rpn.subtract();
            } else if (args == "*") {
                rpn.multiply();
            } else if (args == "/") {
                rpn.divide();
            } else if (args == "min") {
                rpn.min();
            } else if (args == "max") {
                rpn.max();
            }
        }
        rpn.print_stack();
    }

}

int main() {

//    RPN<int> rpn;
//    run_rpn(rpn);

//    RPN<fraction> rpn;
//    run_rpn(rpn);

//    RPN<double> rpn;
//    run_rpn(rpn);

    RPN<complex<int>> rpn;
    run_rpn(rpn);


    return 0;
}
