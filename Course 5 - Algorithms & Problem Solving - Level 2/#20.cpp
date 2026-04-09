
#include <iostream>

using namespace std;


int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}


enum enCharType {
    Small_Letter = 1, Capital_letter = 2,
    Special_Character = 3, Digit = 4
};

void GetRandomCharacter(enCharType CharType) {
    cout << "\n ";
    switch (CharType) {
    case Small_Letter:       
        cout << char(RandomNumber(97, 122)) << endl;
        break;
    case Capital_letter:
        cout << char(RandomNumber(65, 90)) << endl;
        break;
    case Special_Character:
        cout << char(RandomNumber(33, 47)) << endl;
        break;
    case Digit:
        cout << char(RandomNumber(48, 57)) << endl;
        break;
   }
}

int main()
{
    srand((unsigned)time(NULL));

    GetRandomCharacter(enCharType::Small_Letter);
    GetRandomCharacter(enCharType::Capital_letter);
    GetRandomCharacter(enCharType::Special_Character);
    GetRandomCharacter(enCharType::Digit);
}
