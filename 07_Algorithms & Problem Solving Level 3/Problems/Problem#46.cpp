
#include <iostream>
#include<vector>
#include<cctype>
#include <string>
using namespace std;

struct sClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string Phone;
	double AccountBalance;
};

sClient ReadClient() {
	sClient Client;
	cout << " Enter Account Number :";
	getline(cin, Client.AccountNumber);
	cout << " Enter PinCode :";
	getline(cin, Client.PinCode);
	cout << " Enter Name :";
	getline(cin, Client.FullName);
	cout << " Enter Phone :";
	getline(cin, Client.Phone);
	cout << " Enter Account Balance :";
	cin >> Client.AccountBalance;
	return Client;
}

vector<string> SplitString(string S1, string Delim) {
	int pos = 0;

	string SWord;

	vector<string>VString;
	while ((pos = S1.find(Delim)) != std::string::npos) {
		SWord = S1.substr(0, pos);
		if (SWord != " ") {
			VString.push_back(SWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "") {
		VString.push_back(S1);
	}
	return VString;
}


string CounvertRecordToLine(sClient Client, string Seperator = "#//#") {
	string stClientRecord;
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.FullName + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance) + Seperator;
	return stClientRecord;
}


sClient CounvertLineToRecord(string Line, string Seperator = "#//#"){
	sClient Client;
	vector<string> VClientData = SplitString(Line, Seperator);
	vector<string> ::iterator iter = VClientData.begin();
	
	Client.AccountNumber = VClientData[0];
	Client.PinCode =       VClientData[1];
	Client.FullName =      VClientData[2];
	Client.Phone =         VClientData[3];
	Client.AccountBalance =stod(VClientData[4]);

	return Client;
}

void PrintCleintRecord(sClient Client){
	cout << "\n\n The following is extracted client record :\n";
	cout << "\n Account Number  : " << Client.AccountNumber;
	cout << "\n PinCode         : " << Client.PinCode;
	cout << "\n Name            : " << Client.FullName;
	cout << "\n Phone           : " << Client.Phone;
	cout << "\n Account Balance : "<< Client.AccountBalance;
	
}


int main() {
	sClient Client = ReadClient();
	string Line= CounvertRecordToLine(Client);
	cout << Line;
	Client=CounvertLineToRecord(Line);
	PrintCleintRecord(Client);
}


