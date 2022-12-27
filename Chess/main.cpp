#include <iostream>
#include <cassert>

#include "board.h"
#include "humanplayer.h"

using namespace std;

int main()
{


    Board board;


    board.init();

    HumanPlayer hp(_WHITE, board);

    getch();

    hp.makeMove(board);

    return 0;
}
