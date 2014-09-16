#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;
class matr{
    int rows;
    int columns;
    float **fData;

    friend istream &operator>>( istream& stream_in, matr& rvalue );
    friend ostream &operator<<( ostream& stream_out, matr& rvalue );
public:
    matr(int = 1, int = 1);
    ~matr();
    matr(const matr& rvalue);
    void setMatrix( int row, int column, float rvalue );

    matr operator=( const matr& rvalue );
    matr operator-( const matr& rvalue )const;
    matr operator+( const matr& rvalue )const;
    matr operator*(int& multiplier);
    matr operator*( const matr& rvalue )const;
};

#endif // MATRIX_H
