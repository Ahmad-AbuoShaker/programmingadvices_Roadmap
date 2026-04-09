#include <iostream>
#include<string>
using namespace std;

string ReadPassword() {
    cout << " Enter a 3 Capital Letter Password :";
    string Password;
        cin >> Password;
       
        return Password;
}




bool GuessPassword(string OriginalPassword) {
    string Pass = "";
    int Counter = 0;
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                Pass = Pass+ char(i);
                Pass = Pass + char(j);
                Pass = Pass +char(k);
                Counter++;
                cout << "\n Trail [" << Counter << "] : " << Pass << endl;
                if (Pass == OriginalPassword) {
                    cout << "Password is " << Pass << "\n";
                    cout << " Found after " << Counter << " Trial(s).";
                    return 1;
                }
                Pass = "";
            }
        }

    }
    return 0;
}

int main()
{
    GuessPassword(ReadPassword());
}

