#pragma once
#include<iostream>
#include<cmath>
using namespace std;

namespace RandomLib {

    int RandomNumber(int From, int To) {
        int RandNum = rand() % (To - From + 1) + From;
        return RandNum;
    }

    enum enCharType {
        Small_Letter = 1, Capital_letter = 2,
        Special_Character = 3, Digit = 4
    };
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

    void GenerateKeys(int NumOfKeys) {
        for (int i = 1; i <= NumOfKeys; i++) {
            cout << " Key[" << i << "] : "
                << GenerateKey() << endl;

        }

    }


}