//
// Created by arminveres on 10/21/21.
//

#include <sstream>
#include "iostream"

#include "fraction.h"
#include "pvector.h"

template <typename T> void revPol(std::string saveloc) {
    std::string save = saveloc;
    pVector<int> stack(save);

    auto curr = stack.begin();

    std::string cmd;
    bool isRunning = true;
    char ch;
    T num;

    while(isRunning) {
        std::cout << "Enter command: " << std::endl;
        getline(std::cin, cmd);

        // holds commands
        std::istringstream argsStream(cmd);

        while (argsStream >> ch) {
            if (!argsStream.good()) break;

            switch (ch) {
                case 'n': {
                    argsStream >> num;
                    stack.push_back(num);
                    curr = stack.end() - 1;
                    break;
                }
                case 'q': {
//                    argsStream >> ch;
                    std::cout << "quitting..." << std::endl;
                    isRunning = false;
                    break;
                }
                case 'd': {
                    if (curr >= stack.begin()) {
//                        argsStream >> ch;
                        stack.pop_back();
                        curr = stack.end() - 1;
                    } else {
                        std::cout << "nothing on the stack" << std::endl;
                    }
                    break;
                }
                case '+': {
                    if (curr != std::begin(stack)) {
//						argsStream >> ch;
                        std::cout << "operation: " << ch << std::endl;

                        stack.pop_back();
                        stack.pop_back();
                        int res = *curr + *(curr-1);

                        stack.push_back(res);
                        curr = stack.end() - 1;
                        std::cout << "result: " << res << std::endl;
                        std::cout << "current iterator value: " << *curr << std::endl;
                    } else {
                        std::cout << "nothing on the stack" << std::endl;
                    }
                    break;
                }
                case '-': {
                    if (curr != stack.begin()) {
//						argsStream >> ch;
                        std::cout << "operation: " << ch << std::endl;
                        stack.pop_back();
                        stack.pop_back();
                        int res = *curr - *(curr-1);

                        stack.push_back(res);
                        curr = stack.end() - 1;
                        std::cout << "result: " << res << std::endl;
                        std::cout << "current iterator value: " << *curr << std::endl;
                    } else {
                        std::cout << "nothing on the stack" << std::endl;
                    }
                    break;
                }
                case '*': {
                    if (curr != stack.begin()) {
//						argsStream >> ch;
                        std::cout << "operation: " << ch << std::endl;

                        stack.pop_back();
                        stack.pop_back();
                        int res = *curr * *(curr-1);

                        stack.push_back(res);
                        curr = stack.end() - 1;
                        std::cout << "result: " << res << std::endl;
                        std::cout << "current iterator value: " << *curr << std::endl;
                    } else {
                        std::cout << "nothing on the stack" << std::endl;
                    }
                    break;
                }
                case '/': {
                    if (curr != stack.begin()) {
//						argsStream >> ch;
                        std::cout << "operation: " << ch << std::endl;

                        stack.pop_back();
                        stack.pop_back();
                        int res = *curr / *(curr-1);

                        stack.push_back(res);
                        curr = stack.end() - 1;
                        std::cout << "result: " << res << std::endl;
                        std::cout << "current iterator value: " << *curr << std::endl;
                    } else {
                        std::cout << "nothing on the stack" << std::endl;
                    }
                    break;
                }
            }
            stack.printVector();
        }
    }
}

int main() {
    std::string saveloc = "save.txt" ;
    revPol<fraction>(saveloc);
}
