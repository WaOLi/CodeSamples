#pragma once
#include<iostream>
namespace Chrono
{
	enum class Month
	{
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};

	enum class Day
	{
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	class Date
	{
	public:
		//error-class
		class baka
		{
		public:
			baka(std::string message);
		};

		//getters
		int day() const { return d; } // const member: can’t modify the object 
		Month month() const { return m; } // const member: can’t modify the object
		int year() const { return y; } // const member: can’t modify the object

		void add_day(int n); // non-const member: can modify the object
		void add_month(int n); // non-const member: can modify the object
		void add_year(int n); // non-const member: can modify the object

		//validators
		bool is_date();
		bool is_leap_year() { return !(y % 4) ? true : false; }

		//constructors
		Date();
		Date(int y, Month m, int d);
	private:
		int days_in_month(Date& mon) const;
		int y; // year
		Month m;
		int d; // day of month
	};

	Day day_of_week(const Date& d);
	Date next_workday(const Date& d);
	int week_of_year(const Date& d);

	std::ostream& operator<<(std::ostream& os, const Month& m);
	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::ostream& operator<<(std::ostream& os, const Day& day);

	bool operator==(const Date& d1, const Date& d2);
	bool operator!=(const Date& d1, const Date& d2);

}