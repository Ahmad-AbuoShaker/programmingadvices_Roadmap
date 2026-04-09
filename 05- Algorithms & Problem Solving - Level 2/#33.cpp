// #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enCharType {
    Small_Letter = 1, Capital_letter = 2,
    Special_Character = 3, Digit = 4
};



int ReadPositiveNumber(string Message) {
    int Num = 0;
    do {
        cout << Message << endl << " ";
        cin >> Num;
    } while (Num < 0);
    return Num;
}

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enCharType CharType) {
    switch (CharType) {
    case Small_Letter:
        return char(RandomNumber(97, 122));
        break;
    case Capital_letter:
        return char(RandomNumber(65, 90));
        break;
    case Special_Character:
        return char(RandomNumber(33, 47));
        break;
    case Digit:
        return  char(RandomNumber(48, 57));
        break;
    }

}

string GenerateWord(enCharType CharType, short Length) {
    string Word;
    for (int i = 1; i <= Length; i++) {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey() {
    string Key = " ";

    for (int j = 1; j <= 4; j++) {
        Key += GenerateWord(Capital_letter, 4);
        if (j != 4) {
            Key += "_";
        }
    }
    return Key;
}




void FillArrayWithKeys(string Arr[100], int& ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        Arr[i] = GenerateKey();
    }
}

void PrintStringArray(string Arr[100], int ArrLength) {
    cout << "\n Array element :\n\n";
    for (int i = 0; i < ArrLength; i++) {
        cout <<" Array ["<<i+1<<"] = "<< Arr[i] << "\n";
    }
    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));
    int  Length = 0;
    string arr[100];
    Length = ReadPositiveNumber(" Enter number of element.");

    FillArrayWithKeys(arr, Length);

    PrintStringArray(arr, Length);
}

