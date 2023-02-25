#include "player.h"
#ifdef DEBUG_LOGS
#include <iostream>
#endif // DEBUG_LOGS

Player::Player(Color playerColor)
{
    this->playerColor = playerColor;
    moveValidator.setColor(playerColor);
}

bool Player::isCastling(Piece* &firstPiece, Piece* &secondPiece)
{
    if(firstPiece->getWasMoved() || secondPiece->getWasMoved() )
    {
        return false;
    }
    if(!((firstPiece->getShortName()=="R" && secondPiece->getShortName()=="K")||(firstPiece->getShortName()=="K" && secondPiece->getShortName()=="R")))
    {
        return false;
    }
    return true;
}

bool Player::getMove(Piece*& piece, Piece*& enemyPiece, int &diffRow, int &diffCol, position &startPosition, bool &Taken) {}

bool Player::makeMove()
{
    Board* board = Board::getInstance();
    Piece* piece;
    Piece* enemyPiece;
    bool Taken=false;
    History* history= History::getInstance();
    int diffRow = -1, diffCol = -1;
    position startPosition;
    bool ok = getMove(piece, enemyPiece, diffRow, diffCol, startPosition, Taken);
    if(!ok)
        return false;

    if(piece->isValidMove(diffRow, diffCol))
    {
        if(moveValidator.validateMove(diffRow, diffCol, piece->getRow(), piece->getColumn()))
        {
            if(!(moveValidator.getWasCastling()))
            {
                Color pieceColor = board->getColorForCell(piece->getRow(), piece->getColumn());

#ifdef DEBUG_LOGS
                std::cout << "MUT PIESA: " << piece->getType() << ' ' << color << '\n';
                std::cout << "POZITIA ACTUALA: " << piece->getRow() << ' ' << piece->getColumn() << '\n';
#endif // DEBUG_LOGS

                piece->makeMove(diffRow, diffCol);
                history->addMove(piece, startPosition, Taken);

#ifdef DEBUG_LOGS
                std::cout << "POZITIA NOUA: " << piece->getRow() << ' ' << piece->getColumn() << '\n';
#endif // DEBUG_LOGS

                piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());

                int lineIndex = piece->getRow() - diffRow;
                int columnIndex = piece->getColumn() - diffCol;

                Color cellColor = piecePainter.getColorForCell(lineIndex, columnIndex);
                painter.drawEmptySquare(lineIndex, columnIndex, cellColor);

                Color oppositeColor = pieceColor;
                if(pieceColor == _WHITE) oppositeColor = _BLACK;
                else oppositeColor = _WHITE;

#ifdef DEBUG_LOGS
                std::cout << oppositeColor << '\n';
                std::cout << "STERG PIESA DE PE POZITIA " << piece->getRow() << ' ' << piece->getColumn() << '\n';
#endif // DEBUG_LOGS

                board->deletePiece(piece->getRow(), piece->getColumn(), oppositeColor);
                return true;
            }
            else{
                if(diffCol<0){
                    diffCol++;
                }
                else{
                    diffCol--;
                }
                piece->makeMove(diffRow, diffCol);
                history->addMove(piece, startPosition, Taken);
                piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());


                int lineIndex = piece->getRow() - diffRow;
                int columnIndex = piece->getColumn() - diffCol;

                Color cellColor = piecePainter.getColorForCell(lineIndex, columnIndex);
                painter.drawEmptySquare(lineIndex, columnIndex, cellColor);

                if(diffCol<0){
                    diffCol=2;
                }
                else{
                    diffCol=-2;
                }
                enemyPiece->makeMove(diffRow, diffCol);
                piecePainter.paintPiece(enemyPiece->getRow(), enemyPiece->getColumn(), enemyPiece->getType(), enemyPiece->getColor());
                lineIndex = enemyPiece->getRow() - diffRow;
                columnIndex = enemyPiece->getColumn() - diffCol;

                cellColor = piecePainter.getColorForCell(lineIndex, columnIndex);
                painter.drawEmptySquare(lineIndex, columnIndex, cellColor);

                return true;
            }
        }
    }

    return false;
}
