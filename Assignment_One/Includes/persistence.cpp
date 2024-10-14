//
// Created by Jacob on 2024-10-13.
//

#include "persistence.h"
#include <string>



Player createPlayer(const std::string &name, int coins) {
    Player player;
    player.name = name;
    player.coins = coins;
    return player;
}