
#include <iostream>
#include<string>
using namespace std;
struct stInfo {
    string FirstName;
    string LastName;
};

stInfo ReadInfo() {
    stInfo info;
    cout << " Enter your first name :";
    cin>>info.FirstName;
    cout << " Enter your last name :";
    cin>> info.LasName;
    return info;
}
string GetFullName(stInfo info, bool Reversed) {
    if(Reversed)
    return(info.LastName + " " + info.FirstName);
    else
    return(info.FirstName + " " + info.LastName);

}
void PrintFullName(string Name) {
    cout << "\n Your name is :" << Name << endl;
}

int main()
{
    PrintFullName(GetFullName(ReadInfo(),0));
    return 0;
}

