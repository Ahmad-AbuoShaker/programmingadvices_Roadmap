
#include <iostream>

using namespace std;

class clsCalculater {
private:

    float _LastNumber = 0;
    float _PrevesResult = 0;
    string _LastOperation = "Clear";
    float _Resulte = 0;


    bool _isZero(float Number) {
        return Number == 0;
    }

public:

    void Clear() {
        _LastNumber = 0;
        _PrevesResult = 0;
        _LastOperation = "Clear";
        _Resulte = 0;
    }

    void Add(float Number) {
        _LastNumber = Number;
        _PrevesResult = _Resulte;
        _LastOperation = "Adding";
        _Resulte += _LastNumber;
    }

    void Subtract(float Number) {

        _LastNumber = Number;
        _PrevesResult = _Resulte;
        _LastOperation = "Subtracting";
        _Resulte -= _LastNumber;
    }

    void Divide(float Number) {

        _LastNumber = Number;
        if (_isZero(Number)) {
            Number = 1;
        }

        _PrevesResult = _Resulte;
        _LastOperation = "Dividing";
        _Resulte /= _LastNumber;
    }

    void Multiply(int Number) {

        _LastNumber = Number;
        _PrevesResult = _Resulte;
        _LastOperation = "Multiplying";
        _Resulte *= _LastNumber;
    }

    float GetLastResulte() {
        return _Resulte;
    }

    void CancelLastOperation() {
        _Resulte = _PrevesResult;
        _LastNumber = 0;
        _LastOperation = "Canceling Last Operation";

    }


    void PrintResult() {
        cout << "\n Reulte";
        cout<<" After " << _LastOperation << " " << _LastNumber << " is :" << _Resulte;

    }


};



int main()
{
    clsCalculater Calculater;

    Calculater.Add(5);
    Calculater.PrintResult();

    Calculater.Multiply(6);
    Calculater.PrintResult();

}
