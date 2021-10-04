//
// Created by arminveres on 10/4/21.
//

#include <iostream>
#include <numeric>

using namespace std;


class fraction {
    int cntr;
    int denom;

public:
    fraction (int c = 0, int d = 1) :
    cntr(c), denom(d)
    {}

    int get_counter() {
        return cntr;
    }

    void set_counter(int c) {
        cntr = c;
    }

    int get_denominator() {
        return denom;
    }

    void set_denom(int d) {
        denom = d;
    }

    fraction operator* (fraction b) {
        int f1 = gcd(this->cntr, b.denom);
        int f2 = gcd(b.cntr, this->denom);

        return {(this->cntr/f1) * (b.cntr/f2),
                (this->denom/f2) * (b.denom/f1)};
    }

    fraction operator/ (fraction b) {
        int f1 = gcd(this->cntr, b.denom);
        int f2 = gcd(b.cntr, this->denom);

        return {(this->cntr/f1) * (b.denom/f1),
                (this->denom/f2) * (b.cntr/f2)}
    }

    fraction operator+ (fraction b) {

    }

    fraction operator- (fraction b) {

    }

    fraction operator<< (fraction b) {

    }

    fraction operator>> (fraction b) {

    }


};

