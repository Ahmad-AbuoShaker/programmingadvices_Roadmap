// Homework 49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void AA_ZZ(){
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {

            cout << char(i) << char(j) << endl;
        }
    }
}
void dfl(){
    for (int i = 0; i <= 10; i++) {//i=10;i>0;i--
        for (int j = 0; j <= 10 - i; j++) {//j=0;j<=i;j++

            cout << "*";
        }
        cout << endl;
    }
}
void jf(){
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= i; j++) {

            cout << j << " ";
        }
        cout << endl;
    }
}
void kjh(){
    for (int i = 0; i <= 10; i++) {//i=10;i>0;i--
        for (int j = 0; j <= 10 - i; j++) {//j<i

            cout << j << " ";
        }
        cout << endl;
    }
}
void A_F() {
    for (int i = 65; i <= 70; i++) {
        for (int j = 65; j <= i; j++) {

            cout << char(j) << " ";
        }
        cout << endl;
    }
}
void ku() {
    for (int i = 0; i <=10; i++) {
        for (int j = i; j <= 10; j++) {

            cout << j << " ";
        }
        cout << endl;
    }


}
int main()
{
   // A_F();
  // kjh();
  // dfl();
   // jf();
    ku();
}

