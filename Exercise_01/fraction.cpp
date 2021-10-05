//
// Created by arminveres on 10/4/21.
//

#include <iostream>
#include <numeric>

using namespace std;


class fraction {
    int cntr;
    int denom;

    friend istream &operator>>(istream &is, fraction &f);
    friend ostream &operator<<(ostream &os, fraction f);

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
                (this->denom/f2) * (b.cntr/f2)};
    }

    fraction operator+ (fraction b) {
        fraction retVal ((this->cntr * b.denom) + (b.cntr * this->denom),
                         this->denom * b.denom);
        int fac = gcd(retVal.cntr, retVal.denom);
        retVal.cntr /= fac;
        retVal.denom /= fac;

        return retVal;
    }

    fraction operator- (fraction b) {
        fraction retVal ((this->cntr * b.denom) - (b.cntr * this->denom),
                         this->denom * b.denom);
        int fac = gcd(retVal.cntr, retVal.denom);
        retVal.cntr /= fac;
        retVal.denom /= fac;

        return retVal;
    }



};
//  cannot be defined as member function of other classes
ostream &operator<<(ostream &os, fraction f) {
    os << '(' << f.cntr << '/' << f.denom << ')';
    return os;
}

void check_char(istream &is, char ch) {
    char c;
    is >> c; if(c!=ch) {
        is.putback(c); is.setstate(ios::badbit);
    }
}

istream &operator>>(istream &is, fraction &f) {
    fraction g;
    check_char(is, '(');
    is >> g.cntr;
    check_char(is, '/');
    is >> g.denom;
    check_char(is, ')');
    if(is) f=g;
    return is;
}
//  Ends here

int main() {

    int c1, d1, c2, d2;
    char op;
    bool run = true;

    while (run) {
        cout << "Enter first fraction c / d\n";
        cin >> c1;
        cout << "/\n";
        cin >> d1;
        cout << "Enter second fraction  c / d\n";
        cin >> c2;
        cout << "/\n";
        cin >> d2;
        cout << "Enter operation (+, -, *, / or q (quit)): \n";
        cin >> op;
        fraction one(c1, d1);
        fraction two(c2, d2);
        switch (op) {
            case '+':
                cout << (one + two);
                break;
            case '-':
                cout << (one - two);
                break;
            case '*':
                cout << (one * two);
                break;
            case '/':
                cout << (one / two);
                break;
            case 'q':
                cout << "quitting...";
                run = false;
                break;
            default:
                run = false;
                break;
        }
    }
    return 0;
}