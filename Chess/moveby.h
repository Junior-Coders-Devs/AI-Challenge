#ifndef H_MOVEBY
#define H_MOVEBY
class MoveBy
{
    public:
        MoveBy();

        void setDiffRow(int diffRow);
        int getDiffRow() const;

        void setDiffColumn(int diffColumn);
        int getDiffColumn() const;

    private:
        int diffRow;
        int diffColumn;
};


#endif // H_MOVEBY
