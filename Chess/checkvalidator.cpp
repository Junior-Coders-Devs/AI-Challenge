#include "checkvalidator.h"
#include "moveby.h"
#include <iostream>

CheckValidator::CheckValidator(){};

bool isNotOccupied(int row, int column, Color player)
{
    Board* board = Board::getInstance();
    std::vector<Piece*>ally = board->getPieces(player);
    for(auto piece:ally)
        if(piece->getRow()==row && piece->getColumn()==column)
            return false;
    return true;
}

bool CheckValidator::isCheckPosition(int row, int column, Color player)
{
    Color enemyColor;
    if(player==_WHITE)
        enemyColor=_BLACK;
    else
        enemyColor=_WHITE;
    Board* board = Board::getInstance();
    std::vector<Piece*>enemy = board->getPieces(enemyColor);
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
    Color enemyColor;
    if(player==_WHITE)
        enemyColor=_BLACK;
    else
        enemyColor=_WHITE;
    Board* board = Board::getInstance();
    std::vector<Piece*>pieces = board->getPieces(enemyColor);
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
}

void CheckValidator::isCheckMate(Color playerToMove)
{
    Color enemyColor;
    if(playerToMove==_WHITE)
        enemyColor=_BLACK;
    else
        enemyColor=_WHITE;
    Board* board = Board::getInstance();
    std::vector<Piece*>pieces = board->getPieces(enemyColor);
    Piece* piece;
    int size=pieces.size();
    for(int i=0;i<size;i++)
        if(pieces[i]->getType()==KING)
        {
            piece=pieces[i];
            break;
        }
    std::vector<MoveBy>validPositions=piece->getValidPositions();
    int cnt=validPositions.size() + 1;
    if(isCheckPosition(piece->getRow(), piece->getColumn(), piece->getColor()))
        cnt--;

    for(auto moves:validPositions)
    {

        int row=piece->getRow()+moves.getDiffRow();
        int column=piece->getColumn()+moves.getDiffColumn();
        if((isCheckPosition(row,column,piece->getColor()) && isNotOccupied(row,column,piece->getColor())) || !isNotOccupied(row,column,piece->getColor()))
            cnt--;
    }
    if(cnt==0)
        std::cout<<"Checkmate!! "<<piece->getColor()<<" a pierdut!\n";
    else
        std::cout<<"Nu e checkmate!!\n";
}
