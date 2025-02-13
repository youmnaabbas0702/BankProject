#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
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

public:
	static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Delete Client Screen");

        cout << "\nEnter AccountNumber: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number was not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        char DeleteClient = 'n';
        cout << "\nAre you sure you want to delete this client? y/n: ";
        cin >> DeleteClient;

        if(DeleteClient == 'y' || DeleteClient == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient deleted successfully :-)\n";
                _PrintClient(Client);
            }

            else {
                cout << "\nError client was not deleted.\n";
            }
        }
    }
};

