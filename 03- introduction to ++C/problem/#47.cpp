

#include <iostream>
using namespace std;
int main()
{
    float L, M;

    cout << "Enter he loan value : ";
    cin >> L;
    cout << "Enter your monthly payment capacity : ";
    cin >> M;
    cout << "Number of months to repay the loan : " << (L / M);

}
