//
// Created by Jacob on 2024-10-13.
//

#include "gameController.h"
#include "games.cpp"

#include <iostream>

inline void wagerToBalance(Player& player, int playerWager) {
    player.coins += playerWager;
    if (player.coins <= 0) {
        player.coins = 100;
    }
}

inline int playerWagerValadation(int playerWager) {
    while (true) {
        playerWager = 0;
        printf("how many coins do you want to wager?\n");
        scanf("%d", &playerWager);
        if (playerWager <= 10 && playerWager >= 1){break;}
        printf("ERROR!, wagers can only be from 1 - 10, Please enter number Again:\n");
    }
    return playerWager;
}

void runMenu(Player player) {
    int choice = 0;
    while (true) {
        std::cout << "Blackjack - 1\n";
        std::cout << "Roulette - 2\n";
        std::cout << "Craps - 3\n";
        std::cout << "quit - 4\n";

        while (true) {
            scanf("%d", &choice);
            if (choice <= 4 || choice >= 0) {
                break;
            }
            printf("ERROR!, Please enter number Again:\n");
        }

        int playerWager = 0;

        if (choice == 1) {
            playerWagerValadation(playerWager);
            PlayBlackJack(player, playerWager);
            wagerToBalance(player, playerWager);
        } else if (choice == 2) {
            playerWagerValadation(playerWager);
            PlayRoulette(player, playerWager);
            wagerToBalance(player, playerWager);
        }else if (choice == 3) {
            playerWagerValadation(playerWager);
            PlayCraps(player, playerWager);
            wagerToBalance(player, playerWager);

        } else if (choice == 4) {
            std::cout << "good bye!\n";
            break;
        }
    }
}