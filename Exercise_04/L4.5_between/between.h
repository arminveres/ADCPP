#ifndef BETWEEN_H
#define BETWEEN_H

#include <algorithm>
#include <iterator>

template <typename Iter>
bool __between(Iter first, Iter last, Iter item, std::forward_iterator_tag) {
    Iter curr = first;	
    while (curr != item) {
	if (curr == last) return false;
	++curr;
    }
    return true; 
}

template <typename Iter>
bool __between(Iter first, Iter last, Iter item, std::random_access_iterator_tag) {
    return item <= last && item >= first; 
}

template<typename Iter>
bool between(Iter first, Iter last, Iter item) {
    typedef typename std::iterator_traits<Iter>::iterator_category category;
    return __between(first, last, item, category());
}

#endif
