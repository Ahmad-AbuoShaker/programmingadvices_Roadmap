
#include <iostream>
#include<cmath>
using namespace std;
const double pi = 3.14;
int CircleArea(int r) {
	 return ceil(pi * pow(r, 2));
}
int CircleArea() {
	int r,s;
	
	cout << "Enter the radius of the circle :"; cin >> r;
	s = ceil(pi * pow(r, 2));
	cout << "Area of the circle :" << ;
	return s;
}
int main()
{
	
	int r,s;
	cout << "Enter the radius of the circle :"; cin >> r;
	cout << "Area of the circle :" << CircleArea(r);
	s = CircleArea();

}

