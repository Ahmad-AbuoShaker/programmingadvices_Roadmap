#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.14;


int CircleArea(int a) {
    return  ceil(pi * pow(a / 2, 2));
}

int CircleArea() {
    float a, s;

    cout << "Enter the rib length of the square :";
    cin >> a;
    s = pi * pow(a / 2, 2);
    cout << "circle is Area = " << ceil(s) << endl;
    return s;
}


int main()
{
    float a, s;
    const float pi = 3.14;
    cout << "Enter the rib length of the square :";
    cin >> a;
    s = pi * pow(a / 2, 2);
    cout << "circle is Area = " << CircleArea(a) << endl;
    s = CircleArea();
    return 0;
}