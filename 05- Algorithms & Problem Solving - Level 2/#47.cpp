
#include <iostream>
using namespace std;

float ReadNumber(string Message)
{
    cout << Message;
    float num = 0;
    cin >> num;
    return num;
}

float GetFractionPart(float Num) {
    return Num - (int)Num;
}

int MyRound(float Num) {
    int IntPart = (int)Num;
    return  (abs(GetFractionPart(Num)) < 0.5) ? IntPart ://OR
        ((Num > 0) ?
            ++IntPart : --IntPart);
}
int main()
{
    float num = ReadNumber(" Enter number : ");
    cout << " My ABS result : " << MyRound(num);

}
  