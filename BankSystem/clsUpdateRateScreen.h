#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateRateScreen : protected clsScreen
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

    static float _ReadNewRate()
    {
        float NewRate = 0;
        cout << "\nUpdate Currency Rate:";
        cout << "\n_____________________";
        cout << "\nEnter new Rate: ";
        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

public:
    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\t  Update Rate screen.");

        string CurrencyCode = "";
        cout << "Enter Currency code: ";
        CurrencyCode = clsInputValidate::ReadString();

        clsCurrency C1 = clsCurrency::Find(CurrencyCode);

        if (!C1.IsEmpty())
        {
            cout << "\nCurrency was found :-)\n";
            _PrintCurrency(C1);
        }
        else {
            cout << "\nCurrency was not found :-(\n";
        }

        cout << "\nAre you sure you want to update the currency rate? y/n: ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            C1.UpdateRate(_ReadNewRate());
            
            cout << "\n\nCurrency updated successfully :-)\n";
            _PrintCurrency(C1);
        }
    }
};

