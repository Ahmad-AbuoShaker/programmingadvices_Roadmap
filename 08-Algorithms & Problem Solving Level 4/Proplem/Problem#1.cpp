

#include <iostream>

using namespace std;

string NumberToText(long int Number) {

    if (Number >= 1 && Number <= 19) {
        string Arr[] = { "","One","Tow","Three","Four","Five" ,"Six","Seven","Eight"
            ,"Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen"
            ,"Sixteen","Seventeen","Eighteen","NineTeen" };
        return Arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99) {
        string Arr[] = { "","","Twenty","Thirty","Forty","Fifty",
            "Sixty","Seventy","Eighty","Ninety" };
        return Arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199) {
        return  " One Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999) {
        return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999) {
        return " One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999) {
        return  NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999) {
        return " One Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999) {
        return  NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999) {
        return " One Billion " + NumberToText(Number % 1000000000);
    }
    else {
        return  NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
    }
}

int main()
{
    int Number;
    cout << " ";
    cin >> Number;
   cout<< NumberToText(Number);
}
