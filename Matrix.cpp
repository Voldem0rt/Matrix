#include <iostream>
#include <Matrix.h>
using namespace std;

matr::matr(int x, int y){
    if( !x || !y ){
        x = 1; y = 1;}
    if( x == 0 || y == 0 ){
        x = 1; y = 1;
    }
    rows = x;
    columns = y;
    fData = new float* [rows];
    for(int i = 0; i < rows; ++i)
        fData[i] = new float[columns];
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
            fData[i][j] = 0;
    }
}

matr::~matr(){
    for(int i = 0; i < rows; ++i)
        delete fData[i];
    delete []fData;
}

matr::matr(const matr& rvalue){
    float** fData;
    rows = rvalue.rows;
    columns = rvalue.columns;
    fData = new float* [rows];
    for(int i = 0; i < rows; ++i)
        fData[i] = new float[columns];
    for(int i = 0; i < rvalue.rows; ++i){
        for(int j = 0; j < rvalue.columns; ++j)
            fData[i][j] = rvalue.fData[i][j];
    }
}

matr matr::operator=(const matr& rvalue){
        float** new_matrix = new float*[rvalue.rows];
        for(int i = 0; i < rvalue.rows; ++i)
            new_matrix[i] = new float[rvalue.columns];
        copy(rvalue.fData, rvalue.fData + rvalue.rows + rvalue.columns, new_matrix);
        for(int i = 0; i < rvalue.rows; ++i)
            delete fData[i];
        delete []fData;
        fData = new_matrix;
        rows = rvalue.rows;
        columns = rvalue.columns;
    return (*this);
}
/*
void matr::setMatrix(int x, int y, float data){
    if( x < 0 || x > rows )
        x = 0;
    if( y < 0 || y > columns )
        y = 0;
    fData[x][y] = data;
}
*/
matr matr::operator+(const matr& rvalue)const{
    matr temp(*this);              // temporary matrix;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
    temp.fData[i][j] = temp.fData[i][j] + rvalue.fData[i][j];
    }
    return temp;
}

matr matr::operator-(const matr& rvalue)const{
    matr temp(*this);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
            temp.fData[i][j] = temp.fData[i][j] - rvalue.fData[i][j];
    }
    return temp;
}
/*
matr matr::operator*(int& n){
    matr temp(*this);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
            temp.fData[i][j] = temp.fData[i][j] * n;
    }
    return temp;
}
*/
matr matr::operator*(const matr& rvalue)const{
    matr temp(*this);
    matr temp1(rows, columns);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
            temp1.fData[i][j] = 0;
    }
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            for(int k = 0; k < columns; ++k)
                temp1.fData[i][j] = temp1.fData[i][j] + temp.fData[i][k] * rvalue.fData[k][j];
        }
    }
    return temp1;
}
/*
void matr::fillMatrix(){
    cout << "Enter elements of matrix: " << endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
            cin >> fData[i][j];
        cout << endl;
    }

}

void matr::getMatrix(){
    cout << "Matrix is: " << endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j)
            cout << fData[i][j] << " ";
        cout << endl;
    }
}
*/
istream &operator>>(istream& stream_in, matr& rvalue){
    cout << "Enter elements of matrix: " << endl;
    for(int i = 0; i < rvalue.rows; ++i){
        for(int j = 0; j < rvalue.columns;++j)
            stream_in >> rvalue.fData[i][j];
        cout << endl;
    }
    return stream_in;
}

ostream &operator<<(ostream& stream_out, matr& rvalue ){
    cout << "Matrix is: " << endl;
    for(int i = 0; i < rvalue.rows; ++i){
        for(int j = 0; j < rvalue.columns;++j)
            stream_out << rvalue.fData[i][j];
        cout << endl;
    }
    return stream_out;
}

