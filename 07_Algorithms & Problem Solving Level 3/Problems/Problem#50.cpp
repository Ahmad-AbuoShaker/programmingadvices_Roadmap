
#include <iostream>
#include<vector>
#include<cctype>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct sClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
string tabs(short n) {
	string Tab = "";
	for (int i = 0; i < n; i++) {
		Tab += "\t";
	}
	return Tab;
}

sClient ReadNewClient() {
	sClient Client;
	cout << " Enter Account Number :";
	getline(cin >> ws, Client.AccountNumber);
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
string ConvertRecordToLine(sClient& Client, string Seperator = "#//#") {
	string stClientRecord;
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.FullName + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}
void AddDataLineToFile(string FileName, string stDataLine) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << stDataLine << "\n";
		MyFile.close();
	}
}
void AddNewClient() {
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddClients() {

	char Again = 'y';

	do {
		system("cls");
		cout << " Adding new client :\n\n";
		AddNewClient();
		cout << "\n Client Added Successfully ,do you want to add more Clients ?";
		cin >> Again;
	} while (toupper(Again) == 'Y');

}
void PrintCleintCard(sClient &Client) {
	cout << "\n\n The following is extracted client record :\n";
	cout << "\n Account Number  : " << Client.AccountNumber;
	cout << "\n PinCode         : " << Client.PinCode;
	cout << "\n Name            : " << Client.FullName;
	cout << "\n Phone           : " << Client.Phone;
	cout << "\n Account Balance : " << Client.AccountBalance;

}
////////////////////////////////////////////////////////////////////////////
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
sClient ConvertLineToRecord(string& Line, string Seperator = "#//#") {
	sClient Client;
	vector<string> VClientData = SplitString(Line, Seperator);
	vector<string> ::iterator iter = VClientData.begin();

	Client.AccountNumber = VClientData[0];
	Client.PinCode = VClientData[1];
	Client.FullName = VClientData[2];
	Client.Phone = VClientData[3];
	Client.AccountBalance = stod(VClientData[4]);

	return Client;
}
vector <sClient> LoadCleintsDataFromFile(string FileName) {
	vector <sClient> VClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		sClient Client;
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line);
			VClient.push_back(Client);
		}
		MyFile.close();
	}
	return VClient;
}
void PrintClientRecord(sClient& Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.FullName;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}
void PrintAllClientsData(vector <sClient>& VClient) {
	cout << "\n" << tabs(5) << "Client List (" << VClient.size() << ") Client(s)";
	cout << "\n___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
	cout << "| " << left << setw(14) << "Account Number ";
	cout << "| " << left << setw(10) << "Pin Code ";
	cout << "| " << left << setw(40) << "Clients Name ";
	cout << "| " << left << setw(12) << "Phone ";
	cout << "| " << left << setw(12) << "Balance ";
	cout << "\n___________________________________________________________";
	cout << "_____________________________________________________________\n\n";

	for (sClient& Client : VClient) {
		PrintClientRecord(Client);
		cout << "\n";
	}
	cout << "___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
}

/////////////////////////////////////////////////////////////////////////////

string ReadClientAccountNumber() {
	string AccountNumber = "";
	cout << "\n Enter Account Number : ";
	cin >> AccountNumber;
	return AccountNumber;
}
bool FindClientByAccountNumber(string AccountNumber, vector <sClient>& VClient, sClient& Client) {

	for (sClient& c : VClient) {
		if (c.AccountNumber == AccountNumber) {
			Client = c;
			return true;
		}
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////////

void RemoveClient(string AccountNumber, string FileName) {
	//عملي تبقر للمراجعة و التعلم
	char Sure = 'y';
	cout << "\n Are you sure you want delete this Client [Y/N] ?";
	cin >> Sure;

	if (toupper(Sure) == 'Y') {

		vector <sClient> VClient = LoadCleintsDataFromFile(FileName);

		fstream MyFile(FileName, ios::out);
		MyFile.close();

		for (sClient& C : VClient) {
			if (C.AccountNumber != AccountNumber)
				AddDataLineToFile(FileName, ConvertRecordToLine(C));
		}
		cout << " Client removed.\n";
	}
	else
		cout << " Opretion cancelled.\n";
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber,vector<sClient> &VClient) {
	for (sClient& C : VClient) {
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient>& VClient) {
	fstream MyFile(FileName, ios::out);
	string DataLine;
	if (MyFile.is_open()) {
		for (sClient& C : VClient) {
			if (C.MarkForDelete==false) {
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return VClient;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& VClient) {
	sClient Client;
	char Answer = 'y';
	if (FindClientByAccountNumber(AccountNumber, VClient, Client)) {
		PrintCleintCard(Client);
		cout << "\n\n Are you sure you want delete this client? [Y/N] ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') {
			MarkClientForDeleteByAccountNumber(ClientsFileName, VClient);
			SaveCleintsDataToFile(ClientsFileName, VClient);
			VClient = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\n Client Deleted Successfully";
			return true;
		}

	}
	else {
		cout << "\n Client with Account Number (" << AccountNumber << ") NOT Found!";
		return false;
	}


}

////////////////////////////////////////////////////////////////////////////




int main() {





}

