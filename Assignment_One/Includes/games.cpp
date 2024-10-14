//
// Created by Jacob on 2024-10-13.
//

#include "games.h"



// Blackjack
// Deal a rand card
inline int dealCard() {
    return rand() % 11 + 1;
}

inline void showHand(const std::string& name, int handTotal) {
    printf("the %c is %d\n"), name, handTotal;
}

inline int dealersPlay() {
    int dealersHand = dealCard() + dealCard();
    showHand("Dealers Hand", dealersHand);

    while (dealersHand < 17) {
        int cardPulled = dealCard();
        dealersHand += cardPulled;
        printf("dealer pulled a %d", cardPulled);
        showHand("Dealers Hand", dealersHand);
    }
    return dealersHand;
}

inline int playersPlay() {
    int playersHand = dealCard() + dealCard();
    char choiceInput;

    showHand("Player's Hand", playersHand);

    while (playersHand< 21) {
        printf("hit (h) or stand (s)?\n");
        scanf(" %c", &choiceInput);

        if (choiceInput == 'h') {
            int newCard = dealCard();
            playersHand += newCard;
            printf("You drew: %d\n", newCard);
            showHand("Player", playersHand);
        } else if (choiceInput == 's') {
            break;
        }
    }

    return playersHand;
}

inline int winnerValidation(int dealerTotal, int playerTotal, int playerWager) {
    if (dealerTotal > 21) {
        printf("Dealer Busts!, You win!\n");
        playerWager += playerWager;
    } else if (playerTotal > 21) {
        printf("Player Busts!, You lose!\n");
        playerWager = 0;
    } else if (dealerTotal > playerTotal) {
        printf("Dealer Wins!\n");
        playerWager = 0;
    } else if (dealerTotal < playerTotal) {
        printf("Player Wins!\n");
        playerWager += playerWager;
    } else {
        printf("its a push!\n");
    }

    return playerWager;
}

inline void PlayBlackJack(Player &player, int playerWager) {

    int playerTotal = playersPlay();

    if (playerTotal <= 21) {
        int dealerTotal = dealersPlay();
        winnerValidation(dealerTotal, playerTotal, playerWager);
    } else {
        printf("Dealer wins!\n");
    }

}

// roulette!

inline void PlayRoulette(Player &player, int playerWager) {

    int playersNumber = 0;

    while (true) {
        playersNumber = 0;
        printf("please pick a number between 1 and 36\n");
        scanf(" %d", &playersNumber);
        if (playersNumber < 36 && playersNumber > 1) {break;}
        printf("ERROR!, Invaid number please try again!");
    }

    int houseNumber = rand() % 1 + 36;

    if (playersNumber == houseNumber) {
        printf("It landed on %d You win!\n", houseNumber);
        playerWager = playerWager * 35;
    } else {
        printf("It landed on %d You lose!\n", houseNumber);
    }
}

// Craps

inline void PlayCraps(Player &player, int playerWager) {

    int playersNumber = 0;

    while (true) {
        playersNumber = 0;
        printf("please pick a number between 1 and 12\n");
        scanf(" %d", &playersNumber);
        if (playersNumber < 12 && playersNumber > 1) {break;}
        printf("ERROR!, Invaid number please try again!");
    }

    int houseNumber = rand() % 1 + 12;

    if (playersNumber == houseNumber) {
        printf("It landed on %d You win!\n", houseNumber);
        playerWager = playerWager * 12;
    } else {
        printf("It landed on %d You lose!\n", houseNumber);
    }
}