#ifndef H_PIECEPAINTER
#define H_PIECPAINTER

#include <string.h>
#include <vector>
#include <map>
#include "graphics.h"
#include "piecepathloader.h"
#include "config.h"

class PiecePainter
{
    public:
        PiecePainter();
        void paintPiece(int column, int row, PieceType BISHOP, Color pieceColor);

    private:
        Color getColorForCell(int row, int column);
        void loadPiece(const char* image, int diffLin, int diffCol);
        PiecePathLoader piecePathLoader;
};


#endif // H_PIECEPAINTER
