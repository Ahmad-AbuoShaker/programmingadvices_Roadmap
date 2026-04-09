
#include <iostream>
using namespace std;
void Read2Number(int& Num1, int& Num2) {
    cout << " Enter the Number 1 :";
    cin >> Num1;
    cout << " Enter the Number 2 :";
    cin >> Num2;
}
void Read3Number(int& Num1, int& Num2,int &Num3) {
    cout << " Enter the Number 1 :";
    cin >> Num1;
    cout << " Enter the Number 2 :";
    cin >> Num2;
    cout << " Enter the Number 3 :";
    cin >> Num3;
} 
int MaxOf2Num(int Num1, int Num2) {
    
    if (Num1 > Num2)
        return Num1;
    else
        return Num2;
}
int MaxOf3Num(int Num1, int Num2,int Num3){
    if (Num1 > Num2) {
        if (Num1 > Num3)
            return Num1;
        else
        
            return Num3;
        }
    else {
        if (Num2 > Num3)
            return Num2;
        else
            return Num3;
    }
    
      
          

}
void PrintResult(int Max) {
    cout << " The max number is :" << Max << endl;

}
int main()
{

}

