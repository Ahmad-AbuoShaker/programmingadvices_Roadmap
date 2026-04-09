// العد تصاعديا
//

#include <iostream>
using namespace std;
void ForLoop(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
    }
}

void WhileLoop(int n){
    int i = 0;
    while (i<=n) {
        cout << i << endl;
        i++;
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

