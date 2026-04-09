
#include <iostream>
using namespace std;

void swap(int &a,int &b) {
	int m = a;
	a = b; 
	b = m;
}


int main()
{
	short x, y;
	cout << "Enter two numbers :" << endl;
	cin >> x >> y;

	cout << "number1 =" << x << "\nnumber2 =" << y << endl;
	cout << "*******Swap********" << endl;
/*	t = x;
	x = y;
	y = t;*/
	swap(x, y);
	cout << "number1 =" << x << "\nnumber2 =" << y;
	 
	return 0;
}
