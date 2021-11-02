//
// Created by arminveres on 11/2/21.
//

#ifndef ADCPP_RPN_H
#define ADCPP_RPN_H

#include "iostream"

#include "minmax_traits.h"
#include "../pVector/pvector.h"

template <typename T, typename C=MinMaxTraits<T>>
class RPN {
    pVector<T> stack;

public:
    RPN() : stack("stack.txt")
    {}

    void push(T el) {
        stack.push_back(el);
    }

    T pop() {
        T el = stack.back();
        stack.pop_back();
        return el;
    }

    void print_stack() {
        for (auto el : stack) {
           std::cout << el << "\t";
        }
        std::cout << std::endl;
    }

    void add() {
        if (stack.size() < 2) return;
        push(pop() + pop());
    }

    void subtract() {
        if (stack.size() < 2) return;
        push(pop() - pop());
    }

    void multiply() {
        if (stack.size() < 2) return;
        push(pop() * pop());
    }

    void divide() {
        if (stack.size() < 2) return;
        push(pop() / pop());
    }

    void min() {
        if (stack.size() < 2) return;
        push(C::min(pop(), pop()));
    }

    void max() {
        if (stack.size() < 2) return;
        push(C::max(pop(), pop()));
    }


};

#endif //ADCPP_RPN_H
