#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    matr a(2, 2), b(2, 2);
    matr m(2, 2);
    cin >> a;
    cin >> b;
    cout << a;
    cout << b;
    m = a * b;
    cout << m << endl;
    return 0;
}

