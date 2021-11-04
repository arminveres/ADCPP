//
// Created by arminveres on 11/4/21.
//

#include "game.h"
#include "comp_player.h"

#include "playfield.h"
#include "human_player.h"

int main() {

    human_player<> p1 = {1};
    human_player<> p2 = {2};
    game<human_player<>, human_player<>> g(p1, p2);

//    comp_player<> cp1 = {1};
//    comp_player<> cp2 = {2};
//    game<comp_player<>, comp_player<>> g(cp1, cp2);

    return 0;
}
