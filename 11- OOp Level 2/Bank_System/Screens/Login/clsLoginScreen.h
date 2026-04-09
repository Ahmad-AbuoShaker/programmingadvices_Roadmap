#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private :

  static  bool _Login()
    {
        bool LoginFaild = false;
        int FaildLoginCount = 3;

        string Username, Password;
        do
        {
     
            if (FaildLoginCount == 1)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }
            if (LoginFaild)
            {
                --FaildLoginCount;
                cout << "\nInvlaid Username/Password!\n";

            }
           
            cout << "\nYou have " << FaildLoginCount
                << " Trails to login.\n";
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

