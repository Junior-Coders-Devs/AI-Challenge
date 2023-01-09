#include <iostream>
#include <cassert>

#include "board.h"
#include "humanplayer.h"

using namespace std;

int main()
{


    Board* board = Board::getInstance();

    board->init();

    Player*  hp = new HumanPlayer(_WHITE);

    /// Aici va fi de fapt inlocuit de un Game.cpp
    while(true) {

       bool couldMove = hp->makeMove();
       if(couldMove) {

#ifdef DEBUG_LOGS
            cout << "AM REUSIT!!" << endl;
#endif // DEFINE_LOGS
            /// Aici ar fi logica de schimbat jucatorul care e la mutare
       }
       else {
#ifdef DEBUG_LOGS
            cout << "Nu am reusit :(" << endl;
#endif // DEBUG_LOGS
       }

    }

    getch();

    closegraph();

    return 0;
}
