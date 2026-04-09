#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

using namespace std;

class clsMainScreen:protected clsScreen
{


    private:
        enum enCurrencyExchangeMenueOption {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
        };

       static short _ReadMainMenueOption(short From,short To)
        {
           cout << setw(37) << left << "" << "Choose what do you want to do? [" + to_string(From) + " to " + to_string(To) + "] ? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(From,To,"Enter Number between " + to_string(From) + " to " + to_string(To) + " :");
            return Choice;
        }

       static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
           
            system("pause>0");
            ShowMainMenue();
        }
       
       static void _ShowAllClientsScreen()
       {
        //cout << "\nClient List Screen Will be here...\n";
           
           clsClientListScreen::ShowClientsList();

       }

       static void _ShowAddNewClientsScreen()
       {
         //  cout << "\nAdd New Client Screen Will be here...\n";
           clsAddNewClientScreen::ShowAddNewClientScreen();
       }

       static void _ShowDeleteClientScreen()
       {
          // cout << "\nDelete Client Screen Will be here...\n";
           clsDeleteClientScreen::ShowDeleteClientScreen();
       }

       static void _ShowUpdateClientScreen()
       {
          // cout << "\nUpdate Client Screen Will be here...\n";
           clsUpdateClientScreen::ShowUpdateClientScreen();
       }

       static void _ShowFindClientScreen()
       {
           //cout << "\nFind Client Screen Will be here...\n";
           clsFindClientScreen::ShowFindClientScreen();
       }

       static void _ShowTransactionsMenue()
       {
         //  cout << "\nTransactions Menue Will be here...\n";
           clsTransactionsScreen::ShowTransactionsMenue();
       }

       static void _ShowManageUsersMenue()
       {
           //cout << "\nUsers Menue Will be here...\n";
           clsManageUsersScreen::ShowManageUsersMenue();
       }

       static void _ShowLoginRegisterList() {
          // cout << "Here _ShowLoginRegisterList screen\n";
           clsLoginRegisterScreen::ShowLoginRegisterScreen();
       }

       static void _ShowCurrencyExchangeMenue() {

           clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMenue();
       }

       static void _Logout()
           {
               //cout << "\nEnd Screen Will be here...\n";
           CurrentUser = clsUser::Find("", "");
           }

       static void _PerfromMainMenueOption(enCurrencyExchangeMenueOption MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enCurrencyExchangeMenueOption::eListClients:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enCurrencyExchangeMenueOption::eAddNewClient:
                system("cls");
                _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eDeleteClient:
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eUpdateClient:
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eFindClient:
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eShowTransactionsMenue:
                system("cls");
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eManageUsers:
                system("cls");
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eLoginRegister:
                system("cls");
                _ShowLoginRegisterList();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eCurrencyExchange:
                system("cls");
                _ShowCurrencyExchangeMenue();
                _GoBackToMainMenue();
                break;

            case enCurrencyExchangeMenueOption::eExit:
                system("cls");
                _Logout();


                break;
            }

        }



	public:
       

       static void ShowMainMenue()
        {
           
            system("cls");
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enCurrencyExchangeMenueOption)_ReadMainMenueOption(1,10));
        }

};

