

#include <iostream>

using namespace std;

void PrintNumber(int n, int m) {
    if (n <= m) {
        cout << n << endl;
        PrintNumber(n + 1, m);
    }
}

int Pow(int n, int m) {
    if (m == 0) {
        return 1;
    }
    else {
        return n * Pow(n, m - 1);
    }
}

int main()
{
    PrintNumber(1, 555);
   std::cout << Pow(5, 99);
}
