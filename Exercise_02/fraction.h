//
// Created by arminveres on 10/21/21.
//

#ifndef ADCPP_FRACTION_H
#define ADCPP_FRACTION_H

#include <fstream>

class fraction {
    int cntr;
    int denom;

    friend std::istream &operator>>(std::istream &is, fraction &f);
    friend std::ostream &operator<<(std::ostream &os, fraction f);

public:
    fraction(int c = 0, int d = 1) :
            cntr(c), denom(d)
    {}
    int get_counter();
    void set_counter(int c);
    int get_denominator();
    void set_denominator(int d);

    fraction operator* (fraction b);
    fraction operator/ (fraction b);
    fraction operator+ (fraction b);
    fraction operator- (fraction b);

    bool operator<(fraction b);
    bool operator>(fraction b);
};
//std::ostream &operator<<(std::ostream &os, fraction f);
//std::istream &operator>>(std::istream &is, fraction &f);
void check_char(std::istream &is, char ch);
#endif //ADCPP_FRACTION_H
