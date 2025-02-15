#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n__________________________________";
        cout << "\nCountry :" << Currency.Country();
        cout << "\nCode    :" << Currency.CurrencyCode();
        cout << "\nName    :" << Currency.CurrencyName();
        cout << "\nRate    :" << Currency.Rate();
        cout << "\n__________________________________";
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find currency screen.");

        string CurrencyIdentifier = "";
        cout << "Enter Country or Currency code: ";
        CurrencyIdentifier = clsInputValidate::ReadString();

        clsCurrency C1 = clsCurrency::Find(CurrencyIdentifier);

        if (!C1.IsEmpty())
        {
            cout << "\nCurrency was found :-)\n";
            _PrintCurrency(C1);
        }
        else {
            cout << "\nCurrency was not found :-(\n";
        }
    }
};

