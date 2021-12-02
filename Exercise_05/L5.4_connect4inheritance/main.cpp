#include <iostream>

#include "comp_player.h"
#include "human_player.h"
#include "my_playfield.h"

using namespace std;

typedef playfield_traits<playfield> PT;

int main() {

    auto field = my_playfield();
    auto p1 = human_player(1);
    auto p2 = comp_player(2);

    int current = 1;

    while (PT::is_not_full(field)) {
        field.print();
        std::cout << "It is player " << current << "'s turn: ";

        if (current == playfield::player1) {
            int column = p1.play(field);
            field.insert(column, playfield::player1);
        }
        else if (current == playfield::player2) {
            int column = p2.play(field);
            field.insert(column, playfield::player2);
        }

        std::cout << std::endl;

        if (PT::has_won(field, current)) {
            field.print();
            std::cout << "Player " << current << " won!" << std::endl;
            return 0;
        }

        current = PT::next_player(current);
    }
    std::cout << "It's a draw..." << std::endl;
}
