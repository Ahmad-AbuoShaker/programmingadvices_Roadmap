
#include <iostream>
using namespace std;


string ReadPinCode() {
	string PinCode;
	cout << " Enter Pin Code :" << endl;
	cout << " "; cin >> PinCode;

	return PinCode;
}

bool Login() {
	string PinCode;
	int Counter = 3;
	do {
		Counter--;
		PinCode = ReadPinCode();
		if (PinCode == "1234") {
			return 1;
		}
		else {
			cout << "\n Wrong PIN ,You have "<< Counter<<" Chances. \n";
			system("color 4F");
			
		}
	} while (PinCode != "1234" && Counter > 0);
return 0;
}

int main()
{
	if (Login()) {
		system("color 2F");
		cout << " Your balance :" << 7500 << "\n";
	}
	else {
		cout << "\n Your card blocked call the bank for help. \n";
	}
}


