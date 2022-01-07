#include "player_factory.h"
#include "human_player.h"
#include "comp_player.h"

using namespace std;

player_factory::player_factory() {}
player *player_factory::getPlayer(const string &type, const int &id) {
    if (type == "human") {
        return new human_player(id);
    } else if (type == "computer1") {
        return new comp_player(id);
    } else if (type == "computer2") {
        return new comp_player(id);
    } 

    return nullptr;
}
