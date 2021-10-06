//
// Created by arminveres on 10/5/21.
//
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int main() 
{
    vector<int> stack;

    auto curr = begin(stack);

    string cmd;
    bool isRunning = true;
    char ch;
    int num;

    while(isRunning) {
        cout << "Enter command: " << endl;
        getline(cin, cmd);

        // holds commands
        istringstream argsStream(cmd);

        while (argsStream >> ch) {
            if (!argsStream.good()) break;

            switch (ch) {
                case 'n': {
                    argsStream >> num;
                    stack.push_back(num);
                    curr = end(stack) - 1;
                    break;
                }
                case 'q': {
                    argsStream >> ch;
                    cout << "quitting..." << endl;
                    isRunning = false;
                    break;
                }
                case 'd': {
                    if (curr >= begin(stack)) {
                        argsStream >> ch;
                        stack.pop_back();
                        curr = end(stack) - 1;
                    } else {
                        cout << "nothing on the stack" << endl;
                    }
                    break;
                }
                case '+': {
                    if (curr != begin(stack)) {
						argsStream >> ch;
						cout << "operation: " << ch << endl;

                        stack.pop_back();  
                        stack.pop_back();
                        int res = *curr + *(curr-1);
						
                        stack.push_back(res);
                        curr = end(stack) - 1;
                        cout << "result: " << res << endl;
                        cout << "current iterator value: " << *curr << endl;
                    } else {
                        cout << "nothing on the stack" << endl;
                    }
                    break;
                }
                case '-': {
                    if (curr != begin(stack)) {
						argsStream >> ch;
						cout << "operation: " << ch << endl;
                        stack.pop_back();  
                        stack.pop_back();
                        int res = *curr - *(curr-1);
						
                        stack.push_back(res);
                        curr = end(stack) - 1;
                        cout << "result: " << res << endl;
                        cout << "current iterator value: " << *curr << endl;
                    } else {
                        cout << "nothing on the stack" << endl;
                    }
                    break;
                }
                case '*': {
                    if (curr != begin(stack)) {
						argsStream >> ch;
						cout << "operation: " << ch << endl;

                        stack.pop_back();  
                        stack.pop_back();
                        int res = *curr * *(curr-1);
						
                        stack.push_back(res);
                        curr = end(stack) - 1;
                        cout << "result: " << res << endl;
                        cout << "current iterator value: " << *curr << endl;
                    } else {
                        cout << "nothing on the stack" << endl;
                    }
                    break;
                }
                case '/': {
                    if (curr != begin(stack)) {
						argsStream >> ch;
						cout << "operation: " << ch << endl;

                        stack.pop_back();  
                        stack.pop_back();
                        int res = *curr / *(curr-1);
						
                        stack.push_back(res);
                        curr = end(stack) - 1;
                        cout << "result: " << res << endl;
                        cout << "current iterator value: " << *curr << endl;
                    } else {
                        cout << "nothing on the stack" << endl;
                    }
                    break;
                }
        	}
        
        if (isRunning) {
            cout << "Stack:\t";
            for (int st : stack) cout << st << "\t";
            cout << endl;
        }
		}
    }
}
