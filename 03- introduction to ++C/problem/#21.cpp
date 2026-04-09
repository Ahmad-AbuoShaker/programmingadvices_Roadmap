//مساحة دائرة من طول محيطها
#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.14;

int CircleArea(int l) {
    return  floor((pow(l, 2) / (4 * pi));
}

int CircleArea() {
    float l, s;

    cout << "Enter the length of the circle's circumference :";
    cin >> l;
    s = pow(l, 2) / (4 * pi);
    cout << "circle is Area = " << floor(s) << endl;
    return s;

int main()
{
    float l, s;
    cout << "Enter the length of the circle's circumference :";
    cin >> l;
    cout << "circle is Area = " << fCircleArea(l) << endl;
    s = CircleArea();
    return 0;
}
