#include <iostream>
#include "../Mtmchkin.h"

int main() {

    try {
        Mtmchkin game("../deck.txt");
        while(!game.isGameOver())
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (std::exception& error) {
        std::cerr << error.what() << std::endl;
    }
    return 0;
}
