#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsAddNewClientScreen : protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "\nEnter Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

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
    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Add New Client Screen");

        cout << "\nEnter AccountNumber: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is used, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::svSucceeded:
            cout << "\nAccount Added successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::svFailedEmptyObject:
            cout << "\n Error, Account was not saved because it is empty.";
            break;
        default:
            break;
        }
    }

};

