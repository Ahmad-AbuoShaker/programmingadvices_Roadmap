//حساب عدد الايام و الساعات و الدقائق من عدد الثواني
#include <iostream>
using namespace std;



void secToTime() {
	int ms = 60, hs = ms * 60, ds = hs * 24, s;
	cout << " How many seconds did you work :" << endl;
	cin >> s;
	cout << " you work :" << endl;
	cout << " Days :" << floor(s / ds) << endl;
	cout << " hours :" << floor((s % ds) / hs) << endl;
	cout << " minutes :" << floor((s % hs) / ms) << endl;
	cout << " seconds :" << floor(s % ms) << endl;

}
int main()
{
	secToTime();
	return 0;
}