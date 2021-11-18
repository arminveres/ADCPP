//
// Created by arminveres on 11/4/21.
//

#ifndef ADCPP_GAME_H
#define ADCPP_GAME_H

#include <iostream>
#include <chrono>
#include <thread>

#include "playfield.h"
#include "playfield_traits.h"

template<typename P1, typename P2, typename F=playfield>
struct game {

    F field;
    P1 player1;
    P2 player2;

    int current;

public:

    game(P1 p1, P2 p2) : player1(p1), player2(p2), current(1) {
        play();
    }

    void play() {

        while (playfield_traits<F>::is_not_full(field)) {
            field.print();
	    std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "It is player " << current << "'s turn: ";

            if (current == F::player1) {
                play_round(player1, F::player1);
            }
            else if (current == F::player2) {
                play_round(player2, F::player2);
            }

            std::cout << std::endl;

            if (playfield_traits<F>::has_won(field, current)) {
                field.print();
                std::cout << "Player " << current << " won!" << std::endl;
                return;
            }

            current = playfield_traits<F>::next_player(current);
        }
        std::cout << "It's a draw..." << std::endl;
    }

    template<typename P>
    void play_round(P p, int player) {
        int column = p.play(field);
        field.insert(column, player);
    }
};
#endif //ADCPP_GAME_H
