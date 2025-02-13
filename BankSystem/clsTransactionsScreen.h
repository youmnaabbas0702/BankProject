#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h";
#include "clsWithDrawScreen.h"
#include "clsAllBalancesScreen.h"
#include "clsUser.h"

class clsTransactionsScreen : protected clsScreen
{
    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithDraw = 2, 
        eShowTotalBalance = 3, eShowMainMenu = 4
    };

    static short _ReadTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? : ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4);
        return Choice;
    }
    
    static  void _GoBackToTransactionsMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menu...\n";

        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithDrawScreen()
    {
        clsWithDrawScreen::ShowWithDrawScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
        clsAllBalancesScreen::ShowTotalBalances();
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
        case clsTransactionsScreen::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        case clsTransactionsScreen::eWithDraw:
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenu();
            break;
        case clsTransactionsScreen::eShowTotalBalance:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        case clsTransactionsScreen::eShowMainMenu:
            break;
        default:
            break;
        }
    }

public:
    static void ShowTransactionsMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return;
        }
        system("cls");

        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
    }

};

