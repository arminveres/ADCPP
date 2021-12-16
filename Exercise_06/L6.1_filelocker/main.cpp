#include <iostream>

#include "pvector.h"

using namespace std;

int main() {
    pVector<int> vi("integers.txt");

    cout << "Vector contains: ";
    for (const int &i : vi) {
        cout << i << " ";
    }
    cout << endl;

    int i;
    cout << "add integer to vector: ";
    cin >> i;
    vi.push_back(i);

    cout << "New vector contains: ";
    for (const int &i : vi) {
        cout << i << " ";
    }
    cout << endl;
}
