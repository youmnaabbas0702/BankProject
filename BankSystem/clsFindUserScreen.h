#pragma once
#include "clsUser.h"
#include "clsScreen.h"

class clsFindUserScreen : protected clsScreen 
{
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

public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }

        else
        {
            cout << "\nUser was not found :-(\n";
        }

        _PrintUser(User);
    }
};

