#include "checkvalidator.h"


CheckValidator::CheckValidator(){};

void CheckValidator::isCheck(Color player)
{
    Board* board = Board::getInstance();
    std::vector<Piece*>pieces = board->getPieces(player);
    Piece* piece;
    int size=pieces.size();
    for(int i=0;i<size;i++)
        if(pieces[i]->getType()==KING)
        {
            piece=pieces[i];
            break;
        }
    Color enemyColor;
    if(player==_WHITE)
        enemyColor=_BLACK;
    else enemyColor=_WHITE;
    std::vector<Piece*>enemy = board->getPieces(enemyColor);
    size=enemy.size();
    ///Need every valid move
    ///To be done as the last task
}

void CheckValidator::isCheckMate(Color playerToMove)
{
    ///Same as last task
}
