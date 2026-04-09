

#include <iostream>
#include<string>
using namespace std;

string ReadName(){
    cout << " Enter your name :";
    string Name;
    getline(cin, Name);
    return Name;
}

void PrintName(string Name) {
    cout << " Your name is :"<< Name << endl;

}
int main()
{
    PrintName(ReadName());
    return 0;
}
