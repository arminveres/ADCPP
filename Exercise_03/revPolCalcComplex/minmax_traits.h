//
// Created by arminveres on 11/2/21.
//

#ifndef ADCPP_MINMAX_TRAITS_H
#define ADCPP_MINMAX_TRAITS_H

#include "complex"

template <typename T>
struct MinMaxTraits {
    static T min(T a, T b) {
        return a < b ? a : b;
    }
    static T max(T a, T b) {
        return a > b ? a : b;
    }
};

template <typename T>
struct MinMaxTraits<std::complex<T>> {
    static std::complex<T> min(std::complex<T> a, std::complex<T> b) {
        return std::norm(a) < std::norm(b) ? a : b;
    }

    static std::complex<T> max(std::complex<T> a, std::complex<T> b) {
        return std::norm(a) > std::norm(b) ? a : b;
    }
};

#endif //ADCPP_MINMAX_TRAITS_H
