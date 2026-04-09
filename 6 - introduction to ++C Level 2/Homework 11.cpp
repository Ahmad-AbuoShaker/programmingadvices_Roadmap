#include <iostream>

using namespace std;

int ReadNumber() {
    int Number = 0;
    cout << " Enter a Number : ";
    cin >> Number;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << " Invaild Number, Enter a vail Number :";
        cin >> Number;
    }
    return Number;
}

int main()
{
   int number= ReadNumber();
   cout << number;
}
