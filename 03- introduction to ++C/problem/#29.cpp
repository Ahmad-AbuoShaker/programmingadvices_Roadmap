//جمع الاعداد ضمن مجال
#include <iostream>
using namespace std;

int sumForLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;

    }
    return sum;
}

int sumWhileLoop(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }
    return sum;
}





int main()
{
    int n; int sum = 0;
    cout << "Enter the number :";
    cin >> n;
    cout << sumForLoop(n);
    cout << sumWhileLoop(n);


    return 0;
}
