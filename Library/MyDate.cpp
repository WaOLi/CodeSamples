#include"MyDate.h"

namespace Chrono
{
	Date::baka::baka(std::string message)
	{
		std::cerr << message;
	}

	bool Date::is_date()
	{
		int mm = static_cast<int>(m);

		if (y < 1900 || y > 2100) return false;
		if (mm < 1 || mm > 12) return false;
		int days_in_the_month = 31;

		switch (m)
		{
		case Month::Feb:
			days_in_the_month = is_leap_year() ? 29 : 28;
			break;
		case Month::Apr: case Month::Jun:case Month::Sep: case Month::Nov:
			days_in_the_month = 30;
		}

		if (days_in_the_month < d || d < 1) return false;

		return true;
	}

	void Date::add_day(int n)
	{
		for (int i{}; i < n; i++)
		{
			int days_in_curr_month{ days_in_month(*this) };

			if (days_in_curr_month > day())
			{
				d++;
				return;
			}
			else
			{
				add_month(1);
				d = 1;
				return;
			}
		}
	}

	void Date::add_month(int n)
	{
		for (int i{}; i < n; i++)
		{
			int temp{ static_cast<int>(month()) };
			//january case
			if (temp == 1)
			{
				if (d > 28)
				{
					if (is_leap_year())
						d = 29;
					else
						d = 28;
				}
				++temp;
			}//december case
			else if (temp == 12)
			{
				temp = 1;
				add_year(1);
			}//every 31 day case
			else if (days_in_month(*this) == 31)
			{
				Date d_temp{ *this };
				d_temp.d = 1;
				int d_m_temp{ static_cast<int>(d_temp.month()) };
				d_temp.m = static_cast<Month>(++d_m_temp);

				if (!(days_in_month(d_temp) == 31) && this->day() == 31)
				{
					d = 30;
				}
				++temp;
			}
			else
			{
				++temp;
			}

			m = static_cast<Month>(temp);
			if (is_date()) {}
			else
			{
				throw baka("date got invalid");
			}
		}
	}

	void Date::add_year(int n)
	{
		if (is_leap_year() && day() == 29 && (n % 4))
		{
			d = 28;
			y += n;
			return;
		}
		y += n;
	}

	Date::Date(int y, Month m, int d)
		:y(y), m(m), d(d)
	{
		if (!is_date()) throw baka("invalid date");
	}

	Date::Date()
		:y(2001), m(Month::Jan), d(1)
	{
	}

	std::ostream& operator<<(std::ostream& os, const Month& m)
	{
		switch (m)
		{
		case Month::Jan:
			os << "January";
			break;
		case Month::Feb:
			os << "February";
			break;
		case Month::Mar:
			os << "March";
			break;
		case Month::Apr:
			os << "April";
			break;
		case Month::May:
			os << "May";
			break;
		case Month::Jun:
			os << "June";
			break;
		case Month::Jul:
			os << "July";
			break;
		case Month::Aug:
			os << "August";
			break;
		case Month::Sep:
			os << "September";
			break;
		case Month::Oct:
			os << "October";
			break;
		case Month::Nov:
			os << "November";
			break;
		case Month::Dec:
			os << "December";
			break;
		default:
			throw Date::baka("invalid month");
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		return os << date.year() << " year "
			<< date.month() << " month "
			<< date.day() << " day "
			<< day_of_week(date) << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Day& day)
	{
		switch (day)
		{
		case Day::monday:
			os << "Monday";
			break;
		case Day::tuesday:
			os << "Tuesday";
			break;
		case Day::wednesday:
			os << "Wednesday";
			break;
		case Day::thursday:
			os << "Thursday";
			break;
		case Day::friday:
			os << "Friday";
			break;
		case Day::saturday:
			os << "Saturday";
			break;
		case Day::sunday:
			os << "Sunday";
			break;
		default:
			throw Chrono::Date::baka("invalid day of week");
		}

	}

	bool operator==(const Date& d1, const Date& d2)
	{
		return (d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year());
	}

	bool operator!=(const Date& d1, const Date& d2)
	{
		return !(d1 == d2);
	}

	int Date::days_in_month(Date& date) const
	{
		switch (date.month())
		{
		case Month::Feb:
			return date.is_leap_year() ? 29 : 28;
		case Month::Apr: case Month::Jun:case Month::Sep: case Month::Nov:
			return 30;
		default:
			return 31;
		}
	}

	Day day_of_week(const Date& d)
	{
		Date init{ 1900, Month::Jan, 1 };
		int counter{};
		while (init != d)
		{
			init.add_day(1);
			counter++;
		}
		counter %= 7;
		return static_cast<Day>(counter);
	}

	Date next_workday(const Date& d)
	{
		Date temp{ d };
		temp.add_day(1);
		while (day_of_week(temp) == Day::saturday || day_of_week(temp) == Day::sunday)
		{
			temp.add_day(1);
		}
		return temp;
	}

	int week_of_year(const Date& d)
	{
		Date init{ d.year(), Month::Jan, 1 };
		int week_count{ 1 };
		while (init != d)
		{
			if (day_of_week(init) == Day::sunday)
			{
				week_count++;
			}
			init.add_day(1);
		}
		return week_count;
	}
}