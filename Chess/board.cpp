#include "board.h"

Board::Board() {}

void Board::init()
{
    initMapPieces();
    painter.initializeWindow();
    painter.initializeBoard();
    painter.initializePieces();
}

std::vector<Piece*> Board::getPieces(Color color)
{
    return pieces[color];
}

void Board::initMapPieces()
{
    initByColor(_WHITE);
    initByColor(_BLACK);
}

void Board::initByColor(Color color)
{
    int firstRow = 0, secondRow = 0;
    if(color == _WHITE)
        firstRow = 1, secondRow = 2;
    else if(color == _BLACK)
        firstRow = 8, secondRow = 7;

    for(int i = 1; i <= 8; ++i)
    {
        switch(i)
        {
        case 1:case 8:
        {
            Rook * rook = new Rook(firstRow, i);
            pieces[color].push_back(rook);
            break;
        }
        case 2:case 7:
        {
            Knight * knight = new Knight(firstRow, i);
            pieces[color].push_back(knight);
            break;
        }
        case 3:case 6:
        {
            Bishop * bishop = new Bishop(firstRow, i);
            pieces[color].push_back(bishop);
            break;
        }
        case 4:
        {
            Queen * queen = new Queen(firstRow, i);
            pieces[color].push_back(queen);
            break;
        }
        case 5:
        {
            King * king = new King(firstRow, i);
            pieces[color].push_back(king);
            break;
        }
        default:
            break;
        }
    }
    for(int i = 1; i <= 8; ++i)
    {
        Pawn * pawn = new Pawn(secondRow, i);
        pieces[color].push_back(pawn);
    }
}
