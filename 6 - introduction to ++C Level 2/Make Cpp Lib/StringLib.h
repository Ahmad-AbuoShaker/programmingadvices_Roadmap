#pragma once
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

namespace StringLib {
    string ReadText() {
        cout << " Enter a Text :";
        string Text;
        getline(cin, Text);
        return Text;

    }

    //ÊæÇÈÚ ááÊÔÝíÑ
    string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    string DecryptText(string Text, short EncryptionKey) {

        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }
    //

}