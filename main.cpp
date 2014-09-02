#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    matr a(2, 2), b(2, 2);
    //a.fillMatrix();
    //a.getMatrix();
    //b.fillMatrix();
    //b.getMatrix();
    //cout << endl;
    /*
    (a - b).getMatrix();
    cout << endl;
    (a + b).getMatrix();
    cout << endl;
    (a * b).getMatrix();*/
    //int n = 4;
    //(a * n).getMatrix();
    //a.~matr();
    //b.~matr();
    matr s(2, 2);
    cin >> a;
    cin >> b;
    cout << a;
    cout << b;
    //s = a + b;
    //(a*b).getMatrix();
    a = a + b;
    cout << a;
   // cout << m;
    //(a - b).getMatrix();
    //cout << s << endl;
    //cout << a << endl;
    //cout << m << endl;
    //(a * b).getMatrix();
    return 0;
}

