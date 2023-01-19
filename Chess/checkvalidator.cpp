#include "checkvalidator.h"
#include "moveby.h"
#include <iostream>

CheckValidator::CheckValidator(){};

bool CheckValidator::isCheckPosition(int row, int column, Color player)
{
    Board* board = Board::getInstance();
    Color enemyColor;
    if(player==_WHITE)
        enemyColor=_BLACK;
    else enemyColor=_WHITE;
    std::vector<Piece*>enemy = board->getPieces(enemyColor);
    int size=enemy.size();
    for(auto piece:enemy)
    {
        std::vector<MoveBy>validPositions=piece->getValidPositions();
        for(auto moves:validPositions)
        {
            int enemyRow=piece->getRow()+moves.getDiffRow();
            int enemyColumn=piece->getColumn()+moves.getDiffColumn();
            if(enemyRow==row && enemyColumn==column)
                return true;
        }
    }
    return false;
}

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
    if(CheckValidator::isCheckPosition(piece->getRow(),piece->getColumn(),piece->getColor()))
        std::cout<<"Sah, muta regele "<<piece->getColor()<<'\n';
    ///Need every valid move
    ///To be done as the last task
}

void CheckValidator::isCheckMate(Color playerToMove)
{
    Board* board = Board::getInstance();
    std::vector<Piece*>pieces = board->getPieces(playerToMove);
    Piece* piece;
    int size=pieces.size();
    for(int i=0;i<size;i++)
        if(pieces[i]->getType()==KING)
        {
            piece=pieces[i];
            break;
        }
    std::vector<MoveBy>validPositions=piece->getValidPositions();
    int cnt=validPositions.size();
    for(auto moves:validPositions)
    {
        int row=moves.getDiffRow()+piece->getRow();
        int column=moves.getDiffColumn()+piece->getColumn();
        if(isCheckPosition(row,column,piece->getColor()))
            cnt--;
    }
    if(cnt==0)
        std::cout<<"Checkmate!! "<<piece->getColor()<<" a pierdut!";
    else
        std::cout<<"Nu e checkmate!!";
}
