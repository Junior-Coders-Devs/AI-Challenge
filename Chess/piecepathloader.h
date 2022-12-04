#ifndef H_PIECE_PATH_LOADER
#define H_PIECE_PATH_LOADER

#include "config.h"

class PiecePathLoader {

    public:
        PiecePathLoader();
        const char* getPath(Color squareColor, Color pieceColor, PieceType type);

    private:
       const char* getQueenPath(Color squareColor, Color pieceColor);
       const char* getKingPath(Color squareColor, Color pieceColor);
       const char* getKnightPath(Color squareColor, Color pieceColor);
       const char* getPawnPath(Color squareColor, Color pieceColor);
       const char* getRookPath(Color squareColor, Color pieceColor);
       const char* getBishopPath(Color squareColor, Color pieceColor);
};

#endif // H_PIECE_PATH_LOADER
