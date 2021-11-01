//
// Created by arminveres on 10/31/21.
//

#ifndef ADCPP_DUMB_POINTER_H
#define ADCPP_DUMB_POINTER_H

#include "iostream"

template <typename T>
class dumb_pointer {

    T *ptr;

    friend std::ostream& operator<<(std::ostream& os, dumb_pointer<T>& p) {
        os << p.ptr;
    }

public:
    dumb_pointer(T *in_ptr) : ptr(in_ptr)
    {}

    ~dumb_pointer() {
        delete ptr;
    }

    T& operator* () {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }
};


#endif //ADCPP_DUMB_POINTER_H
