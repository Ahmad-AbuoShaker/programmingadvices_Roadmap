//حساب العاملي n!
#include <iostream>
using namespace std;
void PrintCapitalLatterF(){

    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << " ";
    }

}

void PrintCapitalLatterW() {
    int i = 65;
    while (i<=90) {
        cout << char(i) << " ";
        i++;
    }

}



int main()
{
    PrintCapitalLatterF();
    PrintCapitalLatterW();
    return 0;
}
