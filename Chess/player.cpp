#include "player.h"


void Player::makeMove(Board board){};



Player::Player(Color color, Board board)
{
    this->color = color;
    moveValidator.setBoard(board);
    moveValidator.setColor(color);
}

int Player::convertCoordinateX(int coord)
{
    return 9 - ((coord - 30) / SQUARE_SIZE);
}

int Player::convertCoordinateY(int coord)
{
    return (coord - 30) / SQUARE_SIZE;
}

bool Player::checkForSamePiece(int row, int column, Board board, Color color)
{
    std::vector <Piece*> myPieces = board.getPieces(color);

    bool ok = 0;

    for(int pieceIndex = 0;pieceIndex < myPieces.size(); ++pieceIndex)
    {
        int boardRow = myPieces[pieceIndex]->getRow();
        int boardColumn = myPieces[pieceIndex]->getColumn();
        ok |= (boardRow == row && boardColumn == column);
    }
    return ok;
}

bool Player::checkForEnemyPiece(int row, int column, Board board, Color color)
{
    if(color == _WHITE)
        color = _BLACK;
    else color = _WHITE;

    std::vector <Piece*> myPieces = board.getPieces(color);

    bool ok = 0;

    for(int pieceIndex = 0;pieceIndex < myPieces.size(); ++pieceIndex)
    {
        int boardRow = myPieces[pieceIndex]->getRow();
        int boardColumn = myPieces[pieceIndex]->getColumn();
        ok |= (boardRow == row && boardColumn == column);
    }
    return ok;
}
