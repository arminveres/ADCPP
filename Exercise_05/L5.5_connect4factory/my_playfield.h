#ifndef MY_PLAYFIELD_H_
#define MY_PLAYFIELD_H_

#include <string>

#include "playfield.h"
#include "playfield_traits.h"

class my_playfield : public playfield {
public:
    typedef playfield_traits<my_playfield> T;
    char rep[width][height]{};
    my_playfield();

    virtual int stoneat(int x, int y) const override;
    void insert(int x, int player);
    void print() const;
    std::string stone_repr(int x, int y) const;
};


#endif // MY_PLAYFIELD_H_
