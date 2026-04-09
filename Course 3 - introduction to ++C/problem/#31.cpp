#include <iostream>
using namespace std;


int pow(int a, int n) {
    for (int i = 0; i < n; i++) { a *= a; }
    return a;
}

int main()
{
    int a;
    cout << "Enter a Number :";
    cin >> N;
   // a = N * N; b = a * N; c = b * N;//(هذا سابقا)
    
    cout << "\n" << N << "^2 =" << round(pow(N,2)) << "\n"<<N<<"^3 =" << round(pow(N, 3)) << "\n" << N << "^4 =" << round(pow(N,4));
    return 0;
}
