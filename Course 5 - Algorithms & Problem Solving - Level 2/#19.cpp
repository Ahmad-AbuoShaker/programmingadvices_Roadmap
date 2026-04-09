// #19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 

using namespace std;

int RandomNumber(int From,int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << RandomNumber(1,59) << endl;
    cout << RandomNumber(8, 59) << endl;
    cout << RandomNumber(19, 589) << endl;


}

