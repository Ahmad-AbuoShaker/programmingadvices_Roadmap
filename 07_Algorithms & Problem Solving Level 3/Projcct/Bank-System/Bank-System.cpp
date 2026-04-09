

#include <iostream>
#include<vector>
#include<cctype>
#include <string>
#include<fstream>
#include <iomanip>
#include <limits>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct sClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string Phone;
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
};
enum enMainMenueOptions {
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eExit = 6
};

string tabs(short n) {
	string Tab = "";
	for (int i = 0; i < n; i++) {
		Tab += "\t";
	}
	return Tab;
}
void ShowMainMenue();
///////////////////////////////////////////////////////////////



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
			Client = &c;
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////

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
string ConvertRecordToLine(sClient& Client, string Seperator = "#//#") {
	string stClientRecord;
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.FullName + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}
sClient ConvertLineToRecord(string Line, string Seperator = "#//#") {
	sClient Client;
	vector<string> VClientData = SplitString(Line, Seperator);

	Client.AccountNumber = VClientData[0];
	Client.PinCode = VClientData[1];
	Client.FullName = VClientData[2];
	Client.Phone = VClientData[3];
	Client.AccountBalance = stod(VClientData[4]);

	return Client;
}
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	fstream Myfile;
	Myfile.open(FileName, ios::in);
	if (Myfile.is_open()) {
		string Line;
		sClient Client;
		while (getline(Myfile, Line)) {

			Client = ConvertLineToRecord(Line);
			if (Client.AccountNumber == AccountNumber) {
				Myfile.close();
				return true;
			}

		}
		Myfile.close();
	}
	return false;
}
void AddDataLineToFile(string FileName, string stDataLine) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << stDataLine << "\n";
		MyFile.close();
	}
}
sClient ReadNewClient() {
	sClient Client;
	cout << " Enter Account Number :";
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName)) {
		cout << "\n Client Account Number [" << Client.AccountNumber << "] already exists ,"
			<< "Enter another account number :";
		getline(cin >> ws, Client.AccountNumber);
	}
	
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
void AddNewClient() {
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddNewClients() {

	char Again = 'y';

	do {
		
		cout << " Adding new client :\n\n";
		AddNewClient();
		cout << "\n Client Added Successfully ,do you want to add more Clients ?";
		cin >> Again;
	} while (toupper(Again) == 'Y');

}
void PrintCleintCard(sClient& Client) {
	cout << "\n\n The following is extracted client record :\n";
	cout << "\n Account Number  : " << Client.AccountNumber;
	cout << "\n PinCode         : " << Client.PinCode;
	cout << "\n Name            : " << Client.FullName;
	cout << "\n Phone           : " << Client.Phone;
	cout << "\n Account Balance : " << Client.AccountBalance;

}

////////////////////////////////////////////////////////////////////////////

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
void PrintClientRecordLine(sClient& Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.FullName;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}


/////////////////////////////////////////////////////////////////////////////

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& VClient) {
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
			if (C.MarkForDelete == false) {
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
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, VClient, Client)) {
		PrintCleintCard(Client);
		cout << "\n\n Are you sure you want delete this client? [Y/N] ";
		cin >> Answer;
		cin.ignore();
		if (toupper(Answer) == 'Y') {
			MarkClientForDeleteByAccountNumber(AccountNumber, VClient);
			SaveCleintsDataToFile(ClientsFileName, VClient);
			VClient = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\n Client Deleted Successfully";
			return true;
		}

	}
	else {
		cout << "\n Client with Account Number (" << AccountNumber << ") NOT Found!\n ";
		return false;
	}


}

////////////////////////////////////////////////////////////////////////////

sClient ChangeClientREcord(string AccountNumber) {
	sClient Client;
	Client.AccountNumber = AccountNumber;
	cout << " Enter PinCode :";
	getline(cin >> ws, Client.PinCode);
	cout << " Enter Name :";
	getline(cin, Client.FullName);
	cout << " Enter Phone :";
	getline(cin, Client.Phone);
	cout << " Enter Account Balance :";
	cin >> Client.AccountBalance;
	cin.ignore();
	return Client;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& VClient) {
	sClient Client;
	char Answer = 'y';
	if (FindClientByAccountNumber(AccountNumber, VClient, Client)) {
		PrintCleintCard(Client);
		cout << "\n\n Are you sure you want update this client? [Y/N] ";
		cin >> Answer;
		cin.ignore();
		if (toupper(Answer) == 'Y') {

			for (sClient& C : VClient) {
				if (C.AccountNumber == AccountNumber) {
					C = ChangeClientREcord(AccountNumber);
					break;
				}
			}

			SaveCleintsDataToFile(ClientsFileName, VClient);

			cout << "\n\n Client updated Successfully";
			return true;
		}
	}
	else {
		cout << "\n Client with Account Number (" << AccountNumber << ") NOT Found!";
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////


void ShowAllClientsScreen() {
	vector <sClient> VClient= LoadCleintsDataFromFile(ClientsFileName);

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
		PrintClientRecordLine(Client);
		cout << "\n";
	}
	cout << "___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
}
void ShowAddClientScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Add New Client screen\n";
	cout << "-------------------------------------------------------------\n";

	AddNewClients();
}
void ShowDeleteClientScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Delete Client screen\n";
	cout << "-------------------------------------------------------------\n";
	vector<sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, VClient);

}
void ShowUpdateClientScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Update Client screen\n";
	cout << "-------------------------------------------------------------\n";

	vector<sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, VClient);
}
void ShowFindClientScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Find Client screen\n";
	cout << "-------------------------------------------------------------\n";

	string AccountNumber = ReadClientAccountNumber();
	vector<sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		PrintCleintCard(Client);
	}
	else
		cout << "\n Client with Account Number (" << AccountNumber << ") NOT Found!\n ";
}
void ShowExitScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Program End :-)\n";
	cout << "-------------------------------------------------------------\n ";
}

void GoBackToMainMenue()
{
	cout << "\n\n Press any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();

}


int ReadMainMenueOption() {
	int Number = 0;
	cout << " Choose what you want to do [1->6]: ";
	cin >> Number;
	while (cin.fail() || (Number < 1 || 6 < Number)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n Invaild Number, Enter a vail Number :";
		cin >> Number;
	}
	return Number;
}
void PerfromMainMenueOption(enMainMenueOptions MainMenueOption) {
	
		switch (MainMenueOption) {
		case eListClients:
			system("cls");
			ShowAllClientsScreen();
			GoBackToMainMenue();
			break;
		case eAddNewClient:
			system("cls");
			ShowAddClientScreen();
			GoBackToMainMenue();
			break;
		case eDeleteClient:
			system("cls");
			ShowDeleteClientScreen();
			GoBackToMainMenue();
			break;
		case eUpdateClient:
			system("cls");
			ShowUpdateClientScreen();
			GoBackToMainMenue();
			break;
		case eFindClient:
			system("cls");
			ShowFindClientScreen();
			GoBackToMainMenue();
			break;
		case eExit:
			system("cls");
			ShowExitScreen();
			break;
		default:
			break;
		}
	
}

void ShowMainMenue() {
	system("cls");
	cout << "============================================================\n";

	cout << tabs(2) << "Main Menue Screen";
	cout << "\n============================================================\n";

	cout << tabs(1) << "[1] Show Client list.\n";
	cout << tabs(1) << "[2] Add New Client.\n";
	cout << tabs(1) << "[3] Delete Client.\n";
	cout << tabs(1) << "[4] Update Client Info.\n";
	cout << tabs(1) << "[5] Find Client.\n";
	cout << tabs(1) << "[6] Exit.";
	cout << "\n============================================================\n";
	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());

}

int main() {

	ShowMainMenue();
	system("pause>0");
	return 0;


}

