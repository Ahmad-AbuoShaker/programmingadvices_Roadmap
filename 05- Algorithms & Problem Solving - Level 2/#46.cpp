
#include <iostream>
using namespace std;

int ReadNumber(string Message)
{
    cout << Message;
    int num = 0;
    cin >> num;
    return num;
}

int MyABS(int Num) {
    return(Num >= 0) ? Num : -Num;
}

int main()
{
  int num=  ReadNumber(" Enter number : ");
  cout<<" My ABS result : "<< MyABS(num);

}
