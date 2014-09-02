#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;
class matr{
    int rows;
    int columns;
    float **fData;

    friend istream &operator>>(istream&, matr& );
    friend ostream &operator<<(ostream&, matr& );
public:
    matr(int = 1, int = 1);
    ~matr();
    matr(const matr& rvalue);
    void setMatrix(int, int, float);
    void fillMatrix();
    void getMatrix();

    matr operator-(const matr&)const;
    matr operator+(const matr&)const;
   // matr operator*(int&);
    matr operator*(const matr&)const;
};

#endif // MATRIX_H
