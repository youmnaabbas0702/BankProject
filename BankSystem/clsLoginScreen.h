#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "global.h"

class clsLoginScreen : protected clsScreen
{
	static void _Login()
	{
		bool LoginFailed = false;

		string UserName, Password;

		do
		{
			
			if (LoginFailed)
			{
				cout << "\nInvalid Username/Password!\n\n";
			}

			cout << "Enter Username: ";
			cin >> UserName;
			
			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenu();
	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

