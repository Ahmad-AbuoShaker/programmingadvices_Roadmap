
#include <iostream>
#include<vector>
using namespace std;




/////////////////////////////////////////////////////////////////////////
string UpperAllString(string& S1) {
	for (int i = 0; i < S1.length(); i++) {
		S1[i] = toupper(S1[i]);
	}
	return S1;
}
string JoinString(vector<string>VString, string Delim) {
	if (VString.empty()) return"";

	string S1;
	for (string& s : VString) {
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
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


string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true) {
	vector<string>VString;

	VString = SplitString(S1, " ");

	for (string& s : VString) {
		if (MatchCase) 
		{
			if (s == StringToReplace)
			{
				s = sReplaceTo;
			}
		}
		else
		{
			if (UpperAllString(s) == UpperAllString(StringToReplace)) 
			{
				s = sReplaceTo;
			}
		}
	}
	return JoinString(VString, " ");
}



int main() {


	cout << ReplaceWordInStringUsingSplit("Ahmad Samer , Samer Ali", "Samer", "A");
}


