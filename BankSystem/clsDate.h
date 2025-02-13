#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include "clsString.h"
#include <iomanip>
using namespace std;

class clsDate
{
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:
	//4 constructor overloads
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string Date)
	{
		vector<string> parts = clsString::Split(Date, "/");

		_Day = stoi(parts[0]);
		_Month = stoi(parts[1]);
		_Year = stoi(parts[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short NumOfDays, short Year)
	{
		clsDate Date = GetDateAfterNumberOfDays(0,1,Year,NumOfDays);
		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}


	//print date function
	void Print()
	{
		cout << DateToString() << endl;
	}


	//set and get properties
	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;
	__declspec(property(get = GetYear, put = SetYear)) short Year;


	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" +
			to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static short NumberOfWeekDay(short Day, short Month, short Year)
	{
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + 12 * a - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short NumberOfWeekDay()
	{
		return NumberOfWeekDay(_Day, _Month, _Year);
	}

	static string ShortNameOfDay(short DayOrder)
	{
		string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrDayNames[DayOrder];
	}



	static string ShortNameOfMonth(short Month)
	{
		string arrMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return arrMonthNames[Month - 1];
	}

	string ShortNameOfMonth()
	{
		return ShortNameOfMonth(_Month);
	}



	static bool IsLeapYear(short Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}




	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (Month == 1 || Month == 3 ||
			Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) ? 31 : 30;
	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}



	static void PrintMonthCalendar(short Month, short Year)
	{
		cout << "\n\t\t" << ShortNameOfMonth(Month) << "\n";
		cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		short firstDayOfMonth = NumberOfWeekDay(1, Month, Year);
		short daysInMonth = NumberOfDaysInMonth(Month, Year);

		for (short i = 0; i < firstDayOfMonth; i++)
		{
			cout << "     ";
		}

		for (short j = 1; j <= daysInMonth; j++)
		{
			cout << setw(3) << j << "  ";

			if ((firstDayOfMonth + j) % 7 == 0)
				cout << endl;
		}
	}

	void PrintMonthCalendar()
	{
		return PrintMonthCalendar(_Month, _Year);
	}



	static void PrintYearCalendar(short Year)
	{
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
			cout << endl;
		}
	}

	void PrintYearCalendar()
	{
		return PrintYearCalendar(_Year);
	}



	static short NumOfDaysFromBeginningOfYear(short Day, short Month, short Year)
	{
		short NumOfDays = 0;
		for (short i = 1; i < Month; i++)
		{
			NumOfDays += NumberOfDaysInMonth(i, Year);
		}
		NumOfDays += Day;

		return NumOfDays;
	}

	short NumOfDaysFromBeginningOfYear()
	{
		return NumOfDaysFromBeginningOfYear(_Day, _Month, _Year);
	}



	static void PrintDateForNumberOfDays(short Year, short TotalDays)
	{
		short Day = 0;
		short Month = 0;
		short MonthDays = 0;
		short NumOfDays = 0;

		for (int i = 1; i <= 12; i++)
		{
			MonthDays = NumberOfDaysInMonth(i, Year);
			NumOfDays += MonthDays;

			if (NumOfDays >= TotalDays)
			{
				Month = i;
				NumOfDays -= MonthDays;
				break;
			}
		}

		Day = TotalDays - NumOfDays;

		cout << "Date for [" << TotalDays << "] is: " << Day << "/" << Month << "/" << Year;
	}



	static clsDate GetDateAfterNumberOfDays(short Day, short Month, short Year, short DaysToAdd)
	{
		clsDate Date;
		short MonthDays = NumberOfDaysInMonth(Month, Year);
		short RemainingDays = DaysToAdd - (MonthDays - Day);
		Date.Month = ++Month;
		Date.Year = Year;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				if (Date.Month == 12)
				{
					Date.Month = 1;
					Date.Year++;
				}

				else
				{
					Date.Month++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	clsDate GetDateAfterNumberOfDays(short DaysToAdd)
	{
		return GetDateAfterNumberOfDays(_Day, _Month,_Year, DaysToAdd);
	}



	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{

		if (Date1.Year < Date2.Year)
			return true;
		if (Date1.Year == Date2.Year && Date1.Month < Date2.Month)
			return true;
		if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day)
			return true;

		return false;
	}

	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month ==
			Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
			: false;
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayOfMonth(clsDate Date1)
	{
		return Date1.Day == NumberOfDaysInMonth(Date1.Month, Date1.Year);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate
		Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	bool IsLastDayOfMonth()
	{
		return IsLastDayOfMonth(*this);
	}



	static bool IsLastMonthOfYear(short Month)
	{
		return Month == 12;
	}

	bool IsLastMonthOfYear()
	{
		return IsLastMonthOfYear(_Month);
	}



	static void AddOneDayToDate(clsDate &Date)
	{
		if (IsLastDayOfMonth(Date) && IsLastMonthOfYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
			
		}
		else if (IsLastDayOfMonth(Date))
		{
			Date.Day = 1;
			Date.Month++;
		}
		else
			Date.Day++;
	}

	void AddOneDayToDate()
	{
		return AddOneDayToDate(*this);
	}


	static clsDate GetSystemDate()
	{
		clsDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
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

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SawpFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			AddOneDayToDate(Date1);
		}
		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}


	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth,
			clsDate::GetSystemDate(), true);
	}


	static void IncreaseDateByXDays(short Days, clsDate &Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			AddOneDayToDate(Date);
		}
	}

	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	static void IncreaseDateByOneWeek(clsDate &Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			 AddOneDayToDate(Date);
		}

	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static void IncreaseDateByXWeeks(short Weeks, clsDate &Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			IncreaseDateByOneWeek(Date);
		}
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	static void IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static void IncreaseDateByXMonths(short Months, clsDate &Date)
	{
		for (short i = 0; i < Months; i++)
		{
			IncreaseDateByOneMonth(Date);
		}

	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static void IncreaseDateByOneYear(clsDate &Date)
	{
		Date.Year++;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static void IncreaseDateByXYears(short Years, clsDate &Date)
	{
		Date.Year += Years;

	}

	void IncreaseDateByXYears(short Years)
	{
		return IncreaseDateByXYears(Years, *this);
	}

	static void IncreaseDateByOneDecade(clsDate &Date)
	{
		Date.Year += 10;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static void IncreaseDateByXDecades(short Decades, clsDate Date)
	{
		Date.Year += 10 * Decades;
	}

	void IncreaseDateByXDecades(short Decades)
	{
		return IncreaseDateByXDecades(Decades, *this);
	}

	static void IncreaseDateByOneCentury(clsDate& Date)
	{
		Date.Year += 100;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static void IncreaseDateByOneMellinnium(clsDate& Date)
	{
		Date.Year += 1000;
	}

	void IncreaseDateByOneMellinnium()
	{
		IncreaseDateByOneMellinnium(*this);
	}



	static bool IsEndOfWeek(clsDate Date)
	{
		return NumberOfWeekDay(Date.Day, Date.Month, Date.Year) == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = NumberOfWeekDay(Date.Day, Date.Month, Date.Year);
		return DayIndex == 6 || DayIndex == 5;
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - NumberOfWeekDay(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date)
	{
		return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
	}

	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short DaysUntilEndOfYear(clsDate Date)
	{
		return NumberOfDaysInYear(Date.Year) - NumOfDaysFromBeginningOfYear(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}


	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short Period = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (!IsWeekEnd(DateFrom))
				Period++;

			AddOneDayToDate(DateFrom);
		}

		return Period;
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate
		DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;
			AddOneDayToDate(DateFrom);
		}
		return Days;
	}

	static clsDate DateOfReturnFromVacation(clsDate DateFrom, short NumOfDays)
	{
		while (NumOfDays > 0)
		{
			if (!IsWeekEnd(DateFrom))
			{
				NumOfDays--;
			}
			AddOneDayToDate(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			AddOneDayToDate(DateFrom);
		}

		return DateFrom;
	}

	clsDate DateOfReturnFromVacation(short NumOfDays)
	{
		return DateOfReturnFromVacation(*this, NumOfDays);
	}


	static bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day>31)
			return false;
		if (Date.Month < 1 || Date.Month>12)
			return false;
		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > DaysInMonth)
		{
			return false;
		}
		return true;
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

};

