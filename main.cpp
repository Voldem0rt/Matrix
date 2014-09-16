#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    matr a(4, 4), b(4, 4);
    matr m(4, 4), s(4, 4), d(4, 4);
    cin >> a;
    cin >> b;
    cout << a;
    cout << b<< endl;
    int factor;
    m = a * b;
    s = a + b;
    d = a - b;

    cout << s << endl;
    cout << d << endl;
    cout << m << endl;
    cout << "Enter the factor: ";
    cin >> factor;
    m = a * factor;
    cout << m << endl;
    return 0;
}

