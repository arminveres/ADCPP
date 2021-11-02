//
// Created by arminveres on 10/31/21.
//

#ifndef ADCPP_PERSISTANCE_TRAITS_H
#define ADCPP_PERSISTANCE_TRAITS_H

#include "fstream"
#include "string"

//  persistence traits for all cases
template <typename T>
struct persistence_traits {

    static void read(std::ifstream &ifs, T &elem) {
        ifs >> elem;
    }

    static void write(std::ofstream &ofs, const T &elem) {
        if (ofs.is_open()) {
            ofs << elem << std::endl;
        } else std::cout << "no file" << std::endl;
    }
};

//  persistance trait for string
template <>
struct persistence_traits<std::string> {

    static void read(std::ifstream &ifs, std::string &elem) {
        std::getline(ifs, elem);
    }

    static void write(std::ofstream &ofs, const std::string &elem) {
        ofs << elem << std::endl;
    }
};

#endif //ADCPP_PERSISTANCE_TRAITS_H
