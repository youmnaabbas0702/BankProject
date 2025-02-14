#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson
{
	enum enMode{EmptyMode, UpdateMode, AddNewMode};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector<string> Record = clsString::Split(Line, Separator);
		return clsBankClient(enMode::UpdateMode, Record[0], Record[1], Record[2], Record[3], Record[4], Record[5], stof(Record[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string Line = "";
		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone + Separator;
		Line += Client.AccountNumber + Separator;
		Line += Client.PinCode + Separator;
		Line += to_string(Client.AccountBalance);
		return Line;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while(getline(MyFile,Line))
			{
				vClients.push_back(_ConvertLineToClientObject(Line));
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient C : vClients)
			{
				if(C.MarkedForDelete == false)
				{
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		//get clients
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		//edit client info
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				break;
			}
		}

		//Save Clients to file again
		_SaveClientsDataToFile(vClients);
	}
	
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	string _PrepareTransferRecord(double Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
	{
		string datetime_str = clsDate::GetSystemDateTimeString();

		string Line = "";

		Line += datetime_str + Separator;
		Line += AccountNumber + Separator;
		Line += DestinationClient.AccountNumber + Separator;
		Line += to_string(Amount) + Separator;
		Line += to_string(AccountBalance) + Separator;
		Line += to_string(DestinationClient.AccountBalance) + Separator;
		Line += UserName;

		return Line;
	}

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string Line = _PrepareTransferRecord(Amount, DestinationClient, UserName);

		fstream LogFile;
		LogFile.open("TransferLog.txt", ios::out | ios::app);

		if (LogFile.is_open())
		{
			LogFile << Line << endl;
			LogFile.close();
		}
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord Record;

		vector<string> vTransferLogData;
		vTransferLogData = clsString::Split(Line, Seperator);

		Record.DateTime = vTransferLogData[0];
		Record.sAccNumber = vTransferLogData[1];
		Record.dAccNumber = vTransferLogData[2];
		Record.Amount = stod(vTransferLogData[3]);
		Record.sBalance = stod(vTransferLogData[4]);
		Record.dBalance = stod(vTransferLogData[5]);
		Record.UserName = vTransferLogData[6];
		return Record;

	}
public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccountNumber, string PinCode,float AccountBalance) :
		clsPerson(FirstName, LastName,Email,Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
	    _PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLogRecord
	{
		string DateTime;
		string sAccNumber;
		string dAccNumber;
		double Amount;
		double sBalance;
		double dBalance;
		string UserName;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber)) string AccountNumber;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void SetMarkedForDelete(bool MarkedForDelete)
	{
		_MarkedForDelete = MarkedForDelete;
	}

	bool GetMarkedForDelete()
	{
		return _MarkedForDelete;
	}

	__declspec(property(get = GetMarkedForDelete, put = SetMarkedForDelete)) bool MarkedForDelete;

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if(MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}
	
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		clsBankClient BankClient = Find(AccountNumber);
		if (BankClient.PinCode == PinCode)
		{
			return BankClient;
		}
		return _GetEmptyClientObject();
		
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults{svSucceeded, svFailedEmptyObject, svFailedAccountNumberExists};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
		
			if(IsEmpty())
			{
				return enSaveResults::svFailedEmptyObject;
			}

		case clsBankClient::UpdateMode:
			
			_Update();
			return enSaveResults::svSucceeded;

		case clsBankClient::AddNewMode:
			if (IsClientExist(AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			
			else
			{
				_AddNew();
				_Mode = clsBankClient::AddNewMode;
				return enSaveResults::svSucceeded;
			}
		
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		//delte client
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == GetAccountNumber())
			{
				C.MarkedForDelete = true;
				break;
			}
		}

		//Save Clients to file again
		_SaveClientsDataToFile(vClients);
		(*this) = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		double Sum = 0;
		for (clsBankClient C : vClients)
		{
			Sum += C.AccountBalance;
		}
		return Sum;
	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	
	bool WithDraw(double Amount)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	 bool Transfer( clsBankClient &ReceiverClient, double Amount, string UserName)
	{
		if (Amount > AccountBalance || AccountNumber == ReceiverClient.AccountNumber)
		{
			return false;
		}
		else
		{
			WithDraw(Amount);
			ReceiverClient.Deposit(Amount);

			_RegisterTransferLog(Amount, ReceiverClient, UserName);
			return true;
		}
	}

	 static vector<stTransferLogRecord> GetTransfersLogList()
	 {
		 vector<stTransferLogRecord> vTransfersLogList;

		 fstream LogFile;
		 LogFile.open("TransferLog.txt", ios::in);

		 if (LogFile.is_open())
		 {
			 string Line;
			 stTransferLogRecord TransferLogRecord;

			 while (getline(LogFile, Line))
			 {
				 TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
				 vTransfersLogList.push_back(TransferLogRecord);
			 }

			 LogFile.close();
		 }

		 return vTransfersLogList;
	 }
};

