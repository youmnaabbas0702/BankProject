#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:

	enum enCharType {
		SmallLetter, CapitalLetter,
		SpecialCharacter, Digit, MixChars };

	static void SRand()
	{
		//seed the random number generator in C++, called once only in the main function
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int randd = rand();
		int randNum = randd % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomCharacter(enCharType chartype)
	{
		switch (chartype)
		{
		case SmallLetter:
			return char(RandomNumber(97, 122));
		case CapitalLetter:
			return char(RandomNumber(65, 90));
		case SpecialCharacter:
			return char(RandomNumber(33, 47));
		case Digit:
			return char(RandomNumber(48, 57));
		case MixChars:
			return char(RandomNumber(48, 122));
		}
	}

	static string GenerateWord(enCharType characterType, short Length)
	{
		string Word = "";
		for (int i = 1; i <= Length; i++)
			Word += GetRandomCharacter(characterType);

		return Word;
	}

	static string GenerateKey(enCharType characterType)
	{
		string Key = "";
		for (int i = 1; i <= 4; i++)
		{
			Key += GenerateWord(characterType, 4);
			if (i < 4)
				Key += '-';
		}
		return Key;
	}

	static void GenerateKeys(short NumberofKeys, enCharType characterType)
	{
		for (short i = 1; i <= NumberofKeys; i++)
		{
			cout << "Key[" << i << "]:";
			cout << GenerateKey(characterType);
			cout << endl;
		}
	}

	static void Swap(int &Num1, int &Num2)
	{
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	
	static void Swap(double &Num1, double &Num2)
	{
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}
	
	static void Swap(string &Word1, string &Word2)
	{
		string Temp;
		Temp = Word1;
		Word1 = Word2;
		Word2 = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;
		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;
		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}

	static void ShuffleArray(int arr[100], int length)
	{
		for (int i = 0; i < length; i++) {
			int index1 = RandomNumber(0, length - 1);
			int index2 = RandomNumber(0, length - 1);

			Swap(arr[index1], arr[index2]);
		}
	}

	static void ShuffleArray(string arr[100], int length)
	{
		for (int i = 0; i < length; i++) {
			int index1 = RandomNumber(0, length - 1);
			int index2 = RandomNumber(0, length - 1);

			Swap(arr[index1], arr[index2]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int length, int From, int To)
	{
		cout << "\nEnter number of elements:\n";
		cin >> length;

		for (int i = 0; i < length; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void CopyArray(int oldarray[100], int newarray[100], int length)
	{
		for (int i = 0; i < length; i++)
		{
			newarray[i] = oldarray[i];
		}
	}

	static void SumOf2Arrays(int arr1[100], int arr2[100], int sumarray[100], int length)
	{
		for (int i = 0; i < length; i++)
			sumarray[i] = arr1[i] + arr2[i];
	}

	static void FillArrayWithRandomWords(string WordsArray[100], int arrLength, enCharType characterType, short Wordlength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			WordsArray[i] = GenerateWord(characterType, Wordlength);
		}
	}

	static void FillArrayWithRandomKeys(string KeysArray[100], short NumberofKeys, enCharType characterType)
	{
		for (short i = 0; i < NumberofKeys; i++)
		{
			KeysArray[i] = GenerateKey(characterType);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string tabs = "";

		for (int i = 1; i <= NumberOfTabs; i++)
		{
			tabs = tabs + "\t";
			cout << tabs;
		}
		return tabs;

	}

	static string  EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
			return "";

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One", "Tow", "Three", "Four", "Five", "Six", "Seven",
			"Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourtheen", "Fifteen",
			"Sixteen", "Seventeen", "Eighteen", "Nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "", "", "Twenty", "Thirty","Forty", "Fifty", "Sixty",
			"Seventy", "Eighty", "Ninety" };
			return arr[Number / 10] + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}
	}

	static string EncryptText(string Text, int EncryptionKey = 2)
	{
		string OriginalText = Text;
		string EncryptedText = "";

		for (int i = 0; i < OriginalText.length(); i++)
		{
			int index = (int)OriginalText[i] + EncryptionKey;
			EncryptedText += char(index);
		}

		return EncryptedText;
	}

	static string DecryptText(string Text, int EncryptionKey = 2)
	{
		string EncryptedText = Text;
		string OriginalText = "";

		for (int i = 0; i < EncryptedText.length(); i++)
		{
			int index = (int)EncryptedText[i] - EncryptionKey;
			OriginalText += char(index);
		}

		return OriginalText;
	}
};

