#include <iostream>
#include <vector>
#include <set>
#include <map>

#include "mergecont.h"

using namespace std;



int main() {
    vector<int> con1 = {1,3,5};
    vector<int> con2 = {2,4,6};
    vector<int> res = mergecont<int>(con1, con2);
    cout << "vector: ";
    print(res);

    set<int> con11 = {1,3,5};
    set<int> con21 = {2,4,6};
    set<int> res2 = mergecont<int>(con11, con21);
    cout << "set: ";
    print(res2);

    vector<int> setmix = mergecont<int>(con1, con21);
    cout << "set into vector: ";
    print(setmix);


    map<int, int> m1 = {{1,10}, {2,20}, {3,30}};
    map<int, int> m2 = {{3,30}, {4,40}, {5,50}};

    map<int, int> m = mergecont<pair<int, int>>(m1, m2);
    cout << "Map: ";
    print(m);

}
