#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
    enum enCurrencyExchangeMenuOptions {
       eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
       eCurrencyCalc = 4, eMainMenu = 5
    };

    static short _ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? : ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5);
        return Choice;
    }

    static  void _GoBackToCurrencyExchangeMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to Currency Exchange Menu...\n";

        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        cout << "Currency calculator screen will be here...\n";
    }

    static void _PerformCurrencyExhangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
        case clsCurrencyExchangeScreen::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case clsCurrencyExchangeScreen::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case clsCurrencyExchangeScreen::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case clsCurrencyExchangeScreen::eCurrencyCalc:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case clsCurrencyExchangeScreen::eMainMenu:
            break;
        default:
            break;
        }
    }

public:
	static void ShowCurrencyExchangeScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        system("cls");

        _DrawScreenHeader("\t  Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExhangeMenuOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
	}
};

