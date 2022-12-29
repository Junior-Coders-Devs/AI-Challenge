#ifndef H_HUMANPLAYER
#define H_HUMANPLAYER

#include "player.h"

class HumanPlayer : public Player
{
    public:
        HumanPlayer(Color color, Board board);
        void getMove(Board board);
        void getMove(Board board, Piece* &piece, int &diffRow, int &diffCol);
        bool isValidMove(position humanPiece, position enemyPiece, Board board, Color color);

    private:
        void waitForClick(int kind, int &row, int &column);
};




#endif // H_HUMANPLAYER
