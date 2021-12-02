//
// Created by arminveres on 11/4/21.
//

#ifndef COMP_PLAYER_H_
#define COMP_PLAYER_H_

#include "player.h"
#include "playfield_traits.h"

class comp_player : public player {
public:
    int id;
    struct copy_playfield;
    typedef playfield_traits<copy_playfield> T;

    comp_player(int id);
    virtual ~comp_player();
    virtual int play(const playfield &field);
};
#endif // COMP_PLAYER_H_
