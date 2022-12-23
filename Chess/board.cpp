#include "board.h"

Board::Board() {}

void Board::init() {
    initMapPieces();
    painter.initializeWindow();
    painter.initializeBoard();
    painter.initializePieces();
}

std::map<Color, std::vector<Piece*>> Board::getPieces()
{
    return pieces;
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

    for(int i = 1;i <= 8; ++i)
    {
        if(i == 1 || i == 8)
        {
            Rook * rook = new Rook(firstRow, i);
            pieces[color].push_back(rook);
        }
        if(i == 2 || i == 7)
        {
            Bishop * bishop = new Bishop(firstRow, i);
            pieces[color].push_back(bishop);
        }
        if(i == 3 || i == 6)
        {
            Knight * knight = new Knight(firstRow, i);
            pieces[color].push_back(knight);
        }
        if(i == 4)
        {
            Queen * queen = new Queen(firstRow, i);
            pieces[color].push_back(queen);
        }
        if(i == 5)
        {
            King * king = new King(firstRow, i);
            pieces[color].push_back(king);
        }
    }
    for(int i = 1;i <= 8; ++i)
    {
        Pawn * pawn = new Pawn(secondRow, i);
        pieces[color].push_back(pawn);
    }
}
