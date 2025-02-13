#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "global.h"
//#include "clsLoginScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };
    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? : ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 8);
        return Choice;
    }

    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenu()
    {
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        //clsLoginScreen::ShowLoginScreen(); /* circular reference */
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case clsMainScreen::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;
        }
        case clsMainScreen::eExit:
        {
            system("cls");
            _Logout();
            break;
        }
        default:
            break;
        }
    }

public:
	static void ShowMainMenu()
	{
		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

