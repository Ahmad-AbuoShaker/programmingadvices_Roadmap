// Homework 36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int x = 300;//Global

int getX() {
    int x;
   return x = 600;
  
}
int main()
{
    int x = 500;
    cout << "local X =" <<x<< endl;
    cout << "getX x =" << getX() << endl;
    cout << "Global X =" << ::x << endl;;

}
