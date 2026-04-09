
#include <iostream>
#include<string>
using namespace std;
void getname() {
    string s;
    cout << "Enter your name : ";
    getline(cin, s);
    cout << "Name :" << s << endl;

}
int main()
{
    getname();
    return 0;
}

