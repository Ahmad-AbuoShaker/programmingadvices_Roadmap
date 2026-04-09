#pragma once
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"

class clsCurrencyExchangeMainScreen :public clsScreen
{
    enum enCurrencyExchangeMenueOption {
        eCurrenciesList = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculater = 4,
        eMainMenue = 5
    };

    static short _ReadCurrencyExchangeMenueOption(short From, short To)
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [" + to_string(From) + " to " + to_string(To) + "] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(From, To, "Enter Number between " + to_string(From) + " to " + to_string(To) + " :");
        return Choice;
    }

    static  void _GoBackToCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowCurrenciesListScreen() {
       // cout << "eListCurrencies\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrncyScreen() {
        //cout << "_FindCurrncyScreen\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrncyRateScreen() {
       // cout << "_UpdateRateScreen";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrncyCalculater() {
        cout << "_CurrncyCalculater\n";
    }

    static void _PerfromCurrencyExchangeMenueOption(enCurrencyExchangeMenueOption CurrencyExchangeMenueOption)
    {
        switch (CurrencyExchangeMenueOption)
        {
        case enCurrencyExchangeMenueOption::eCurrenciesList:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenueOption::eFindCurrency:
            system("cls");
            _ShowFindCurrncyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenueOption::eUpdateRate:
            system("cls");
            _ShowUpdateCurrncyRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenueOption::eCurrencyCalculater:
            system("cls");
            _ShowCurrncyCalculater();
            _GoBackToCurrencyExchangeMenue();
            break;

        case enCurrencyExchangeMenueOption::eMainMenue:
            system("cls");
            //do nothing here the main screen will handle it :-) ;
            break;
        }

    }



public:

	static void ShowCurrencyExchangeMenue() {

        system("cls");
        _DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculater.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyExchangeMenueOption((enCurrencyExchangeMenueOption)_ReadCurrencyExchangeMenueOption(1, 5));
      
	}
};

