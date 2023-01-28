#ifndef H_GAME
#define H_GAME

#include "humanplayer.h"
#include <vector>

class Game
{

public:
    Game();
    void start();

private:
    Board * board;
    std::vector<Player*> players{2};

    void initializePlayers();
    void init();
};



#endif // H_GAME
