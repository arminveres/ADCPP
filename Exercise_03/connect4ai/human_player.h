//
// Created by arminveres on 11/4/21.
//

#ifndef ADCPP_HUMAN_PLAYER_H
#define ADCPP_HUMAN_PLAYER_H

#include <iostream>
#include "playfield_traits.h"

template<typename F>
struct human_player {
    int id;

public:

    int play(const F &field) {
        int column;
        for (;;) {
            std::cin >> column;
            if (playfield_traits<F>::is_playable(field, column-1)) {
                return column-1;
            }
            else {
                std::cout << "Wrong input. Try again: ";
            }
        }
    }
};
#endif //ADCPP_HUMAN_PLAYER_H
