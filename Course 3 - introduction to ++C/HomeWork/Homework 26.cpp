#include<iostream>
using namespace std;
int main() {
	short A, B;
	cout << "enter number A : ";
	cin >> A;
	cout <<"\nenter number B : ";
	cin >> B;
	cout << "\n" << (A = B);
	cout << "\n" << (A != B);
	cout << "\n" << (A <= B);
	cout << "\n" << (A >= B);
	cout << "\n" << (A > B);
	cout << "\n" << (A < B);
	return 0;
}