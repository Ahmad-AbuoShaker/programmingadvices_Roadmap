// مساحة دائرة داخل مثلث متساوي الساقين
#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.14;

int CircleArea(float a, float b,) {
    return  floor((pi * pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b)));
}
int CircleArea(){
    float a, b, s;
    cout << "Enter the length of the base and the two side sides :";
    cin >> a >> b;
    s = (pi * pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
    cout << "circle is Area :" << floor(s) << endl;
    return s;
}




int main()
{
    
    float a, b, s;
    cout << "Enter the length of the base and the two side sides :";
    cin >> a >> b; 
    cout << "circle is Area :" << CircleArea(a,b) << endl;
    s = CircleArea();
    cout << "circle is Area :" << s;
    return 0;
}
