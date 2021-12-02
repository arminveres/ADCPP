#ifndef MERGECONTS_TRAITS_H
#define MERGECONTS_TRAITS_H

#include <forward_list>

template<typename T, typename C>
struct merge_traits {
    void static mergec(C& cont, const T& item) {
        cont.insert(cont.end(), item);
    }
};

template<typename T>
struct merge_traits<std::forward_list<T>, T> {
static void mergec(std::forward_list<T> &l, const T t) {
    l.push_front(t);
}
};

#endif
