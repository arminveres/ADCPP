#ifndef MERGECONT_H
#define MERGECONT_H

#include <algorithm>
#include <iterator>
#include <set>
#include <iostream>

/*
 * it sadly didn't work with the back inserter, it's much simpler with the inserter 
 * it had errors, that set didn't have pushback. 
 */
template<typename C1, typename C2, typename RES>
void mergecont(C1 &con1, C2 &con2, RES &res) {
    std::merge(con1.begin(), con1.end(), con2.begin(), con2.end(), std::inserter(res, res.begin()));
}

template<typename T>
void print(const T &t) {
    for (auto el : t) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

 template<typename T>
 void print(const std::map<T, T> &t) {
     for (auto el : t) {
         std::cout << el.first << ":" << el.second << " ";
     }
     std::cout << std::endl;
 }

#endif
