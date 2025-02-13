#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (Date.IsDate1EqualDate2(DateFrom) || Date.IsDate1EqualDate2(DateTo))
			return true;
		if (DateFrom.IsDate1AfterDate2(DateTo))
			clsDate::SwapDates(DateFrom, DateTo);
		return Date.IsDate1AfterDate2(DateFrom) && Date.IsDate1BeforeDate2(DateTo);
	}

	static short ReadShortNumber(string ErrorMsg = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMsg = "Number is not within range, Enter again:\n")
	{
		short Number = ReadIntNumber(ErrorMsg);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMsg;
			Number = ReadIntNumber(ErrorMsg);
		}

		return Number;
	}
	
	static int ReadIntNumber(string ErrorMsg = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMsg = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber(ErrorMsg);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMsg;
			Number = ReadIntNumber(ErrorMsg);
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMsg = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMsg = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber(ErrorMsg);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMsg;
			Number = ReadDblNumber(ErrorMsg);
		}

		return Number;
	}
	
	static float ReadFloatNumber(string ErrorMsg = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg;
		}
		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMsg = "Number is not within range, Enter again:\n")
	{
		float Number = ReadDblNumber(ErrorMsg);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMsg;
			Number = ReadDblNumber(ErrorMsg);
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return Date.IsValid();
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};

