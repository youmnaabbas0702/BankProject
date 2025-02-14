#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n__________________________________";
        cout << "\nFullName     :" << Client.FullName();
        cout << "\nAccountNumber:" << Client.AccountNumber;
        cout << "\nBalance      :" << Client.AccountBalance;
        cout << "\n__________________________________";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number was not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static double _ReadTransferAmount(clsBankClient SounrceClient)
    {
        cout << "\n\nEnter Amount to transfer: ";
        double Amount = 0;
        Amount = clsInputValidate::ReadDblNumberBetween(0, SounrceClient.AccountBalance, "\n\nAmount exceeds the available balance, enter another amount: ");
        return Amount;
    }

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		cout << "\n\nPlease enter account number to transfer from: ";

        string AccountNumberFrom = _ReadAccountNumber();

        clsBankClient ClientFrom = clsBankClient::Find(AccountNumberFrom);

        _PrintClient(ClientFrom);

        cout << "\n\nPlease enter account number to transfer to: ";

        string AccountNumberTo = _ReadAccountNumber();
        
        while (AccountNumberFrom == AccountNumberTo)
        {
            cout << "\nYou cannot transfer between same account, choose another one: ";
            AccountNumberTo = clsInputValidate::ReadString();
        }

        clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);

        _PrintClient(ClientTo);

        double Amount = _ReadTransferAmount(ClientFrom);

        char PerformTransaction = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n: ";
        cin >> PerformTransaction;

        if (PerformTransaction == 'y' || PerformTransaction == 'Y')
        {
            if (ClientFrom.Transfer(ClientTo,Amount))
            {
                cout << "Amount Transfered Successfully.\n";
                _PrintClient(ClientFrom);
                _PrintClient(ClientTo);
            }

            else {
                cout << "\nCannot transfer, an error occured.\n";
            }
        }

        else
        {
            cout << "\nOperation was cancelled.\n";
        }
	}
};

