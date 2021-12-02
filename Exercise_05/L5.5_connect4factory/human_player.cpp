#include <iostream>

#include "human_player.h"

human_player::human_player(int id) : id(id) {};

human_player::~human_player() {};

int human_player::play(const playfield &field) {
    int column;
    for (;;) {
        std::cin >> column;
        if (T::is_playable(field, column-1)) {
            return column-1;
        }
        else {
            std::cout << "Wrong input. Try again: ";
        }
    }
}
