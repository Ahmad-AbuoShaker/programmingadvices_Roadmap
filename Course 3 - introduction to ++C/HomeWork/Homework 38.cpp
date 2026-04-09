#include <iostream>
#include <string>
using namespace std;

void ProcedureMySum(){ 
	int n1, n2;
	cout << "Enter Number1 :" << endl;
	cin >> n1;
	cout << "Enter Number2 :" << endl;
	cin >> n2;
	cout << "******************" << endl;
	cout << n1 + n2;
}
int MySumFaction() {
	int n1, n2;
	cout << "Enter Number1 :" << endl;
	cin >> n1;
	cout << "Enter Number2 :" << endl;
	cin >> n2;
	
	return n1 + n2;
}
int MySumFaction(int n1, int n2) {
	return n1 + n2;
}


int main()
{
	ProcedureMySum();
	cout << MySumFaction() << endl;
	int n1, n2;
	cout << "Enter Number1 :" << endl;
	cin >> n1;
	cout << "Enter Number2 :" << endl;
	cin >> n2;
	cout << MySumFaction(n1,n2) << endl;



	return 0;
}

