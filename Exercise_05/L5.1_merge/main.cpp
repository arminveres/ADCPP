#include <iostream>
#include <vector>
#include <set>
#include <map>

#include "mergecont.h"

using namespace std;



int main() {
    cout << "merging vectors" << endl;
    vector<int> con1 = {1,3,5};
    vector<int> con2 = {2,4,6};
    vector<int> res;
    mergecont(con1, con2, res);
    cout << "vector: ";
    print(res);

/* so using the merge_w_back with sets doesn't work, since it uses pushback */    
    cout << "merging sets" << endl;
    set<int> con11 = {1,3,5};
    set<int> con21 = {2,4,6};
    set<int> res2;
    mergecont(con11, con21, res2);
    cout << "set: ";
    print(res2);

    cout << "merging vector and set into vector" << endl;
    vector<int> setmix;
    mergecont(con1, con21, setmix);
    cout << "set into vector: ";
    print(setmix);

    cout << "merging maps" << endl;
    map<int, int> m1 = {{1,10}, {2,20}, {3,30}};
    map<int, int> m2 = {{3,30}, {4,40}, {5,50}};

    map<int, int> m;
    mergecont(m1, m2, m);
    cout << "Map: ";
    print(m);

}
