// جمع الارقام التي يدخلها المستخدم ,,اذا ادخل -99 نتوقف
//

#include <iostream>
using namespace std;
int main()
{
    int n; int sum = 0;
   
    while (n != -99) {
        cout << "Enter the number for sum :";
        cin >> n;
        sum += n;
    }
    cout << "Result :" << sum;
}
