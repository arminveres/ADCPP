#include <iostream>

#include "comp_player.h"
#include "human_player.h"
#include "my_playfield.h"
#include "player_factory.h"

using namespace std;

typedef playfield_traits<playfield> PT;

void run(player *p1, player *p2) {
    auto field = my_playfield();
    /* auto p1 = human_player(1); */
    /* auto p2 = comp_player(2); */

    int current = 1;

    while (PT::is_not_full(field)) {
        field.print();
        std::cout << "It is player " << current << "'s turn: ";

        if (current == playfield::player1) {
            int column = p1->play(field);
            field.insert(column, playfield::player1);
        }
        else if (current == playfield::player2) {
            int column = p2->play(field);
            field.insert(column, playfield::player2);
        }

        std::cout << std::endl;

        if (PT::has_won(field, current)) {
            field.print();
            std::cout << "Player " << current << " won!" << std::endl;
	    return;
        }

        current = PT::next_player(current);
    }
    std::cout << "It's a draw..." << std::endl;

}

int main() {
    string inp;
    player_factory pf;
    cout << "enter who should play player 1: human or computer\ninput: ";
    cin >> inp;
    player *p1 = pf.getPlayer(inp, 1);
    cout << "enter who should play player 2: human or computer\ninput: ";
    cin >> inp;
    player *p2 = pf.getPlayer(inp, 2);

    run(p1, p2);
}

