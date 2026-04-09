
#include <iostream>
using namespace std;


string ReadPinCode() {
    string PinCode;
	cout << " Enter Pin Code :" << endl;
	cin >> PinCode;
    
	return PinCode;
}

bool Login() {
	string PinCode;
	do {
		PinCode = ReadPinCode();
		if (PinCode == "1234") {
			return 1;
		}
		else {
			cout << " \nWrong PIN\n";
			system("color 4F");
		}
	} while (PinCode != "1234");
}

int main()
{
	if (Login()) {
		system("color 4F");
		cout << " Your balance :" << 7500 << "\n";
	};
}



}