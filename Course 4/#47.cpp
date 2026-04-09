
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

float TotalMonths(float LoanAmount, float MonthlyInstallment) {
    return (LoanAmount / MonthlyInstallment);
}


int main() {
    float LoanAmount = ReadPositiveNum(" Enter Loan Amountt ?");
    float MonthlyInstallment = ReadPositiveNum(" Enter Monthly Installment ?");

    cout << "\n Total Months to pay : " << TotalMonths(LoanAmount, MonthlyInstallment);
    cout << endl;
    return 0;
}