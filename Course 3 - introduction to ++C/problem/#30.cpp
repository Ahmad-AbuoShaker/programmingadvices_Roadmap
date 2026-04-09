//حساب العاملي n!
#include <iostream>
using namespace std;

int FactorForLoop(int n) {
    int Factor = 1;
    for (int i = 1; i <= n; i++) {
        Factor *= i;

    }
    return Factor;
}

int FactorWhileLoop(int n) {
    int Factor = 1;
    int i = 1;
    while (i <= n) {
        Factor *= i;
        i++;
    }
    return sum;
}




int main()
{
    int n;
    cout << "Enter the number :";
    cin >> n;
    cout << FactorForLoop(n);
    cout << FactorWhileLoop(n);

    return 0;
}
