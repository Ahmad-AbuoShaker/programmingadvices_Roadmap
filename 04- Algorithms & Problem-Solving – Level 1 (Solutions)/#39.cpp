
#include <iostream>
#include<string>
#include<cmath>
using namespace std;

float ReadPositiveNum(string Message) {
    int Num;
    do {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}
 
float CalculateRemainder(float TotalBill, float TotalCashPaid) {
    return (TotalCashPaid-TotalBill);
}
int main()
{
    float TotalBill = ReadPositiveNum(" Enter Total Bill :");
    float TotalCashPaid = ReadPositiveNum(" Enter Total Cash Paid :");

    cout << endl << " Total Bill = " << TotalBill << endl;
    cout << " Total Cash Paid = " << TotalCashPaid << endl;

    cout << "***************************\n";
    cout << " Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;
    
    return 0;
}
