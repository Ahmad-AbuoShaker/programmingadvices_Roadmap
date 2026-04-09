
//حساب ثواني العمل 
#include <iostream>
#include <cmath>
using namespace std;


int Get_Work_second(int d,int h,int m,int s) {
	int T = (d * 86400) + (h * 3600) + (m * 60) + s;
	return T;
}

int Get_Work_second() {
	int d, h, m, s;
	cout << "How many did you work :\n";
	cout << "Days:"; cin >> d;
	cout << "hours:"; cin >> h;
	cout << "minutes:"; cin >> m;
	cout << "seconds:"; cin >> s;
	int T = (d * 86400) + (h * 3600) + (m * 60) + s;
	cout << "The total seconds you work is : " << round(T);
	return T;

}
int main()
{

   return 0;
}
