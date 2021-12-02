//
// Created by arminveres on 11/4/21.
//

#ifndef ADCPP_HUMAN_PLAYER_H
#define ADCPP_HUMAN_PLAYER_H


#include "player.h"
#include "playfield.h"
#include "playfield_traits.h"

struct human_player : public player {
    int id;
    typedef playfield_traits<playfield> T;
public:
    human_player(int id);
    virtual ~human_player();
    virtual int play(const playfield &field);
};
#endif //ADCPP_HUMAN_PLAYER_H
