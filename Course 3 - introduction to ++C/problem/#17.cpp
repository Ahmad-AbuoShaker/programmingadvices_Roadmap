#include <iostream>
using namespace std;
int main()
{
    short w, h, s;
    cout << "Enter width and Height of the triangle\n";
    cin >> w >> h;
    s = (h * w) / 2;
    cout << "triangle is Area = " << s << endl;
    return 0;
}
