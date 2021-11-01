//
// Created by arminveres on 10/30/21.
//

#ifndef ADCPP_PVECTOR_H
#define ADCPP_PVECTOR_H

#include "fstream"
#include "string"
#include "vector"

#include "persistance_traits.h"

//  class
template<typename T, typename P=persistence_traits<T>>
class pVector {

    std::string filename;
    std::vector<T> v;

    void readSet() {
        std::ifstream ifs(filename);
        for (;;) {
            T elem;
            persister::read(ifs, elem);
            if (!ifs.good()) break;
            v.push_back(elem);
        }

    }

    void writeSet() {
        std::ofstream ofs(filename);
        iterator first = v.begin(), last = v.end();
        while (first != last) {
            persister::write(ofs, *first++);
        }
    }

public:
    typedef P persister;
    typedef typename std::vector<T>::iterator iterator;

    pVector(std::string fname) : filename(fname) {
        readSet();
    }

    ~pVector() {
        writeSet();
    }

//    vector methods

    iterator begin() {
        return v.begin();
    }

    iterator end() {
        return v.end();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back() {
        v.pop_back();
    }

    void printVector() {
        for (auto el : v) {
            std::cout << el << "\n";
        }
        std::cout << std::endl;
    }

};

#endif //ADCPP_PVECTOR_H
