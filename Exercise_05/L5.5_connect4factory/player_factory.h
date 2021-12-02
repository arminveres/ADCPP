#ifndef PLAYER_FACOTRY_H_
#define PLAYER_FACOTRY_H_

#include <string>
#include "player.h"

class player_factory {
public:
    player_factory();
    player *getPlayer(const std::string &type, const int &id);

};

#endif
