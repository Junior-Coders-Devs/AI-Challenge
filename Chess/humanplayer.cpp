#include "humanplayer.h"


HumanPlayer::HumanPlayer(Color playerColor) : Player(playerColor) {}


bool HumanPlayer::getMove(Piece* &piece, Piece* &enemyPiece, int &diffRow, int &diffCol, position &startPosition, bool &Taken)
{
    Board* board = Board::getInstance();

    position humanPosition = getPositionClicked();

    piece = board->getPieceForPosition(humanPosition.row, humanPosition.column);

    if(piece == NULL)
        return 0;

    if(piece->getColor() != playerColor)
        return 0;

    position targetPosition = getPositionClicked();

    diffRow = targetPosition.row - humanPosition.row;
    diffCol = targetPosition.column - humanPosition.column;

    enemyPiece = board->getPieceForPosition(targetPosition.row, targetPosition.column);

    if(enemyPiece != NULL && (enemyPiece->getColor() == piece->getColor() && !(isCastling(piece, enemyPiece))))
        return 0;
    startPosition = humanPosition;
    if(enemyPiece != NULL){
        Taken = true;
    }
    return 1;
}


position HumanPlayer::getPositionClicked()
{
    int kind = WM_LBUTTONDOWN;
    int row = -1, column = -1;

    while(!ismouseclick(kind));
    getmouseclick(kind, row, column);

    position pos =
    {
        convertCoordinateX(column),
        convertCoordinateY(row)
    };

    return pos;
}

int HumanPlayer::convertCoordinateX(int coord)
{
    return 9 - ((coord - 30) / SQUARE_SIZE);
}

int HumanPlayer::convertCoordinateY(int coord)
{
    return (coord - 30) / SQUARE_SIZE;
}
