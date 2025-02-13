#pragma once
#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
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
	static void ShowDeleteUserScreen()
	{
        _DrawScreenHeader("\t  Delete User Screen");

        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User? y/n: ";
        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError, User was not deleted.\n";
            }
        }
	}
};

