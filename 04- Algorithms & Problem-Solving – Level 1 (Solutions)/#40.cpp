
#include <iostream>

using namespace std;

float ReadPositiveNum(string Message) {
    int Num;
    do {  
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

float TotalBillAfterServiceAndTsx(float TotalBill) {
    TotalBill = TotalBill * 1.1;
    TotalBill = TotalBill * 1.6;
    return TotalBill;
}
int main()
{
    float TotalBill = ReadPositiveNum(" Enter Total Bill :");

    cout << endl;
    cout << " Total Bill = " << TotalBill << endl;
    cout << " Total Bill After Service Fee and Sales Tsx : "
        << TotalBillAfterServiceAndTsx(TotalBill) << endl;

    return 0;
}
