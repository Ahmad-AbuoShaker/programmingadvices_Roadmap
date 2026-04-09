
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


int MyCeil(float Num) {
    int IntPart = (int)Num;
    if (GetFractionPart(Num) == 0.0) {
        return IntPart;
    }
    else{
        return ((Num > 0) ? ++IntPart : IntPart);
    }
}
int main()
{
    float num = ReadNumber(" Enter number : ");
    cout << " My Ceil result : " << MyCeil(num);

}
