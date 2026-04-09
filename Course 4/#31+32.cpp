
#include <iostream>
#include <string>
using namespace std;

int ReadNum(){
    int Num;
    cout << " Enter a number :";
    cin >> Num;
    return Num;
}
int ReadPow() {
    int pow;
    cout << " Enter a :";
    cin >> pow;
    return pow;
}
void PowerOf2_3_4(int Num) {
    int a, b, c;
    a = Num * Num;
    b = a * Num;
    c = b * Num;
    cout << a << " " << b << ' ' << c << endl;

}

int Power(int Num, int Pow) {
    if (Pow == 0) {
        return 0;
    }
    int p=1;
    for (int i = 1; i <= Pow; i++) {
        p = p * Num;
    }
    return p;
}

void PrintResult(int Num) {
    cout << " Result =" << Num << endl;

}

int main()
{
 
    PowerOf2_3_4(ReadNum());
    PrintResult(Power(ReadNum(), ReadPow()));

}
