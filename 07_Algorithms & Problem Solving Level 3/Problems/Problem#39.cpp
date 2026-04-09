
#include <iostream>
#include<vector>
using namespace std;



string JoinString(vector<string>VString,string Delim) {
	if (VString.empty()) return"";

	string S1;
	for (string& s : VString) {
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}



int main()
{
	vector<string>VString = { "ahmad","samer","Ali" };
	cout << JoinString(VString,";");

}
