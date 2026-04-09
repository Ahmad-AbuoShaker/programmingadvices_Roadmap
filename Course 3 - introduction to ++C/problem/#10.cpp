
#include <iostream>
using namespace std;
int main()
{
    short m1, m2, m3, avg;
    cout << "enter your marks :\n";
    cin >> m1 >> m2 >> m3;
    avg = (m1 + m2 + m3) / 3;
    cout << "you marks is\n Mark1 =" << m1 << endl << "Mark2 =" << m2 << endl << "Mark3 =" << m3
        << endl << "your avrge is :" << avg << endl;
    if (avg > 50) { cout << "S\n"; }
    else { cout << "F\n"; }
    return 0;
}