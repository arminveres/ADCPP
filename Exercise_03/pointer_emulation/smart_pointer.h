//
// Created by arminveres on 11/1/21.
//

#ifndef ADCPP_SMART_POINTER_H
#define ADCPP_SMART_POINTER_H

#include "iostream"

template <typename T>
class smart_pointer {

    T *ptr;
//    we have to use pointer to an int, as otherwise the value cant be correctly given over to the next object and
//    incremented
    int32_t *ctr;

//    friend std::ostream& operator<<(std::ostream& os, dumb_pointer<T>& p) {
//        os << p.ptr;
//    }

    void incr() {
        ++(*ctr);
    }

    void decr() {
        --(*ctr);
    }

public:
    smart_pointer(T *in_ptr) : ptr(in_ptr)
    {
        ctr = new int(1);
    }

    smart_pointer(const smart_pointer<T>& ptr2) : ptr(ptr2.ptr), ctr(ptr2.ctr)
    {
        incr();
    }

    ~smart_pointer() {
        decr();
    }

    T& operator* () {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    smart_pointer<T>& operator=(const smart_pointer<T>& p) {
//        if addresses equal
        if (this == &p) return *this;
//        decrease counter for first object
        decr();
//        assign
        this->ctr = p.ctr;
        this->ptr = p.ptr;
//        increase counter for second object
        incr();
        return *this;
    }

    uint32_t counter() {
        return *ctr;
    }
};
#endif //ADCPP_SMART_POINTER_H
