// #33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadTotalSales() {
    int Num;
    
        cout << " Enter your salary :";
        cin >> Num;
    return Num;
}

float GetCommissionPercentage(float TotalSales) {


    if (TotalSales >= 1000000)
        return 0.01;
    else if (TotalSales >= 500000)
        return 0.02;
    else if (TotalSales >= 100000)
        return 0.03;
    else if (TotalSales >= 50000)
        return 0.05;
    else
        return 0;


}

float CalculateTotalComission(float TotalSales) {
    return TotalSales * GetCommissionPercentage(TotalSales);
}

int main()
{
    float TotalSales = ReadTotalSales();
    cout << endl << " Commission Percentage =" << GetCommissionPercentage(TotalSales);
    cout << endl << " Total Comission =" << CalculateTotalComission(TotalSales);

}
