#include <iostream>
using namespace std;
int main()
{
    short p, n, d, q, D, T, TD;
    cout << "enter  Your coins :";
    cin >> p >> n >> d >> q >> D;
    T = p + n * 5 + d * 10 + q * 25 + D * 100;
    TD = T / 100;
    cout << " \nyour total penny is " << T;
    cout << " \nyour total Dollars is " << TD;
}