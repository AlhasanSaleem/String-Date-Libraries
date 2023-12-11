#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate
{

	private:

		short _Day   = 1;
		short _Month = 1;
		short _Year  = 1900;

	public:

		clsDate()
		{
			time_t t     = time(0);
			tm* now      = localtime(&t);
			this->_Day   = now->tm_mday;
			this->_Month = now->tm_mon + 1;
			this->_Year  = now->tm_year + 1900;
		}

		clsDate(string sDate)
		{	
			vector <string> vDate;
			vDate = clsString::Split(sDate, "/");

			this->_Day   = stoi(vDate[0]);
			this->_Month = stoi(vDate[1]);
			this->_Year  = stoi(vDate[2]);
		}

		clsDate(short Day, short Month, short Year)
		{	
			this->_Day   = Day;
			this->_Month = Month;
			this->_Year  = Year;			
		}

		clsDate(short DateOrderInYear, short Year)
		{
			//This will construct a date by date order in year
			clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
			this->_Day    = Date1.GetDay();
			this->_Month  = Date1.GetMonth();
			this->_Year   = Date1.GetYear();
		}

		void SetDay(short Day)
		{
			this->_Day = Day;
		}

		short GetDay()
		{
			return this->_Day;
		}
		// __declspec(property(get = GetDay, put = SetDay)) short Day;

		void SetMonth(short Month) 
		{
			this->_Month = Month;
		}

		short GetMonth()
		{
			return this->_Month;
		}
		// __declspec(property(get = GetMonth, put = SetMonth)) short Month;

		void SetYear(short Year) 
		{
			this->_Year = Year;
		}

		short GetYear()
		{
			return this->_Year;
		}
		// __declspec(property(get = GetYear, put = SetYear)) short Year;

		void Print()
		{
			cout << DateToString() << endl;
		}

		static clsDate GetSystemDate()
		{
			//system date
			time_t t = time(0);
			tm* now  = localtime(&t);
			
			short Day, Month, Year;

			Year  = now->tm_year + 1900;
			Month = now->tm_mon + 1;
			Day   = now->tm_mday;

			return clsDate(Day, Month, Year);
		}

		static bool IsValidDate(clsDate Date)
		{
			if (Date._Day < 1 || Date._Day > 31)
				return false;

			if (Date._Month < 1 || Date._Month > 12)
				return false;

			if (Date._Month == 2)
			{
				if (isLeapYear(Date._Year))
				{
					if (Date._Day > 29)
						return false;
				}
				else
				{
					if (Date._Day > 28)
						return false;
				}
			}

			short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);

			if (Date._Day > DaysInMonth)
				return false;

			return true;
		}
		
		bool IsValid()
		{
			return IsValidDate(*this);
		}

		static string DateToString(clsDate Date)
		{
			return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
		}

		string DateToString()
		{
			return DateToString(*this);
		}

		static bool isLeapYear(short Year)
		{
			// if year is divisible by 4 AND not divisible by 100
			// OR if year is divisible by 400
			// then it is a leap year
			return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
		}

		bool isLeapYear()
		{
			return clsDate::isLeapYear(this->_Year);
		}

		static short NumberOfDaysInAYear(short Year)
		{
			return clsDate::isLeapYear(Year) ? 365 : 364;
		}

		short NumberOfDaysInAYear()
		{
			return clsDate::NumberOfDaysInAYear(this->_Year);
		}

		static short NumberOfHoursInAYear(short Year)
		{
			return clsDate::NumberOfDaysInAYear(Year) * 24;
		}

		short NumberOfHoursInAYear()
		{
			return clsDate::NumberOfHoursInAYear(this->_Year);
		}

		static int NumberOfMinutesInAYear(short Year)
		{
			return clsDate::NumberOfHoursInAYear(Year) * 60;
		}

		int NumberOfMinutesInAYear()
		{
			return clsDate::NumberOfMinutesInAYear(this->_Year);
		}

		static int NumberOfSecondsInAYear(short Year)
		{
			return clsDate::NumberOfMinutesInAYear(Year) * 60;
		}

		int NumberOfSecondsInAYear()
		{
			return clsDate::NumberOfSecondsInAYear(this->_Year);
		}

		static short NumberOfDaysInAMonth(short Month, short Year)
		{
			if (Month < 1 || Month > 12)
				return  0;

			int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			return (Month == 2) ? (clsDate::isLeapYear(Year) ? 29 : 28) : days[Month - 1];
		}

		short NumberOfDaysInAMonth()
		{
			return clsDate::NumberOfDaysInAMonth(this->_Month, this->_Year);
		}

		static short NumberOfHoursInAMonth(short Month, short Year)
		{
			return clsDate::NumberOfDaysInAMonth(Month, Year) * 24;
		}

		short NumberOfHoursInAMonth()
		{
			return clsDate::NumberOfDaysInAMonth(this->_Month, this->_Year) * 24;
		}

		static int NumberOfMinutesInAMonth(short Month, short Year)
		{
			return clsDate::NumberOfHoursInAMonth(Month, Year) * 60;
		}

		int NumberOfMinutesInAMonth()
		{
			return clsDate::NumberOfHoursInAMonth(this->_Month, this->_Year) * 60;
		}

		static int NumberOfSecondsInAMonth(short Month, short Year)
		{
			return clsDate::NumberOfMinutesInAMonth(Month, Year) * 60;
		}

		int NumberOfSecondsInAMonth()
		{
			return clsDate::NumberOfMinutesInAMonth(this->_Month, this->_Year) * 60;
		}

		static short DayOfWeekOrder(short Day, short Month, short Year)
		{
			short a, y, m;
			a = (14 - Month) / 12;
			y = Year - a;
			m = Month + (12 * a) - 2;
			// Gregorian:
			//0:sun, 1:Mon, 2:Tue...etc
			return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		}

		short DayOfWeekOrder()
		{
			return clsDate::DayOfWeekOrder(this->_Day, this->_Month, this->_Year);
		}

		static string DayShortName(short DayOfWeekOrder)
		{
			string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
			return arrDayNames[DayOfWeekOrder];
		}

		static string DayShortName(short Day, short Month, short Year)
		{
			string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
			return arrDayNames[clsDate::DayOfWeekOrder(Day, Month, Year)];
		}

		string DayShortName()
		{
			string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
			return arrDayNames[clsDate::DayOfWeekOrder(this->_Day, this->_Month, this->_Year)];
		}

		static string MonthShortName(short MonthNumber)
		{
			string Months[12] = { "Jan", "Feb", "Mar",
								  "Apr", "May", "Jun",
								  "Jul", "Aug", "Sep",
								  "Oct", "Nov", "Dec"
			                    };

			return (Months[MonthNumber - 1]);
		}

		string MonthShortName()
		{
			return clsDate::MonthShortName(this->_Month);
		}

		static void PrintMonthCalendar(short Month, short Year)
		{
			int NumberOfDays;

			// Index of the day from 0 to 6
			int current = clsDate::DayOfWeekOrder(1, Month, Year);

			NumberOfDays = clsDate::NumberOfDaysInAMonth(Month, Year);

			// Print the current month name
			printf("\n  _______________%s_______________\n\n", clsDate::MonthShortName(Month).c_str());

			// Print the columns
			printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

			// Print appropriate spaces
			int i;
			for (i = 0; i < current; i++)
				printf("     ");

			for (int j = 1; j <= NumberOfDays; j++)
			{
				printf("%5d", j);


				if (++i == 7)
				{
					i = 0;
					printf("\n");
				}
			}

			printf("\n  _________________________________\n");
		}

		void PrintMonthCalendar()
		{
			clsDate::PrintMonthCalendar(this->_Month,this-> _Year);
		}

		static void PrintYearCalendar(int Year)
		{
			printf("\n  _________________________________\n\n");
			printf("           Calendar - %d\n", Year);
			printf("  _________________________________\n");


			for (int i = 1; i <= 12; i++)
			{
				clsDate::PrintMonthCalendar(i, Year);
			}

			return;
		}

		void PrintYearCalendar()
		{
			printf("\n  _________________________________\n\n");
			printf("           Calendar - %d\n", this->_Year);
			printf("  _________________________________\n");


			for (int i = 1; i <= 12; i++)
			{
				clsDate::PrintMonthCalendar(i, this->_Year);
			}

			return;
		}

		static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
		{
			short TotalDays = 0;

			for (int i = 1; i <= Month - 1; i++)
			{
				TotalDays += clsDate::NumberOfDaysInAMonth(i, Year);
			}

			TotalDays += Day;

			return TotalDays;
		}

		short DaysFromTheBeginingOfTheYear()
		{
			short TotalDays = 0;

			for (int i = 1; i <= this->_Month - 1; i++)
			{
				TotalDays += clsDate:: NumberOfDaysInAMonth(i, this->_Year);
			}

			TotalDays += this->_Day;

			return TotalDays;
		}

		static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
		{
			clsDate Date;
			short RemainingDays = DateOrderInYear;
			short MonthDays     = 0;

			Date._Year = Year;
			Date._Month = 1;

			while (true)
			{
				MonthDays = clsDate::NumberOfDaysInAMonth(Date._Month, Year);

				if (RemainingDays > MonthDays)
				{
					RemainingDays -= MonthDays;
					Date._Month++;
				}
				else
				{
					Date._Day = RemainingDays;
					break;
				}

			}

			return Date;
		}

		void AddDays(short Days)
		{
			short RemainingDays = Days + clsDate::DaysFromTheBeginingOfTheYear(this->_Day, this->_Month, this->_Year);
			short MonthDays     = 0;
			this->_Month        = 1;

			while (true)
			{
				MonthDays = NumberOfDaysInAMonth(this->_Month, this->_Year);

				if (RemainingDays > MonthDays)
				{
					RemainingDays -= MonthDays;
					this->_Month++;

					if (this->_Month > 12)
					{
						this->_Month = 1;
						this->_Year++;

					}
				}
				else
				{
					this->_Day = RemainingDays;
					break;
				}
			}
		}

		static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
		{
			return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
		}

		bool IsDateBeforeDate2(clsDate Date2)
		{
			//note: *this sends the current object :-) 
			return clsDate::IsDate1BeforeDate2(*this, Date2);
		}

		static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
		{
			return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
		}

		bool IsDateEqualDate2(clsDate Date2)
		{
			return clsDate::IsDate1EqualDate2(*this, Date2);
		}

		static bool IsLastDayInMonth(clsDate Date)
		{
			return (Date._Day == clsDate::NumberOfDaysInAMonth(Date._Day, Date._Year));
		}

		bool IsLastDayInMonth()
		{
			return clsDate::IsLastDayInMonth(*this);
		}

		static bool IsLastMonthInYear(short Month)
		{
			return (Month == 12);
		}

		static clsDate AddOneDay(clsDate Date)
		{
			if (clsDate::IsLastDayInMonth(Date))
			{
				if (clsDate::IsLastMonthInYear(Date._Month))
				{
					Date._Year++;
					Date._Month = 1;
					Date._Day = 1;
				}
				else
				{
					Date._Month++;
					Date._Day = 1;
				}
			}
			else
			{
				Date._Day++;
			}

			return Date;
		}

		void AddOneDay()
		{
			*this = clsDate::AddOneDay(*this);
		}

		static void SwapDates(clsDate &Date1, clsDate &Date2)
		{
			clsDate TempDate;

			TempDate = Date1;
			Date1    = Date2;
			Date2    = TempDate;
		}

		static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
		{
			//this will take care of negative diff
			int Days = 0;
			short SawpFlagValue = 1;

			if (!clsDate::IsDate1BeforeDate2(Date1, Date2))
			{
				//Swap Dates 
				clsDate::SwapDates(Date1, Date2);
				SawpFlagValue = -1;

			}

			while (IsDate1BeforeDate2(Date1, Date2))
			{
				Days++;
				Date1 = AddOneDay(Date1);
			}

			return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
		}

		int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
		{
			return clsDate::GetDifferenceInDays(*this, Date2, IncludeEndDay);
		}

		static short CalculateMyAgeInDays(clsDate DateOfBirth)
		{
			return clsDate::GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
		}
		//above no need to have nonstatic function for the object because it does not depend on any data from it.

		static clsDate IncreaseDateByOneWeek(clsDate & Date)
		{
			for (int i = 1; i <= 7; i++)
			{
				Date = clsDate::AddOneDay(Date);
			}

			return Date;
		}

		void IncreaseDateByOneWeek()
		{
			clsDate::IncreaseDateByOneWeek(*this);
		}

		clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
		{
			for (short i = 1; i <= Weeks; i++)
			{
				Date = clsDate::IncreaseDateByOneWeek(Date);
			}
			return Date;
		}

		void IncreaseDateByXWeeks(short Weeks)
		{
			clsDate::IncreaseDateByXWeeks(Weeks, *this);
		}

		clsDate IncreaseDateByOneMonth(clsDate& Date)
		{
			if (Date._Month == 12)
			{
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Month++;
			}

			//last check day in date should not exceed max days in the current month
			// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
			// be 28/2/2022
			short NumberOfDaysInCurrentMonth = clsDate::NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (Date._Day > NumberOfDaysInCurrentMonth)
			{
				Date._Day = NumberOfDaysInCurrentMonth;
			}

			return Date;
		}

		void IncreaseDateByOneMonth()
		{
			clsDate::IncreaseDateByOneMonth(*this);
		}

		clsDate IncreaseDateByXDays(short Days, clsDate& Date)
		{
			for (short i = 1; i <= Days; i++)
			{
				Date = clsDate::AddOneDay(Date);
			}
			return Date;
		}

		void IncreaseDateByXDays(short Days)
		{
			clsDate::IncreaseDateByXDays(Days, *this);
		}

		clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
		{
			for (short i = 1; i <= Months; i++)
			{
				Date = clsDate::IncreaseDateByOneMonth(Date);
			}
			return Date;
		}

		void IncreaseDateByXMonths(short Months)
		{
			clsDate::IncreaseDateByXMonths(Months, *this);
		}

		static clsDate IncreaseDateByOneYear(clsDate& Date)
		{
			Date._Year++;
			return Date;
		}

		void IncreaseDateByOneYear()
		{
			clsDate::IncreaseDateByOneYear(*this);
		}

		clsDate IncreaseDateByXYears(short Years, clsDate &Date)
		{
			Date._Year += Years;
			return Date;
		}

		void IncreaseDateByXYears(short Years)
		{
			clsDate::IncreaseDateByXYears(Years, *this);
		}

		clsDate IncreaseDateByOneDecade(clsDate& Date)
		{
			//Period of 10 years
			Date._Year += 10;
			return Date;
		}

		void IncreaseDateByOneDecade()
		{
			clsDate::IncreaseDateByOneDecade(*this);
		}

		clsDate IncreaseDateByXDecades(short Decade, clsDate &Date)
		{
			Date._Year += Decade * 10;
			return Date;
		}

		void IncreaseDateByXDecades(short Decade)
		{
			clsDate::IncreaseDateByXDecades(Decade, *this);
		}

		clsDate IncreaseDateByOneCentury(clsDate& Date)
		{
			//Period of 100 years
			Date._Year += 100;
			return Date;
		}

		void IncreaseDateByOneCentury()
		{
			clsDate::IncreaseDateByOneCentury(*this);
		}

		clsDate IncreaseDateByOneMillennium(clsDate& Date)
		{
			//Period of 1000 years
			Date._Year += 1000;
			return Date;
		}

		void IncreaseDateByOneMillennium()
		{
			clsDate::IncreaseDateByOneMillennium(*this);
		}

		static clsDate DecreaseDateByOneDay(clsDate Date)
		{
			if (Date._Day == 1)
			{
				if (Date._Month == 1)
				{
					Date._Month = 12;
					Date._Day = 31;
					Date._Year--;
				}
				else
				{

					Date._Month--;
					Date._Day = clsDate::NumberOfDaysInAMonth(Date._Month, Date._Year);
				}
			}
			else
			{
				Date._Day--;
			}

			return Date;
		}

		void DecreaseDateByOneDay()
		{
			clsDate::DecreaseDateByOneDay(*this);
		}

		static clsDate DecreaseDateByOneWeek(clsDate &Date)
		{
			for (int i = 1; i <= 7; i++)
			{
				Date = clsDate::DecreaseDateByOneDay(Date);
			}

			return Date;
		}

		void DecreaseDateByOneWeek()
		{
			clsDate::DecreaseDateByOneWeek(*this);
		}

		static clsDate DecreaseDateByXWeeks(short Weeks, clsDate &Date)
		{
			for (short i = 1; i <= Weeks; i++)
			{
				Date = clsDate::DecreaseDateByOneWeek(Date);
			}
			return Date;
		}

		void DecreaseDateByXWeeks(short Weeks)
		{
			clsDate::DecreaseDateByXWeeks(Weeks ,*this);
		}

		static clsDate DecreaseDateByOneMonth(clsDate &Date)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Year--;
			}
			else
				Date._Month--;

			//last check day in date should not exceed max days in the current month
			// example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
			// be 28/2/2022
			short NumberOfDaysInCurrentMonth = clsDate::NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (Date._Day > NumberOfDaysInCurrentMonth)
			{
				Date._Day = NumberOfDaysInCurrentMonth;
			}

			return Date;
		}

		void DecreaseDateByOneMonth()
		{
			clsDate::DecreaseDateByOneMonth(*this);
		}

		static clsDate DecreaseDateByXDays(short Days, clsDate &Date)
		{
			for (short i = 1; i <= Days; i++)
			{
				Date = clsDate::DecreaseDateByOneDay(Date);
			}
			return Date;
		}

		void DecreaseDateByXDays(short Days)
		{
			clsDate::DecreaseDateByXDays(Days, *this);
		}

		static clsDate DecreaseDateByXMonths(short Months, clsDate &Date)
		{
			for (short i = 1; i <= Months; i++)
			{
				Date = clsDate::DecreaseDateByOneMonth(Date);
			}
			return Date;
		}

		void DecreaseDateByXMonths(short Months)
		{
			clsDate::DecreaseDateByXMonths(Months, *this);
		}

		static clsDate DecreaseDateByOneYear(clsDate &Date)
		{
			Date._Year--;
			return Date;
		}

		void DecreaseDateByOneYear()
		{
			clsDate::DecreaseDateByOneYear(*this);
		}

		static clsDate DecreaseDateByXYears(short Years, clsDate &Date)
		{
			Date._Year -= Years;
			return Date;
		}

		void DecreaseDateByXYears(short Years)
		{
			clsDate::DecreaseDateByXYears(Years ,*this);
		}

		static clsDate DecreaseDateByOneDecade(clsDate &Date)
		{
			//Period of 10 years
			Date._Year -= 10;
			return Date;
		}

		void DecreaseDateByOneDecade()
		{
			clsDate::DecreaseDateByOneDecade(*this);
		}

		static clsDate DecreaseDateByXDecades(short Decades, clsDate &Date)
		{
			Date._Year -= Decades * 10;
			return Date;
		}

		void DecreaseDateByXDecades(short Decades)
		{
			clsDate::DecreaseDateByXDecades(Decades, *this);
		}

		static clsDate DecreaseDateByOneCentury(clsDate &Date)
		{
			//Period of 100 years
			Date._Year -= 100;
			return Date;
		}

		void DecreaseDateByOneCentury()
		{
			clsDate::DecreaseDateByOneCentury(*this);
		}

		static clsDate DecreaseDateByXCenturies(short Centuries, clsDate &Date)
		{
			//Period of X Centuries
			Date._Year -= Centuries * 100;
			return Date;
		}

		void DecreaseDateByXCenturies(short Centuries)
		{
			clsDate::DecreaseDateByXCenturies(Centuries, *this);
		}

		static clsDate DecreaseDateByOneMillennium(clsDate &Date)
		{
			//Period of (One Millennium) 1000 years
			Date._Year -= 1000;
			return Date;
		}

		void DecreaseDateByOneMillennium()
		{
			clsDate::DecreaseDateByOneMillennium(*this);
		}

		static short IsEndOfWeek(clsDate Date)
		{
			return clsDate::DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
		}

		short IsEndOfWeek()
		{
			return clsDate::IsEndOfWeek(*this);
		}

		static bool IsWeekEnd(clsDate Date)
		{
			//Weekends are Fri and Sat
			short DayIndex = clsDate::DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
			return (DayIndex == 5 || DayIndex == 6);
		}

		bool IsWeekEnd()
		{
			return clsDate::IsWeekEnd(*this);
		}

		static bool IsBusinessDay(clsDate Date)
		{
			//Weekends are Sun,Mon,Tue,Wed and Thur

			/*
			short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
			return  (DayIndex >= 5 && DayIndex <= 4);
			*/

			//shorter method is to invert the IsWeekEnd: this will save updating code.
			return !clsDate::IsWeekEnd(Date);
		}

		bool IsBusinessDay()
		{
			return clsDate::IsBusinessDay(*this);
		}

		static short DaysUntilTheEndOfWeek(clsDate Date)
		{
			return 6 - clsDate::DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
		}

		short DaysUntilTheEndOfWeek()
		{
			return clsDate::DaysUntilTheEndOfWeek(*this);
		}

		static short DaysUntilTheEndOfMonth(clsDate Date1)
		{
			clsDate EndOfMontDate;
			short Days = clsDate::NumberOfDaysInAMonth(Date1._Month, Date1._Year);

			EndOfMontDate._Day = Days; 
			EndOfMontDate._Month = Date1._Month;
			EndOfMontDate._Year = Date1._Year;

			return clsDate::GetDifferenceInDays(Date1, EndOfMontDate, true);
		}

		short DaysUntilTheEndOfMonth()
		{
			return clsDate::DaysUntilTheEndOfMonth(*this);
		}

		static short DaysUntilTheEndOfYear(clsDate Date1)
		{
			clsDate EndOfYearDate;
			EndOfYearDate._Day = 31;
			EndOfYearDate._Month = 12;
			EndOfYearDate._Year = Date1._Year;

			return clsDate::GetDifferenceInDays(Date1, EndOfYearDate, true);
		}

		short DaysUntilTheEndOfYear()
		{
			return clsDate::DaysUntilTheEndOfYear(*this);
		}

		//i added this method to calculate business days between 2 days
		static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
		{
			short Days = 0;
			while (clsDate::IsDate1BeforeDate2(DateFrom, DateTo))
			{
				if (clsDate::IsBusinessDay(DateFrom))
					Days++;

				DateFrom = clsDate::AddOneDay(DateFrom);
			}

			return Days;
		}

		static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
		{
			/*short Days = 0;
			while (IsDate1BeforeDate2(DateFrom, DateTo))
			{
				if (IsBusinessDay(DateFrom))
					Days++;

				DateFrom = AddOneDay(DateFrom);
			}*/

			return clsDate::CalculateBusinessDays(DateFrom, DateTo);
		}
		//above method is eough , no need to have method for the object

		static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
		{
			short WeekEndCounter = 0;

			for (short i = 1; i <= VacationDays; i++)
			{
				if (clsDate::IsWeekEnd(DateFrom))
					WeekEndCounter++;

				DateFrom = clsDate::AddOneDay(DateFrom);
			}
			//to add weekends 
			for (short i = 1; i <= WeekEndCounter; i++)
				DateFrom = clsDate::AddOneDay(DateFrom);

			return DateFrom;
		}

		static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
		{
			return (!clsDate::IsDate1BeforeDate2(Date1, Date2) && !clsDate::IsDate1EqualDate2(Date1, Date2));
		}

		bool IsDateAfterDate2(clsDate Date2)
		{
			return clsDate::IsDate1AfterDate2(*this, Date2);
		}

		enum enDateCompare { Before = -1, Equal = 0, After = 1 };

		static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
		{
			if (clsDate::IsDate1BeforeDate2(Date1, Date2))
				return clsDate::enDateCompare::Before;

			if (clsDate::IsDate1EqualDate2(Date1, Date2))
				return clsDate::enDateCompare::Equal;

			/* 
			if (IsDate1AfterDate2(Date1,Date2))
				return clsDate::enDateCompare::After;
			*/

			//this is faster
			return clsDate::enDateCompare::After;
		}

		enDateCompare CompareDates(clsDate Date2)
		{
			return clsDate::CompareDates(*this, Date2);
		}
};

