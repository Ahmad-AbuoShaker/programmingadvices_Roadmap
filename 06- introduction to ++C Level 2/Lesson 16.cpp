// Lesson 16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//OverLoading

#include <iostream>

int sum(int a, int b, int c, int d) {
	return(a + b + c + d);
}
int sum(int a, int b, int c) {
	return(a + b + c );
}
int sum(int a, int b) {
	return(a + b);
}
float sum(float a, float b) {
	return(a + b );
}

int main()
{
	sum(5.6,5);
}

