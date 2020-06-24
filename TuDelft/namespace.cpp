#include <iostream>
using namespace std;

namespace integer 
{
    int x  = 5;
    int y = 10;
}

namespace floating
{
    double x = 3.67;
    double y = 2e-1;
}

int main()
{
    using integer::x;
    using floating::y;

    cout << x << endl;
    cout << y << endl;

    cout << floating::y << endl;
    cout << integer::x << endl;

    return 0;

}