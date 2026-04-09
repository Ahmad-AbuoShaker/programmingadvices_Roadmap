
#include <iostream>
#include<vector>
#include<cctype>
using namespace std;




/////////////////////////////////////////////////////////////////////////


string RemovePunctuationsFromString(string S1) {
	
	string S2 = "";


	for (int i = 0; i < S1.length();i++) {
		
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}

	}
	return S2;
}



int main() {


	cout << ReplaceWordInStringUsingSplit("Ahmad Samer , Samer Ali", "Samer", "A");
}


