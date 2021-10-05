//
// Created by arminveres on 10/5/21.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    vector<int> stack;

    auto curr = begin(stack);

    string cmd;
    bool isRunning = true;
    bool cmdExists = true;
    char ch;
    int num;

    while(isRunning) {
        cout << "Enter command: " << endl;
        getline(cin, cmd);
//        cout << cmd << endl;
        // holds commands
        istringstream argsStream(cmd);

        while (cmdExists) {
            if (!argsStream.good()) break;

            argsStream >> ch;
//            cout << ch;

            switch (ch) {
                case 'n': {
                    argsStream >> num;
                    stack.push_back(num);
                    curr = end(stack) - 1;
                    cout << *curr << endl;

                    break;
                }
                case '+': {
                    if (curr != end(stack)) {
//                        cout << "curr=" << *curr << endl;
                        int res = *curr + *(curr-1);
                        stack.push_back(res);
                        curr = end(stack) - 1;
                        cout << "the result: " << res << endl;
//                        cmdExists = false;
                        cout << "current iterator value: " << *curr << endl;
                    }
                    break;
                }
                case '-': {
                    if (curr != end(stack)) {
                        int res = *curr - *(--curr);
                        stack.push_back(res);
                        cout << res << endl;

//                        cout << *first << "\t" << *last << "\t" << *curr << endl;
                    }
                    break;
                }
                case '*': {
                    break;
                }
                case '/': {
                    break;
                }
                case 'q': {
                    cout << "quitting...";
                    isRunning = false;
                    cmdExists = false;
                    break;
                }
                default: {
                    cout << "invalid cmd" << endl;
                    cmdExists = false;
//                    isRunning = false;
                    break;
                }
            }
        }
        cout << "Stack:\t";
        for (int st : stack) cout << st << "\t";
        cout << endl;
    }
}