#include <iostream>
#include <cassert>

#include "board.h"
#include "humanplayer.h"

using namespace std;

int main()
{


    Board board;


    board.init();

    /*while(true) {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            cout << x << ' ' << y << endl;
        }
    }*/

    HumanPlayer hp(_WHITE, board);

    /// Aici va fi de fapt inlocuit de un Game.cpp
    while(true) {

       bool couldMove = hp.makeMove(board);
       if(couldMove) {

            cout << "AM REUSIT!!" << endl;
            /// Aici ar fi logica de schimbat jucatorul care e la mutare
       }
       else {
            cout << "Nu am reusit :(" << endl;
       }
    }


    getch();

    closegraph();

    return 0;
}
