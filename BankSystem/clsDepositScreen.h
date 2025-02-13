#pragma once
#include "clsScreen.h"

class clsDepositScreen : protected clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] was not found.";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "\nPlease enter deposit amount? ";
        double Amount = clsInputValidate::ReadDblNumber();

        char PerformTransaction = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n: ";
        cin >> PerformTransaction;

        if (PerformTransaction == 'y' || PerformTransaction == 'Y')
        {
            Client.Deposit(Amount);
            cout << "Amount Deposited Successfully.\n";
            cout << "\nNew Balance is: " << Client.AccountBalance;

        }

        else
        {
            cout << "\nOperation was cancelled.\n";
        }
	}
};

