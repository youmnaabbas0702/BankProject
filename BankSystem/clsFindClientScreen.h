#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsFindClientScreen : protected clsScreen
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
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Find Client Screen");

        string AccountNumber;
        cout << "Please Enter Client accountNumber: ";
        AccountNumber = clsInputValidate::ReadString();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "AccountNumber is not found, please enter another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);
    }
};

