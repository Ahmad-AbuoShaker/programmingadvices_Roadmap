// #1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintTableHeader() {

    cout << "\n\t\t\t\tMultiplication Table From 1_10\n\n";
   // cout << " ";
    for (int i = 1; i <= 10; i++) {
        cout << "\t" <<i;
    }
    cout << "\n____________________________________________________________________________________\n";
}

string ColumSeparator(int i) {
    if (i < 10)
        return"    |";
    else
        return"   |";
}

void PrintMultiplicationTable() {
    PrintTableHeader();
    for (int i = 1; i <= 10; i++) {
        cout << " " << i << ColumSeparator(i)<<"\t";
        
        for (int j = 1; j <= 10;j++) {
            cout << j*i<<"\t";
        }

       cout << endl;
    }


}






int main()
{
    PrintMultiplicationTable();
    
}

 