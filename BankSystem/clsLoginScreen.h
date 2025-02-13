#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "global.h"

class clsLoginScreen : protected clsScreen
{
	static bool _Login()
	{
		bool LoginFailed = false;

		string UserName, Password;

		short Trials = 3;

		do
		{
			
			if (LoginFailed)
			{
				cout << "\nInvalid Username/Password!\n";
				Trials--;
				cout << "You have " << Trials << " trials to Login.\n\n";

				if (Trials == 0)
				{
					cout << "You are locked after 3 failed trials\n\n";
					return true;
				}
			}

			cout << "Enter Username: ";
			cin >> UserName;
			
			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenu();

		return false;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

