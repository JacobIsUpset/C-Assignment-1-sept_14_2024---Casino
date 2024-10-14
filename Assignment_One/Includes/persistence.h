//
// Created by Jacob on 2024-10-13.
//

#ifndef PERSISTENCE_H
#define PERSISTENCE_H
#include <string>

class persistence {

};

struct Player {
    std::string name;
    int coins;
};

Player createPlayer(const std::string &name, int coins);

#endif //PERSISTENCE_H