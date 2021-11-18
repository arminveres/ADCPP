#include <cstdint>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <chrono>

/* #include "findif.h" */

using namespace std;

template<typename E, typename Pred>
void finder(E elem, Pred pred) {
    auto start = chrono::system_clock::now();
//    computation is done between start and end time, useful trick to time computations
    auto elem_iter = find_if(elem.begin(), elem.end(), pred);
    auto end = chrono::system_clock::now();  

    chrono::duration<double> elapsed_seconds = end-start;

    if (elem_iter != elem.end()) {
        cout << "found in " << elapsed_seconds.count() << " seconds" << endl;
    }

}


int main() {
    uint64_t size = 200000001;
    vector<int> collection;
    for (uint64_t i = 0; i < size; ++i) {
        collection.push_back(i);
    }

    for (uint64_t i = 0; i < 5; ++i) {
	finder(collection, [](int elem) {return elem == 200000000;});
    }
    return 0;
}
