

#include <iostream>
#include<vector>
#include<cctype>
#include <string>
#include<fstream>
#include <iomanip>
#include <limits>
#include <cmath> // لاستخدام دوال الرياضيات
#include <cstdlib> // لاستخدام system

using namespace std;
const string ClientsFileName = "Clients.txt";
const string CurrentClient = "Users.txt";
struct sClient {
	string UserName;
	string UserPassword;
	int Permission = 0;
	bool MarkForDelete = false;
};
struct sClient {
	string AccountNumber;
	string PinCode;
	string FullName;
	string Phone;
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
};
enum enMainMenuOptions {
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactions = 6,
	eManageUser = 7, eLogout = 8,
	eExit = 9
};
enum enTransactionsMenuOption {
	enDeposit = 1, enWhithDraw = 2,
	enTotalBalance = 3, enMainMenu = 4
};
enum enManageUserMenuOption {
	eListUser = 1, eAddNewUser = 2,
	eDeleteUser = 3, eUpdateUser = 4,
	eFindUser = 5, eMainMenu = 6,
};
enum enMainMenuPermission {
	pAll = -1, pListClients = 1,
	pAddNewClient = 2, pDeleteClient = 4,
	pUpdateClient = 8, pFindClient = 16,
	pTransactions = 32, pManageUser = 64
};

string tabs(short n) {
	string Tab = "";
	for (int i = 0; i < n; i++) {
		Tab += "\t";
	}
	return Tab;
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
void AddDataLineToFile(string FileName, string stDataLine) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << stDataLine << "\n";
		MyFile.close();
	}
}

void ShowATM_MainMenu();
void ShowManageUserMenu();
void ShowTransactionsMenu();
void GoBackToMainMenue();
void login();
sClient CurrentUser;
///////////////////////////////////////////////////////////////
/*             Function for Read File And Search            */

bool FindClientByAccountNumber(string AccountNumber, vector <sClient>& VClient, sClient& Client) {

	for (sClient& c : VClient) {
		if (c.AccountNumber == AccountNumber) {
			Client = c;
			return true;
		}
	}
	return false;
}
string ConvertClientToLine(sClient& Client, string Seperator = "#//#") {
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
	vector <sClient> vClients;

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

			vClients.push_back(Client);
		}
		Myfile.close();
	}
	return false;
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

////////////////////////////////////////////////////////////////////////////
/*           Fouction for Read and print client info                      */

string ReadClientAccountNumber() {
	string AccountNumber = "";
	cout << "\n Enter Account Number : ";
	cin >> AccountNumber;
	return AccountNumber;
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
	AddDataLineToFile(ClientsFileName, ConvertClientToLine(Client));
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
	cout << "----------------------------------------------------";
	cout << "\n Account Number  : " << Client.AccountNumber;
	cout << "\n PinCode         : " << Client.PinCode;
	cout << "\n Name            : " << Client.FullName;
	cout << "\n Phone           : " << Client.Phone;
	cout << "\n Account Balance : " << Client.AccountBalance;
	cout << "\n----------------------------------------------------\n";

}
void PrintClientRecordLine(sClient& Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.FullName;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

/////////////////////////////////////////////////////////////////////////////
/*                   Fouction for Delete Client Info          */

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
				DataLine = ConvertClientToLine(C);
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
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////
/*                   Fouction for Update Client Info           */


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
	}
	return false;

}

////////////////////////////////////////////////////////////////////////////
/*                   Fouction for read Options              */

int ReadMainMenueOption() {
	int Number = 0;
	cout << " Choose what you want to do [1->9]: ";
	cin >> Number;
	while (cin.fail() || (Number < 1 || 9 < Number)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n Invaild Number, Enter a vail Number :";
		cin >> Number;
	}
	return Number;
}
int ReadTransactionsMenueOption() {
	int Number = 0;
	cout << " Choose what you want to do [1->4]: ";
	cin >> Number;
	while (cin.fail() || (Number < 1 || 4 < Number)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n Invaild Number, Enter a vail Number :";
		cin >> Number;
	}
	return Number;
}
int ReadManageUserMenueOption() {
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


///////////////////////////////////////////////////////////////
/*             Function for Read User File And Search            */

bool FindUserByUserName(string UserName, vector <sClient>& VUser, sClient& User) {

	for (sClient& U : VUser) {
		if (U.UserName == UserName) {
			User = U;
			return true;
		}
	}
	return false;
}
string ConvertUserToLine(sClient& User, string Seperator = "#//#") {
	string stUserRecord;
	stUserRecord += User.UserName + Seperator;
	stUserRecord += User.UserPassword + Seperator;
	stUserRecord += to_string(User.Permission);
	return stUserRecord;
}
sClient ConvertUserLineToRecord(string Line, string Seperator = "#//#") {
	sClient User;
	vector<string> VUserData = SplitString(Line, Seperator);

	User.UserName = VUserData[0];
	User.UserPassword = VUserData[1];
	User.Permission = stoi(VUserData[2]);

	return User;
}
bool UserExistsByUserName(string UserName, string FileName)
{
	vector <sClient> vUsers;

	fstream Myfile;
	Myfile.open(FileName, ios::in);

	if (Myfile.is_open()) {
		string Line;
		sClient User;
		while (getline(Myfile, Line)) {

			User = ConvertUserLineToRecord(Line);
			if (User.UserName == UserName) {
				Myfile.close();
				return true;
			}

			vUsers.push_back(User);
		}
		Myfile.close();
	}
	return false;
}
vector <sClient> LoadCleintsDataFromFile(string FileName) {
	vector <sClient> VUser;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		sClient User;
		while (getline(MyFile, Line)) {
			User = ConvertUserLineToRecord(Line);
			VUser.push_back(User);
		}
		MyFile.close();
	}
	return VUser;
}

////////////////////////////////////////////////////////////////////////////
/*           Fouction for Read and print User info                      */

string ReadUserName() {
	string UserName = "";
	cout << "\n Enter User Name : ";
	cin >> UserName;
	return UserName;
}
string ReadPinCode() {
	string Password = "";
	cout << "\n Enter Password : ";
	cin >> Password;
	return Password;
}
int ReadPermissionToSet() {

	char Answer = 'n';
	cout << "\n Do you want to give full access? [Y/N]: ";
	cin >> Answer;

	if (toupper(Answer) == 'Y') {
		return -1;
	}
	else {

		int permission = 0; 

		cout << "\n Do you want to give access to : ";

		cout << "\n Show Clients List [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pListClients; 

		cout << "\n Add new Client [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pAddNewClient;

		cout << "\n Delete Client [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pDeleteClient;

		cout << "\n Update Client [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pUpdateClient;

		cout << "\n Find Client [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pFindClient;

		cout << "\n Transactions [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pTransactions;

		cout << "\n Manage Users [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') permission += pManageUser;

		return permission;
	}
}
sClient ReadNewUser() {
	sClient User;
	cout << " Enter User Name :";
	getline(cin >> ws, User.UserName);

	while (UserExistsByUserName(User.UserName, CurrentClient)) {
		cout << "\n Name [" << User.UserName << "] already exists ,"
			<< "Enter another Name :";
		getline(cin >> ws, User.UserName);
	}

	cout << " Enter Password :";
	getline(cin, User.UserPassword);

	User.Permission = ReadPermissionToSet();

	return User;
}
void AddNewUser() {
	sClient User;
	User = ReadNewUser();
	AddDataLineToFile(CurrentClient, ConvertUserToLine(User));
}
void AddNewUsers() {

	char Again = 'y';

	do {

		cout << " Adding new User :\n\n";
		AddNewUser();
		cout << "\n User Added Successfully ,do you want to add more User ?";
		cin >> Again;

	} while (toupper(Again) == 'Y');

}
void PrintUserCard(sClient& User) {
	cout << "\n\n The following is extracted User record :\n";
	cout << "----------------------------------------------------";
	cout << "\n User Name       : " << User.UserName;
	cout << "\n User Password   : " << User.UserPassword;
	cout << "\n User Permission : " << User.Permission;
	cout << "\n----------------------------------------------------\n";

}
void PrintUserRecordLine(sClient& User) {

	cout << "| " << setw(15) << left << User.UserName;
	cout << "| " << setw(10) << left << User.UserPassword;
	cout << "| " << setw(12) << left << User.Permission;

}

/////////////////////////////////////////////////////////////////////////////
/*                   Fouction for Delete User Info          */

bool MarkUserForDeleteByUserName(string UserName, vector<sClient>& VUser) {
	for (sClient& U : VUser) {
		if (U.UserName == UserName)
		{
			U.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
vector<sClient> SaveUsersDataToFile(string FileName, vector<sClient>& VUser) {
	fstream MyFile(FileName, ios::out);
	string DataLine;

	if (MyFile.is_open()) {

		for (sClient& U : VUser) {

			if (U.MarkForDelete == false) {

				DataLine = ConvertUserToLine(U);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}

	return VUser;
}
bool DeleteUserByUserName(string UserName, vector<sClient>& VUser) {
	sClient User;
	char Answer = 'n';
	if (UserName == "Admin") {
		cout << "\n You cann't Delete this user.";
		return false;
	}


	if (FindUserByUserName(UserName, VUser, User)) {

		PrintUserCard(User);
		cout << "\n\n Are you sure you want delete this User? [Y/N] ";
		cin >> Answer;
		cin.ignore();

		if (toupper(Answer) == 'Y') {

			MarkUserForDeleteByUserName(UserName, VUser);
			SaveUsersDataToFile(CurrentClient, VUser);
			VUser = LoadCleintsDataFromFile(CurrentClient);
			cout << "\n\n User Deleted Successfully";

			return true;
		}

	}
	else {
		cout << "\n User with Name (" << UserName << ") NOT Found!\n ";
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////
/*                   Fouction for Update User Info           */

sClient ChangeUserRecord(string UserName) {

	sClient User;
	User.UserName = UserName;

	cout << " Enter Password :";
	getline(cin >> ws, User.UserPassword);

	if (UserName != "Admin") {
		User.Permission = ReadPermissionToSet();
	}

	return User;
}
bool UpdateUserByUserName(string UserName, vector<sClient>& VUser) {
	sClient User;
	char Answer = 'y';


	if (FindUserByUserName(UserName, VUser, User)) {

		PrintUserCard(User);

		cout << "\n\n Are you sure you want update this User? [Y/N] ";
		cin >> Answer;
		cin.ignore();

		if (toupper(Answer) == 'Y') {

			for (sClient& U : VUser) {
				if (U.UserName == UserName) {
					U = ChangeUserRecord(UserName);
					break;
				}
			}

			SaveUsersDataToFile(CurrentClient, VUser);

			cout << "\n\n User updated Successfully";
			return true;
		}
	}
	else {
		cout << "\n User with Name (" << UserName << ") NOT Found!";
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////*/
/*                 Fouction for show in Manage user menu               */
void GoBackToManageUserMenu()
{
	cout << "\n\n Press any key to go back to Transactions Menue...";
	system("pause>0");
	ShowManageUserMenu();
}

void ShowAllUserScreen() {
	vector <sClient> VUser = LoadCleintsDataFromFile(CurrentClient);

	cout << "\n" << tabs(5) << "User List (" << VUser.size() << ") User(s)";
	cout << "\n___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
	cout << "| " << left << setw(14) << "User Name ";
	cout << "| " << left << setw(10) << "Password ";
	cout << "| " << left << setw(12) << "Permission ";
	cout << "\n___________________________________________________________";
	cout << "_____________________________________________________________\n\n";

	for (sClient& User : VUser) {
		PrintUserRecordLine(User);
		cout << "\n";
	}
	cout << "___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
}
void ShowAddUserScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Add New User screen\n";
	cout << "-------------------------------------------------------------\n";

	AddNewUsers();
}
void ShowDeleteUserScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Delete User screen\n";
	cout << "-------------------------------------------------------------\n";
	vector<sClient> VUser = LoadCleintsDataFromFile(CurrentClient);
	string UserName = ReadUserName();
	DeleteUserByUserName(UserName, VUser);

}
void ShowUpdateUserScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Update User screen\n";
	cout << "-------------------------------------------------------------\n";

	vector<sClient> VUser = LoadCleintsDataFromFile(CurrentClient);
	string UserName = ReadUserName();
	UpdateUserByUserName(UserName, VUser);
}
void ShowFindUserScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Find User screen\n";
	cout << "-------------------------------------------------------------\n";

	string UserName = ReadUserName();
	vector<sClient> VUser = LoadCleintsDataFromFile(CurrentClient);
	sClient User;
	if (FindUserByUserName(UserName, VUser, User))
	{
		PrintUserCard(User);
	}
	else
		cout << "\n User with Name (" << UserName << ") NOT Found!\n ";
}

void PerformManageUserMenuOption(enManageUserMenuOption ManageUserMenuOption) {

	switch (ManageUserMenuOption) {
	case eListUser:
		system("cls");
		ShowAllUserScreen();
		GoBackToManageUserMenu();
		break;
	case eAddNewUser:
		system("cls");
		ShowAddUserScreen();
		GoBackToManageUserMenu();
		break;
	case eDeleteUser:
		system("cls");
		ShowDeleteUserScreen();
		GoBackToManageUserMenu();
		break;
	case eUpdateUser:
		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUserMenu();
		break;
	case eFindUser:
		system("cls");
		ShowFindUserScreen();
		GoBackToManageUserMenu();
		break;
	case eMainMenu:
		system("cls");
		ShowATM_MainMenu();
		break;
	default:
		break;
	}

}
////////////////////////////////////////////////////////////////////////////
/*                   Fouction for  transacions              */

bool ChangeBalance(string AccountNumber, double Amount, vector<sClient>& VClient) {
	char Answer = 'n';
	cout << "\n Are you sure you want perform this transactino? [Y/N] : ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		for (sClient& C : VClient) {
			if (C.AccountNumber == AccountNumber) {
				C.AccountBalance += Amount;
				SaveCleintsDataToFile(ClientsFileName, VClient);
				cout << " Deposit Successfully, New balance is :" << C.AccountBalance;
				return true;
			}
		}
	}
	return false;
}
void DepositBalanceToClientByAccountNumber(string AccountNumber, vector<sClient>& VClient) {
	double Amount = 0;
	sClient Client;

	while (!FindClientByAccountNumber(AccountNumber, VClient, Client)) {
		cout << "\n Client Account Number [" << AccountNumber << "] Not Found ,"
			<< "Enter another account number :";
		getline(cin >> ws, AccountNumber);
	}

	PrintCleintCard(Client);

	cout << "\n Enter deposit amount :";
	cin >> Amount;
	while (Amount < 0) {
		cout << "\n Enter a positive Value :";
		cin >> Amount;
	}
	ChangeBalance(AccountNumber, Amount, VClient);
}
void Withdraw(string AccountNumber, vector<sClient>& VClient) {
	double Amount = 0;
	sClient Client;

	while (!FindClientByAccountNumber(AccountNumber, VClient, Client)) {
		cout << "\n Client Account Number [" << AccountNumber << "] Not Found ,"
			<< "Enter another account number :";
		getline(cin >> ws, AccountNumber);
	}

	PrintCleintCard(Client);

	cout << "\n Enter WhithDraw amount :";
	cin >> Amount;
	while (Amount > Client.AccountBalance || Amount < 0) {
		if (Amount < 0) {
			cout << "\n Enter positive Value :";
		}
		else {
			cout << "\n Amount Exceeds the balance, you can whithdraw up to :"
				<< Client.AccountBalance;
			cout << "\n Enter another WhithDraw amount :";
		}
		cin >> Amount;
	}

	ChangeBalance(AccountNumber, -1 * Amount, VClient);

}
void PrintClientBalance(sClient Client) {

	cout << "| " << setw(20) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.FullName;
	cout << "| " << setw(30) << left << Client.AccountBalance;
	cout << "\n";

}

/////////////////////////////////////////////////////////////////////////////*/
/*                 Fouction for show in transacions menu               */

void GoBackToTransactionsMenue()
{
	cout << "\n\n Press any key to go back to Transactions Menue...";
	system("pause>0");
	ShowTransactionsMenu();
}

void ShowDepositScreen() {
	cout << "\n\n-------------------------------------------------------------\n";
	cout << tabs(2) << "Deposit screen\n";
	cout << "-------------------------------------------------------------\n";
	vector<sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DepositBalanceToClientByAccountNumber(AccountNumber, VClient);

}
void ShowWhithDrawScreen() {
	cout << "\n\n-------------------------------------------------------------\n";
	cout << tabs(2) << "WhithDraw screen\n";
	cout << "-------------------------------------------------------------\n";
	vector<sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	Withdraw(AccountNumber, VClient);

}
void ShowBalanceListScreen() {
	vector<sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);

	cout << "\n" << tabs(5) << "Client List (" << VClient.size() << ") Client(s)";
	cout << "\n___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
	cout << "| " << left << setw(20) << "Account Number ";
	cout << "| " << left << setw(40) << "Clients Name ";
	cout << "| " << left << setw(20) << "Balance ";
	cout << "\n___________________________________________________________";
	cout << "_____________________________________________________________\n\n";
	if (VClient.size() == 0) {
		cout << tabs(3) << "No Clients Available In the System.";
	}
	else
	{
		double TotalBalances = 0;

		for (sClient& C : VClient) {
			PrintClientBalance(C);
			TotalBalances += C.AccountBalance;
		}

		cout << "\n___________________________________________________________";
		cout << "_____________________________________________________________\n\n";
		cout << setw(63) << right << "Total Balance :" << TotalBalances;
		cout << "\n___________________________________________________________";
		cout << "_____________________________________________________________\n\n";
	}

}

void PerformTransactionsMenuOption(enTransactionsMenuOption TransactionsMenuOption) {

	switch (TransactionsMenuOption) {
	case enDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenue();
		break;
	case enWhithDraw:
		system("cls");
		ShowWhithDrawScreen();
		GoBackToTransactionsMenue();
		break;
	case enTotalBalance:
		system("cls");
		ShowBalanceListScreen();
		GoBackToTransactionsMenue();
		break;
	case enMainMenu:
		system("cls");
		ShowATM_MainMenu();
		break;
	default:
		break;
	}

}

////////////////////////////////////////////////////////////////////////////
enMainMenuPermission GetPermissionForOption(enMainMenuOptions option) {
	switch (option) {

	case eListClients:
		return pListClients;

	case eAddNewClient: 
		return pAddNewClient;

	case eDeleteClient:
		return pDeleteClient;

	case eUpdateClient:
		return pUpdateClient;

	case eFindClient:
		return pFindClient;

	case eTransactions:
		return pTransactions;

	case eManageUser:
		return pManageUser;

	default:
		break;

	}
}
void ShowAccessDeniedMessage() {
	system("cls");
	cout << "\n-----------------------------------------------";
	cout << "\n   Access Denied!";
	cout << "\n   You don’t have permission to perform this action.";
	cout << "\n   Please contact your Admin.";
	cout << "\n-----------------------------------------------\n";
}
bool CheckUserPermission(enMainMenuOptions UserOption){

	if (CurrentUser.Permission == pAll || UserOption == eExit || UserOption == eLogout)
		return true;

	if (CurrentUser.Permission & GetPermissionForOption(UserOption))
		return true;
	
	ShowAccessDeniedMessage();
	return false;
	
}
bool FindUserByUserNameAndPassword(string UserName,string Password, sClient& User) {

	vector<sClient> VUser = LoadCleintsDataFromFile(CurrentClient);

	for (sClient& U : VUser) {
		if (U.UserName == UserName && U.UserPassword == Password) {
			User = U;
			return true;
		}
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////
/*                   Fouction for show in maim menu                     */
void GoBackToMainMenue()
{

	cout << "\n\n Press any key to go back to Main Menue...";
	system("pause>0");
	ShowATM_MainMenu();

}

void ShowAllClientsScreen() {
	vector <sClient> VClient = LoadCleintsDataFromFile(ClientsFileName);

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
void ShowTransactionsMenu() {
	system("cls");
	cout << "============================================================\n";
	cout << tabs(2) << "Transactions Menue Screen";
	cout << "\n============================================================\n";

	cout << tabs(1) << "[1] Deposit.\n";
	cout << tabs(1) << "[2] whithDraw.\n";
	cout << tabs(1) << "[3] Total Balance.\n";
	cout << tabs(1) << "[4] Main Menue.";

	cout << "\n============================================================\n";
	PerformTransactionsMenuOption((enTransactionsMenuOption)ReadTransactionsMenueOption());

}
void ShowManageUserMenu() {
	system("cls");
	cout << "============================================================\n";
	cout << tabs(2) << " Manage User Menu Screen";
	cout << "\n============================================================\n";

	cout << tabs(1) << "[1] List User.\n";
	cout << tabs(1) << "[2] Add New User.\n";
	cout << tabs(1) << "[3] Delete User.\n";
	cout << tabs(1) << "[4] Update User.\n";
	cout << tabs(1) << "[5] Find User.\n";
	cout << tabs(1) << "[6] Main Menue.";

	cout << "\n============================================================\n";
	PerformManageUserMenuOption((enManageUserMenuOption)ReadManageUserMenueOption());

}
void ShowExitScreen() {
	cout << "-------------------------------------------------------------\n";
	cout << tabs(2) << "Program End :-)\n";
	cout << "-------------------------------------------------------------\n ";
}

void PerformMainMenuOption(enMainMenuOptions MainMenueOption) {

	if (!CheckUserPermission(MainMenueOption)) {
		GoBackToMainMenue();
		return;
	}
	system("cls");

	switch (MainMenueOption) {

	case eListClients:
		ShowAllClientsScreen();
		break;

	case eAddNewClient:
		ShowAddClientScreen();
		break;

	case eDeleteClient:
		ShowDeleteClientScreen();
		break;

	case eUpdateClient:
		ShowUpdateClientScreen();
		break;

	case eFindClient:
		ShowFindClientScreen();
		break;

	case eTransactions:
		ShowTransactionsMenu();
		return;

	case eManageUser:
		ShowManageUserMenu();
		return;

	case eLogout:
		login();
		return;

	case eExit:
		ShowExitScreen();
		return;

	default:
		cout << "\nInvalid option!";
		return;
	}

	GoBackToMainMenue();

}

////////////////////////////////////////////////////////////////////////////
		  /*            Main Menue                         */
void ShowATM_MainMenu() {

	system("cls");

	cout << "============================================================\n";
	cout << tabs(2) << "Main Menue Screen";
	cout << "\n============================================================\n";

	cout << tabs(1) << "[1] Show Client list.\n";
	cout << tabs(1) << "[2] Add New Client.\n";
	cout << tabs(1) << "[3] Delete Client.\n";
	cout << tabs(1) << "[4] Update Client Info.\n";
	cout << tabs(1) << "[5] Find Client.\n";
	cout << tabs(1) << "[6] Transactions.\n";
	cout << tabs(1) << "[7] Manage user.\n";
	cout << tabs(1) << "[8] Logout.\n";
	cout << tabs(1) << "[9] Exit.";
	cout << "\n============================================================\n";
	PerformMainMenuOption((enMainMenuOptions)ReadMainMenueOption());

}

//////////////////////////////////////////////////////////////////

bool LoudUserInfo(string UserName ,string Password) {

	return FindUserByUserNameAndPassword(UserName, Password, CurrentUser);

}

void login() {

	bool LoginFail = false;

	do {
		system("cls");

		cout << "\n------------------------------------";
		cout << "\n            Login Screen";
		cout << "\n------------------------------------";

		if (LoginFail) {
			cout << "\n Invalid Usernamer/Password.";
		}

		CurrentUser.UserName = ReadUserName();
		CurrentUser.UserPassword = ReadPinCode();

		LoginFail = LoudUserInfo(CurrentUser.UserName, CurrentUser.UserPassword);

	} while (!LoginFail);

	ShowATM_MainMenu();
}


int main() {

	login();
	system("pause>0");
	return 0;


}

