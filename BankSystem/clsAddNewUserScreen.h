#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsAddNewUserScreen : protected clsScreen
{
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();
        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n__________________________________";
        cout << "\nFirstName    :" << User.FirstName;
        cout << "\nLastName     :" << User.LastName;
        cout << "\nFullName     :" << User.FullName();
        cout << "\nEmail        :" << User.Email;
        cout << "\nPhone        :" << User.Phone;
        cout << "\nPassword     :" << User.Password;
        cout << "\nPermissions     :" << User.Permissions;
        cout << "\n__________________________________";
    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        
        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }
        
        cout << "\nCurrency Exchange? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pCurrencyExchange;
        }

        return Permissions;

    }

public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");

        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is used, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::svSucceeded:
            cout << "\nUser Added successfully :-)\n";
            _PrintUser(NewUser);
            break;
        case clsUser::svFaildEmptyObject:
            cout << "\n Error, User was not saved because it is empty.";
            break;
        default:
            break;
        }
    }
};

