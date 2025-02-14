#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
    static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecord Record)
    {
        cout << setw(8) << left << "" << "| " << setw(22) << left << Record.DateTime;
        cout << "| " << setw(12) << left << Record.sAccNumber;
        cout << "| " << setw(12) << left << Record.dAccNumber;
        cout << "| " << setw(12) << left << Record.Amount;
        cout << "| " << setw(12) << left << Record.sBalance;
        cout << "| " << setw(12) << left << Record.dBalance;
        cout << "| " << setw(12) << left << Record.UserName;
    }

public:
	static void ShowTransferLogScreen()
	{
        vector <clsBankClient::stTransferLogRecord> vTransfers = clsBankClient::GetTransfersLogList();

        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransfers.size()) + ") Records(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
        cout << "| " << left << setw(12) << "s.Acct";
        cout << "| " << left << setw(12) << "d.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "s.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(12) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        if (vTransfers.size() == 0)
            cout << "\t\t\t\tNo login records Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord record : vTransfers)
            {

                _PrintTransferLogRecord(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

	}
};

