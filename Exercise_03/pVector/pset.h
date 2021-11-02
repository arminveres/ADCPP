//
// Created by arminveres on 10/31/21.
//

#ifndef ADCPP_PSET_H
#define ADCPP_PSET_H


#include "fstream"
#include "string"
#include "set"

#include "persistance_traits.h"

//  class
template<typename T, typename P=persistence_traits<T>>
class pSet {

    std::string filename;
    std::set<T> s;

    void readSet() {
        std::ifstream ifs(filename);
        for (;;) {
            T elem;
            persister::read(ifs, elem);
            if (!ifs.good()) break;
            s.insert(elem);
        }

    }

    void writeSet() {
        std::ofstream ofs(filename);
        iterator first = s.begin(), last = s.end();
        while (first != last) {
            persister::write(ofs, *first++);
        }
    }

public:
    typedef P persister;
    typedef typename std::set<T>::iterator iterator;

    pSet(std::string fname) : filename(fname) {
        readSet();
    }

    ~pSet() {
        writeSet();
    }

    void insert(const T &el) {
        s.insert(el);
    }

    void printSet() {
        for (auto el : s) {
            std::cout << el << std::endl;
        }
    }
};
#endif //ADCPP_PSET_H
