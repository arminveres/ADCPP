//
// Created by arminveres on 11/4/21.
//

#include <iostream>
#include "my_playfield.h"

using namespace std;

my_playfield::my_playfield() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            rep[i][j] = none;
        }
    }
}

int my_playfield::stoneat(int x, int y) const {
    if (x >= 0 && x < my_playfield::width && y >= 0 && y < my_playfield::height)
        return rep[x][y];
    else
        return none;
}

string my_playfield::stone_repr(int x, int y) const {
    int stone = rep[x][y];
    if (stone == 0)
        return " ";
    else if (stone == 1)
        return "\e[91mx\e[0m";
    else if (stone == 2)
        return "\e[32mx\e[0m";
    return nullptr;
}

void my_playfield::insert(int x, int player) {
    if (playfield_traits<my_playfield>::is_playable(*this, x)) {
        int y = height - 1;
        while (rep[x][y] != none) y--;
        rep[x][y] = player;
    }
}

void my_playfield::print() const {
    cout << "  1   2   3   4   5   6   7" << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << "| " << stone_repr(j,i) << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}
