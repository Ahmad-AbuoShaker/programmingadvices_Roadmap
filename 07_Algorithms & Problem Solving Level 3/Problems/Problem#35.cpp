#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;



void PrintEachWordInString(string S1) {
	int pos = 0;
	string delim = " ";
	string SWord;


	while ((pos = S1.find(delim)) != std::string::npos) {
		SWord = S1.substr(0, pos);
		if (SWord != " ") {
			cout << SWord<<"\n";
		}
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "") {
		cout << S1;
	}
}




int main()
{
	PrintEachWordInString("Ahmad shaker is frome damas");


}

