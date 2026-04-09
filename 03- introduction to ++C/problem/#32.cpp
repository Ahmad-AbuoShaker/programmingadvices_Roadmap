
#include <iostream>
using namespace std;

int PowForLoop(int a,int e) {
	for (int i = 0; i < n; i++) {
		a *= a;
	}
	return a;
}

int PowWhileLoop(int n, int e) {
	int i = 2;
	while (i<= e) {
		n *= n;
		i++;
	}
	return sum;
}


int pow(int a, int n) {
	for (int i = 0; i < n; i++) {
		a *= a;
	}
	return a;
}


int pow() {
	float a, n;
	cout << "Enter the number :"; cin >> a;
	cout << "and Exponent :"; cin >> n;
	for (int i = 0; i < n; i++) { a *= a; }
	cout << "The result is :" << a;
	return a;
}

int main()
{
	int n, e;
	cout << "Enter the number :"; cin >> n; 
	cout << "and Exponent :"; cin >> e;
	cout << "The result is :" << round(pow(n, e));
	return 0;
}
