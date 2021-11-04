//
// Created by arminveres on 11/4/21.
//

#ifndef ADCPP_COMP_PLAYER_H
#define ADCPP_COMP_PLAYER_H

#include <set>
#include <vector>
#include "playfield.h"
#include "playfield_traits.h"

template<typename F=playfield>
struct comp_player {
    int id;

    struct copy_playfield {
        const static int width = F::width;
        const static int height = F::height;
        const static int player1 = F::player1;
        const static int player2 = F::player2;
        const static int none = F::none;

        char rep[F::width][F::height]{};

        int stoneat(int x, int y) const {
            if (x >= 0 && x < F::width && y >= 0 && y < F::height)
                return rep[x][y];
            else
                return none;
        }

        copy_playfield(const F &field) {
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < height; ++j) {
                    rep[i][j] = field.stoneat(i, j);
                }
            }
        }

        bool copy_insert(int x, int player) {
            if (T::is_playable(*this, x)) {
                int y = height - 1;
                while (rep[x][y] != none) y--;
                rep[x][y] = player;
                return true;
            }
            return false;
        }

        void copy_remove(int x, int player) {
            int y = 0;
            while (rep[x][y] == none)
                ++y;

            if (rep[x][y] == player)
                rep[x][y] = none;
        }

        bool would_win(int x, int player) {
            if (!T::is_playable(*this, x))
                return false;

            copy_insert(x, player);
            bool won = T::has_won(*this, player);
            copy_remove(x, player);
            return won;
        }
    };

    typedef playfield_traits<copy_playfield> T;

public:

    int play(F &field) {
        srand((unsigned) time(0));

        copy_playfield playfield(field);
        int opp_id = T::next_player(id);

        // identify where it can win by placing a stone
        for (int i = 0; i < F::width; ++i) {
            if (playfield.would_win(i, id)) {
                return i;
            }
        }

        // stop opponent from winning
        for (int i = 0; i < F::width; ++i) {
            if (playfield.would_win(i, opp_id))
                return i;
        }

        // identify where we should not place stone because it could help opponent win
        std::vector<int> good_places;
        for (int i = 0; i < F::width; ++i) {
            if (playfield.copy_insert(i, id)) {
                if (!playfield.would_win(i, opp_id))
                    good_places.push_back(i);
                playfield.copy_remove(i, id);
            }
        }

        // identify existing formations that can be extended
        for (int x : good_places) {
            if (playfield.copy_insert(x, id)) {
                bool nice = false;
                for (int y = 0; y < F::height; ++y) {
                    if (playfield.stoneat(x, y) == id && playfield.stoneat(x + 1, y) == id &&
                        field.stoneat(x + 2, y) == id) {
                        nice = true;
                    }
                    if (playfield.stoneat(x, y) == id && playfield.stoneat(x + 1, y + 1) == id &&
                        field.stoneat(x + 2, y + 2) == id) {
                        nice = true;
                    }
                    if (playfield.stoneat(x, y) == id && playfield.stoneat(x, y + 1) == id &&
                        field.stoneat(x, y + 2) == id) {
                        nice = true;
                    }
                    if (playfield.stoneat(x, y) == id && playfield.stoneat(x - 1, y - 1) == id &&
                        field.stoneat(x - 2, y - 2) == id) {
                        nice = true;
                    }
                }
                if (nice) return x;
            }
        }

        int rand_index = std::rand() % good_places.size();
        return good_places.at(rand_index);
    }
};
#endif //ADCPP_COMP_PLAYER_H
