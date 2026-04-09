// تنازليا
//

#include <iostream>
using namespace std;

void ForLoop(int n) {
    for (int i = n; i >0; i--) {
        cout << i << endl;
    }
}

void WhileLoop(int n) {
    int i = n;
    while (i > 0) {
        cout << i << endl;
        i--;
    }
}

int main()
{
    int n;
    cout << "Enter the number :";
    cin >> n;
    ForLoop(n);
    WhileLoop(n);
    return 0;
}