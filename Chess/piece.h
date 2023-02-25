#ifndef H_PIECE
#define H_PIECE

#include "config.h"
#include "moveby.h"
#include <vector>
#include <string>
class Piece {

    public:
        Piece(int row, int column, Color color, std::string shortName);

        void setRow(int row);
        int getRow() const;


        void setColumn(int column);
        int getColumn() const;

        void setColor(Color color);
        Color getColor() const;

        virtual void makeMove(int diffRow, int diffColumn);
        virtual bool isValidMove(int diffRow, int diffColumn);
        virtual PieceType getType();
        std::string getShortName();
        std::vector<MoveBy> getValidPositions();
        bool getWasMoved();

    protected:
        int row;
        int column;
        Color color;
        std::string shortName;
        bool wasMoved;
};

#endif // H_PIECE
