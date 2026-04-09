#include <iostream>
using namespace std;

int RectArea(int b, int a) {
    return a * b;
}
int RectArea() {
    short w, l, s;
    cout << "Enter length and width of the rectangle :" << endl;
    cin >> w >> l;
    s = l * w;
    cout << "rectangle is Area = " << s << endl;
    return s;
}
int main()
{
    short w, l, s;
    cout << "Enter length and width of the rectangle :" << endl;
    cin >> w >> l;
    cout << "rectangle is Area = " << RectArea(w, l) << endl;
    s = RectArea();
    cout << s;
    return 0;
}
