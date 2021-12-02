#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "playfield.h"

class player {
public:
    virtual int play(const playfield &field) = 0;
    virtual ~player() {}
};

#endif
