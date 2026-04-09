
#include <iostream>
#include<vector>
using namespace std;



string ReplaceWordInStringUsingBuiltInFunction(string S1,string StringToReplace,string sReplaceTo) {

	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos) {
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
}



int main()
{

	cout << ReplaceWordInStringUsingBuiltInFunction("Ahmad Samer , Samer Ali","Samer","A");
}

