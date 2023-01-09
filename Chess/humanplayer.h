#ifndef H_HUMANPLAYER
#define H_HUMANPLAYER

#include "player.h"

class HumanPlayer : public Player
{
    public:
        HumanPlayer(Color color);
        bool getMove(Piece* &piece, int &diffRow, int &diffCol) override;

    private:
        position getPositionClicked();
        int convertCoordinateX(int coord);
        int convertCoordinateY(int coord);
};




#endif // H_HUMANPLAYER
