
#include <iostream>
using namespace std;

float ReadNumber(string Message)
{
    cout << Message;
    float num = 0;
    cin >> num;
    return num;
}

float MySqrt(int Num) {
    return pow(Num, 0.5);
}
int main()
{
    float num = ReadNumber(" Enter number : ");
    cout << " My Floor result : " << MySqrt(num);
    sqrt(num);

}
