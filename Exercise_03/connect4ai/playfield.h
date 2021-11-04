//
// Created by arminveres on 11/4/21.
//

#ifndef ADCPP_PLAYFIELD_H
#define ADCPP_PLAYFIELD_H

#include "string"

#include "playfield_traits.h"

class playfield {
public:
    const static int width=7;
    const static int height=6;

    const static char none=0;
    const static char player1=1;
    const static char player2=2;

    char rep[playfield::width][playfield::height]{};

    playfield();

    int stoneat(int x, int y)  const;
    std::string stone_repr(int x, int y) const;
    void insert(int x, int player);
    void print() const;
};


#endif //ADCPP_PLAYFIELD_H
