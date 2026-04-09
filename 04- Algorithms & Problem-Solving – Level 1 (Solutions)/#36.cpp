
#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-',
                   Multiply = '*', Divide = '/'};


float ReadNumber(string Message) {
    float Num = 0;
    cout << Message;
    cin >> Num;
    return Num;

}
  
enOperationType ReadOpType() {
    char Op;
    cout << " Enter the type of operation (+,-,*,/) :";
    cin >> Op;
    return (enOperationType)Op;


   
}

float Calculate(float Num1, float Num2, enOperationType OpType) {
    switch (OpType) 
    {
    case Add:
        return Num1 + Num2;
    case Subtract:
        return Num1 - Num2;
    case Multiply:
         return Num1 * Num2;
    case Divide:
         return Num1 / Num2;
    default:
        return Num1 + Num2;
    }
}

int main()
{    
    float num1 = ReadNumber(" Enter first number :");
    float Num2 = ReadNumber("  Enter second number :");
    enOperationType OpType = ReadOpType();
    cout << " Rrsulte :" << Calculate(num1, Num2, OpType) << endl;


}
