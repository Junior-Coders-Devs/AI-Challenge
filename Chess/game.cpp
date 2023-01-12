#include "game.h"

#ifdef DEBUG_LOGS
#include <iostream>
#endif // DEBUG_LOGS

Game::Game() {};


void Game::start()
{
    bool isGameOpen = true;

    std::vector<Player*> players(2);

    players[0] = new HumanPlayer(_WHITE);
    players[1] = new HumanPlayer(_BLACK);

    int playerIndex = 0;

    while(isGameOpen)
    {
        bool prepareMove = 1;

        while(prepareMove)
        {
            bool couldMove = 0;
            couldMove = players[playerIndex % 2]->makeMove();

            if(couldMove) {
                prepareMove = false;
#ifdef DEBUG_LOGS
                std::cout << "AM REUSIT!!" << std::endl;
#endif // DEFINE_LOGS
            }
            else {
#ifdef DEBUG_LOGS
                std::cout << "Nu am reusit :(" << std::endl;
#endif // DEBUG_LOGS
            }
        }

        playerIndex++;
    }
}
