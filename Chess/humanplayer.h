#ifndef H_HUMANPLAYER
#define H_HUMANPLAYER

#include "player.h"

class HumanPlayer : public Player
{
    public:
        HumanPlayer(Color color);
        bool getMove(Piece* &piece, Piece* &enemyPiece, int &diffRow, int &diffCol, position &startPosition, bool &Taken) override;

    private:
        position getPositionClicked();
        int convertCoordinateX(int coord);
        int convertCoordinateY(int coord);
};




#endif // H_HUMANPLAYER
