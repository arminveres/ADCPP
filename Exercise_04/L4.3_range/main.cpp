#include <iostream>
#include "range.h"

using namespace std;

int main() {
    for (auto i : range(10,20))
        cout << i << endl;
}
