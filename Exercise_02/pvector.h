//
// Created by arminveres on 10/21/21.
//
#include <string>
#include <fstream>
#include <vector>
#include <string>

#ifndef ADCPP_PVECTOR_H
#define ADCPP_PVECTOR_H

template<typename T> class pVector {
    std::string filename;
    std::vector<T> v;

    void readVector() {
        std::ifstream ifs(filename);
        while (true) {
            T x;
            ifs >> x;
            if (!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writeVector() {
        std::ofstream ofs(filename);
        if (ofs.is_open()) {
            for (const T &elem : v) {
                ofs << elem << std::endl;
            }
        } else std::cout << "no file" << std::endl;
    }

public:
    pVector(std::string fname) : filename(fname) {
        readVector();
    }

    typename std::vector<T>::iterator begin() {
        return v.begin();
    }

    typename std::vector<T>::iterator end() {
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
            std::cout << el << std::endl;
        }
    }

};
#endif //ADCPP_PVECTOR_H
