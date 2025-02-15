#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculator : protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n__________________________________";
        cout << "\nCountry :" << Currency.Country();
        cout << "\nCode    :" << Currency.CurrencyCode();
        cout << "\nName    :" << Currency.CurrencyName();
        cout << "\nRate    :" << Currency.Rate();
        cout << "\n__________________________________";
    }

	static clsCurrency _ReadCurrency()
	{
        string C1Code = "";

        C1Code = clsInputValidate::ReadString();

        clsCurrency C1 = clsCurrency::Find(C1Code);

        while (C1.IsEmpty())
        {
            cout << "\nCurrency was not found, enter another code: ";
            C1 = clsCurrency::Find(C1Code);
        }

        return C1;
	}

    static void _PrintCalculationsResult(float Amount, clsCurrency CFrom, clsCurrency CTo)
    {
        float AmountInUSD = 0;
        cout << "\nConvert From: ";
        _PrintCurrency(CFrom);

        AmountInUSD = CFrom.ConvertToUSD(Amount);
        cout << endl << Amount << " " << CFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";

        if (CTo.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConvert from USD to: ";
        _PrintCurrency(CTo);
        float AmountInCTo = CFrom.ConvertToOtherCurrency(Amount, CTo);
        cout << endl << Amount << " " << CFrom.CurrencyCode() << " = " << AmountInCTo << CTo.CurrencyCode() << endl;
    }


public:
	static void ShowCurrencyCalculatorScreen()
	{
        char Answer = 'n';

        do
        {
            system("cls");
            _DrawScreenHeader("\t  Currency calculator screen.");

            cout << "\nEnter Currency1 code: ";
            clsCurrency C1 = _ReadCurrency();

            cout << "\nEnter Currency2 code: ";
            clsCurrency C2 = _ReadCurrency();

            cout << "\n\nEnter amount to exchange: ";
            float amount = clsInputValidate::ReadFloatNumber();

            _PrintCalculationsResult(amount, C1, C2);

            cout << "\nDo you want to make another calculation? y/n: ";
            cin >> Answer;

        } while (Answer == 'y' || Answer == 'Y');

	}
};

