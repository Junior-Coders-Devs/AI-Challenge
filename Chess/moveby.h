#ifndef H_MOVEBY
#define H_MOVEBY

class MoveBy
{
    public:
        MoveBy(int diffRow, int diffColumn);

        void setDiffRow(int diffRow);
        int getDiffRow() const;

        void setDiffColumn(int diffColumn);
        int getDiffColumn() const;

        bool operator == (MoveBy & a) const
        {
            return (a.diffRow == diffRow && a.diffColumn == diffColumn);
        }

    private:
        int diffRow;
        int diffColumn;
};


#endif // H_MOVEBY

