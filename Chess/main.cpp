#include <iostream>
#include <cassert>

#include "board.h"
#include "humanplayer.h"
#include "game.h"

using namespace std;

int main()
{

    Board * board = Board::getInstance();

    board->init();

    Game * game = new Game;

    game->start();

    getch();

    closegraph();

    return 0;
}
