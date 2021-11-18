#ifndef RANGE_H
#define RANGE_H

#include <cstddef>
#include <cstdlib>
#include <vector>


class rangerIter {
    int curr;

public:
    rangerIter(const int &i) : curr(i)
    {}
    int operator* () {
        return this->curr;
    }
    rangerIter& operator++() {
        ++curr;
        return *this;
    }
    /* compiler complained that this was missing */
    bool operator!= (const rangerIter& it) {
        return this->curr != it.curr;
    }
};

// Actually I don't need to make this applicable for any type...
class range {
    int start;
    int ending;

public:
    range(const int &instart, const int &inend) : start(instart), ending(inend)
    {
    }
    // I need an iterator, e.g. over an array/vector with this numbers, which then can be returned to
    // user
    
    // it doesn't even need an operator only a return of begin and end
    /* void operator() (const int &start, const int &end) { */
    /*     return; */
    /* } */
    rangerIter begin() {
        return rangerIter(start);
    }
    rangerIter end() {
        return rangerIter(ending+1);
    }
};


#endif
