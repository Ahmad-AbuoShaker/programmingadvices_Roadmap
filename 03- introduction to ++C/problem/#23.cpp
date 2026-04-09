//مساحة دائرة داخل مثلث
#include <iostream>
#include<cmath>
const float pi = 3.14;
using namespace std;

int CircleArea(int a, int b, int c) {
	float p, t, s;
	p = (a + b + c) / 2;
	t = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	s = floor(pi * pow(t, 2));

	return s;
}
int CircleArea() {
	int a, b, c;

	float p, s, t;
	cout << "Enter the lengths of the sides of the triangle :\n";
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	t = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	s = pi * pow(t, 2);
	cout << "Area of the circle :" << round(s);

	return s;
}



int main()
{
	int a, b, c; float s;
	cout << "Enter the lengths of the sides of the triangle :\n";
	cin >> a >> b >> c;
	cout << "Area of the circle :" << CircleArea(a,b,c);

	s = CircleArea();
	cout << "Area of the circle :" << s;
	return 0;

}

