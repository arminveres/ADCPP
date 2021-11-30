#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include "between.h"

using namespace std;

int main() {

    vector<int> vec = {1,3,5,7,9};
    auto first = vec.begin();
    auto last = vec.end();
    auto current = (first + 6);
    bool isBetween = between(first, last, current);
    cout << "testing random access iterator..." << endl;
    cout << "the current iterator is between: ";
    cout << boolalpha << isBetween << endl;

    list<int> ls = {2,4,6,8,0};
    auto first2 = ls.begin();
    auto last2 = ls.end();
    auto current2 = next(first2, 2);
    bool isBetween2 = between(current2, last2, first2);
    cout << "testing forward access iterator..." << endl;
    cout << "the current iterator is between: ";
    cout << boolalpha << isBetween2 << endl;
}
