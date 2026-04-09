
#include <iostream>
using namespace std;

struct stPiggyBankContent{
    int Penny, Nickel , Dime , Quarter , Dollar;
};

stPiggyBankContent ReadPiggyBankContent() {
    stPiggyBankContent PiggyBankContent;
    cout << " Enter a total of Penny :";
    cin >> PiggyBankContent.Penny;;
    cout << " Enter a total of Nickel :";
    cin >> PiggyBankContent.Nickel;
    cout << " Enter a total of Dime :";
    cin >> PiggyBankContent.Dime;
    cout << " Enter a total of Quarter :";
    cin >> PiggyBankContent.Quarter;
    cout << " Enter a total of Dollar :";
    cin >> PiggyBankContent.Dollar;

    return PiggyBankContent;

}
int CalculateTotalPennies(stPiggyBankContent PiggyBankContent) {
    return (PiggyBankContent.Penny * 1 + PiggyBankContent.Nickel * 5 +
        PiggyBankContent.Dime * 10 +   PiggyBankContent.Quarter * 25 +
        PiggyBankContent.Dollar * 100);
}

int main()
{ 
    int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());
    cout << " Total Pennies = " << TotalPennies << endl;
    cout << " Total Dollars = " << (float)TotalPennies / 100 << endl;

}

 