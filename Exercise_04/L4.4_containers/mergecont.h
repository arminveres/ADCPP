#ifndef MERGECONT_H
#define MERGECONT_H

#include <algorithm>
#include <set>
#include <iostream>
#include <map>

#include "mergecont_traits.h"

// usage: (container type CT) mergecont(container1, container2)
template<typename T, typename C1, typename C2, typename M=merge_traits<T, C1>>
C1 mergecont(const C1& container1, const C2& container2) {

    C1 result;

    for (T elem : container1) {
        M::mergec(result, elem);
    }
    for (T elem : container2) {
        M::mergec(result, elem);
    }

    return result;
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
