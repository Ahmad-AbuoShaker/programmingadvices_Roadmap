
#include <iostream>
using namespace std;

float ReadPositiveNum(string Message) {
    int Num;
    do {
        cout << Message << endl;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

float MonthlyInstallment(float LoanAmount, float HowManyMonths ) {
    return (LoanAmount / HowManyMonths);
}


int main() {
    float LoanAmount = ReadPositiveNum(" Enter Loan Amountt ? ");
    float HowManyMonths = ReadPositiveNum(" Enter How many Months ? ");

    cout << "\n Monthly Installment : " << MonthlyInstallment(LoanAmount, HowManyMonths);
    cout << endl;
    return 0;
}