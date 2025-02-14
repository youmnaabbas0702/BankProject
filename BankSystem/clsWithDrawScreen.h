#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsWithDrawScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n__________________________________";
        cout << "\nFirstName    :" << Client.FirstName;
        cout << "\nLastName     :" << Client.LastName;
        cout << "\nFullName     :" << Client.FullName();
        cout << "\nEmail        :" << Client.Email;
        cout << "\nPhone        :" << Client.Phone;
        cout << "\nAccountNumber:" << Client.AccountNumber;
        cout << "\nPassword     :" << Client.PinCode;
        cout << "\nBalance      :" << Client.AccountBalance;
        cout << "\n__________________________________";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:
    static void ShowWithDrawScreen()
    {
        _DrawScreenHeader("\tWithDraw Screen");
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] was not found.";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "\nPlease enter WithDraw amount? ";
        double Amount = clsInputValidate::ReadDblNumberBetween(5, Client.AccountBalance);

        char PerformTransaction = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n: ";
        cin >> PerformTransaction;

        if (PerformTransaction == 'y' || PerformTransaction == 'Y')
        {
            if(Client.WithDraw(Amount))
            {
                cout << "Amount Withdrewn Successfully.\n";
                cout << "\nNew Balance is: " << Client.AccountBalance;
            }

            else {
                cout << "\nCannot WithDraw, Insufficient Balance!\n";
                cout << "\nAmount to WithDraw is: " << Amount;
                cout << "\nYour Balance is: " << Client.AccountBalance;
            }
        }

        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};

