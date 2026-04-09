#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;



int CountWords(string S1) {
	int pos = 0;
	string delim = " ";
	string SWord;
	int Counter = 0;

	while ((pos = S1.find(delim)) != std::string::npos) {
		SWord = S1.substr(0, pos);
		if (SWord != " ") {
			Counter++;
		}
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "") {
		Counter++;
	}
	return Counter;
}




int main()
{
	cout<< CountEachWordInString("Ahmad shaker is frome damas");


}

