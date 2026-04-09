#include <iostream>
using namespace std;

float getAverage(int x[]) {
	return (x[0]+x[1]+x[2]) / 3;
}
int main()
{
	int mark[3];
	cout <<" Enter your mark1 :" << endl;
	cin >> mark[0];
	cout <<" Enter your mark2 :" << endl;
	cin >> mark[1];
	cout <<" Enter your mark3 :" << endl; 
	cin >> mark[2];
	if (getAverage(mark) < 50) { cout << " You failed."; }
	else { cout << " You succeesed."; }
}
							