#ifndef FINDIF_H
#define FINDIF_H

template<typename Iter, typename T>
Iter find(Iter begin, Iter beyond, const T &x) {
    while ((begin != beyond) && (*begin != x)) {
    ++begin;
    }
    return begin;
}

template<typename Iter, typename Pred>
Iter find_if(Iter begin, Iter beyond, Pred pred) {
    while (begin != beyond) {
        if (pred(*begin)) {
        break;
        }
        ++begin;
    }
    return begin;
}

#endif
