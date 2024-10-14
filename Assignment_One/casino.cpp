#include <iostream>
#include <string>
#include "Includes/persistence.h"
#include "Includes/gameController.h"



int main() {
    std::string playerName;

    std::cout << "What is your name?";

    std::getline(std::cin, playerName);

    Player player = createPlayer(playerName, true);

    runMenu(player);


    return 0;
}
