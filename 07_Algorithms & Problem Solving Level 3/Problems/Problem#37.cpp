
#include <iostream>
#include<vector>
using namespace std;

vector<string> SplitString(string S1,string Delim) {
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

int main()
{
	string s1 = "Ahmad#..#Ali#..#Samer";
	vector<string>VString = SplitString(s1,"#..#");
	cout << VString.size()<<"\n";
	for (string& s : VString) {
		cout << s<<"  ";
	}
}

