#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
    static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord Record)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << Record.DateTime;
        cout << "| " << setw(20) << left << Record.UserName;
        cout << "| " << setw(12) << left << Record.Password;
        cout << "| " << setw(20) << left << Record.Permissions;
    }

public:
	static void ShowLginRegisterList()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLogins = clsUser::GetLoginRegisterList();

        string Title = "\t  Login register List Screen";
        string SubTitle = "\t    (" + to_string(vLogins.size()) + ") Records(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogins.size() == 0)
            cout << "\t\t\t\tNo login records Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord record : vLogins)
            {

                _PrintLoginRegisterRecord(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


	}
};

