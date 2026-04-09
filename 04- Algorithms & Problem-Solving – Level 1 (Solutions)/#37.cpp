
#include <iostream>
#include<string>
using namespace std;

int ReadNum(string Message) {
    int Num;
    cout << Message;
    cin >> Num;
    return Num;
}
int SumNumbers() {
    int Sum = 0, N = 0, counter = 1;
    do {
        N = ReadNum(" Enter Number " + to_string(counter));
        if (N == -99) {
            break;
        }
        Sum += N;
        counter++;
    } while (N != -99);
    return Sum;
}

int main()
{
    cout << " Resulte =" << SumNumbers() << endl;
}
