// #33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadMarkInRange(int From,int To) {
    int Num;
    do {
        cout << " Enter a number :";
        cin >> Num;
    } while (Num<From||Num>To);
    return Num;
}

char GetGradLetter(int Mark) {

    if (Mark >= 90)
        return 'A';
    else if (Mark >= 80)
        return 'B';
    else if (Mark >= 70)
        return 'C';
    else if (Mark >= 60)
        return 'D';
    else if (Mark >= 50)
        return 'E';
    else
        return 'F';


}

int main()
{
    cout << " Result ="<<GetGradLetter(ReadMarkInRange(0,100));
}
