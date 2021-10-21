//
// Created by arminveres on 10/21/21.
//

#include "numeric"
#include "iostream"

#include "fraction.h"


int fraction::get_counter() {
    return this->cntr;
}

void fraction::set_counter(int c) {
    this->cntr = c;
}

int fraction::get_denominator() {
    return this->denom;
}

void fraction::set_denominator(int d) {
    this->denom = d;
}

fraction fraction::operator*(fraction b) {
    int f1 = std::gcd(this->cntr, b.denom);
    int f2 = std::gcd(b.cntr, this->denom);

    return {(this->cntr/f1) * (b.cntr/f2),
            (this->denom/f2) * (b.denom/f1)};
}

fraction fraction::operator/ (fraction b) {
    int f1 = std::gcd(this->cntr, b.denom);
    int f2 = std::gcd(b.cntr, this->denom);

    if (b.get_denominator() == 0) {
        std::cout << "division by 0!" << std::endl;
        return fraction();
    }

    return {(this->cntr/f1) * (b.denom/f1),
            (this->denom/f2) * (b.cntr/f2)};
}

fraction fraction::operator+ (fraction b) {
    fraction retVal ((this->cntr * b.denom) + (b.cntr * this->denom),
                     this->denom * b.denom);
    int fac = std::gcd(retVal.cntr, retVal.denom);
    retVal.cntr /= fac;
    retVal.denom /= fac;

    return retVal;
}

fraction fraction::operator- (fraction b) {
    fraction retVal ((this->cntr * b.denom) - (b.cntr * this->denom),
                     this->denom * b.denom);
    int fac = std::gcd(retVal.cntr, retVal.denom);
    retVal.cntr /= fac;
    retVal.denom /= fac;

    return retVal;
}


void check_char(std::istream &is, char ch) {
    char c;
    is >> c; if(c!=ch) {
        is.putback(c); is.setstate(std::ios::badbit);
    }
}

std::istream &operator>>(std::istream &is, fraction &f) {
    fraction g;
    check_char(is, '(');
    is >> g.cntr;
    check_char(is, '/');
    is >> g.denom;
    check_char(is, ')');
    if(is) f=g;
    return is;
}

std::ostream &operator<<(std::ostream &os, fraction f) {
    os << '(' << f.cntr << '/' << f.denom << ')';
    return os;
}
