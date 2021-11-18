#ifndef MERGECONTS_TRAITS_H
#define MERGECONTS_TRAITS_H

template<typename T, typename C>
struct merge_traits {
    void static mergec(C& cont, const T& item) {
        cont.insert(cont.end(), item);
    }
};

#endif
