#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Num = 0;
    do {
        cout << Message << endl << " ";
        cin >> Num;
    } while (Num < 0);
    return Num;
}

void PrintInvertedNumberPatter(short Num) {
    for (int i = Num; i >0; i--) {
       
            for (int j = 1; j <= i; j++) {
                cout << i;
            }
            cout << "\n";
        
        
        
    }
}
int main()
{
    PrintInvertedNumberPatter(ReadPositiveNumber(" Enter aNumbert :"));
}

