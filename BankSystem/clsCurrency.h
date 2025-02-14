#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"

using namespace std;

class clsCurrency
{
	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string> Record = clsString::Split(Line, Separator);
		return clsCurrency(enMode::UpdateMode, Record[0], Record[1], Record[2], stof(Record[3]));
	}

	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector<clsCurrency> vCurrencies;

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
			}
			MyFile.close();
		}
		return vCurrencies;
	}

	static string _ConvertClientObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string Line = "";
		Line += Currency.Country() + Separator;
		Line += Currency.CurrencyCode() + Separator;
		Line += Currency.CurrencyName() + Separator;
		Line += to_string(Currency.Rate());
		return Line;
	}

	static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrency C : vCurrencies)
			{
				Line = _ConvertClientObjectToLine(C);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrenciesDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency Find(string Identifier)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		Identifier = clsString::UpperAllString(Identifier);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Identifier || Currency.CurrencyCode() == Identifier)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C = clsCurrency::Find(CurrencyCode);
		return (!C.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}
};


