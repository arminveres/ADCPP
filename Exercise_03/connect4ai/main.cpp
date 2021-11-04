//
// Created by arminveres on 11/4/21.
//

#include "game.h"
#include "playfield.h"
#include "human_player.h"

int main() {

    human_player<playfield> p1 = {1};
    human_player<playfield> p2 = {2};

    game<playfield, human_player<playfield>, human_player<playfield>> g(p1, p2);

    return 0;
}
