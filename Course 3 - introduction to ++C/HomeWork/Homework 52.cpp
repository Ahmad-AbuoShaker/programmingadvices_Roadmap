//بحث عن عنصر في مصفوفة

#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 85,84,92,86,20,63,97,21,11,40 }, SearchFor = 20;
	for (int i = 0; i < 10; i++) {
		cout << " We are at iteration " << i << endl;
		if (a[i] == SearchFor) {
			cout << " a[" << i << "] =20";
			break;

		}
	}

}
