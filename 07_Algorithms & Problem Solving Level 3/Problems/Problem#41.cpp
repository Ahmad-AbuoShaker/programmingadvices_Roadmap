
#include <iostream>
#include<vector>
using namespace std;


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

string ReversWordsInString(string S1) {
	vector<string>VString;
	string S2 = "";

	VString = SplitString(S1," ");

	vector<string>::iterator iter = VString.end();

	while (iter!=VString.begin() ){
		--iter;
		S2 = S2 + *iter + " ";
	}
	S2.substr(0, S2.length() - 1);
	return S2;
}



int main()
{
	
	cout<<ReversWordsInString("Ahmad Samer Ali");
}

 