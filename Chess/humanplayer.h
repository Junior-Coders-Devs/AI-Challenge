#ifndef H_HUMANPLAYER
#define H_HUMANPLAYER

#include "player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(Color color, Board board);
    void makeMove(Board board);
    bool isValidMove(element humanPiece, element enemyPiece, Board board, Color color);
};




#endif // H_HUMANPLAYER
