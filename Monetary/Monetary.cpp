#include"Monetary.h"
#include<math.h>

Money::Money(Currency cur, double c)
	:currency{ cur }
{
	long int temp_i{};
	if (std::numeric_limits<int>::max() > c && std::numeric_limits<int>::min() < c)
	{
		temp_i = static_cast<long int>(c);
	}
	double temp_f = c - temp_i;

	cents = (temp_f < .5f) ? temp_i : temp_i + 1;
}


std::ostream& operator<<(std::ostream& os, const Currency& cur)
{
	switch (cur)
	{
	case Currency::USD:
		return os << "USD";
	case Currency::EUR:
		return os << "EUR";
	case Currency::UAH:
		return os << "UAH";
	default:
		return os << "invalid currency";
	}
}

std::ostream& operator<<(std::ostream& os, const Money& mon)
{
	switch (mon.get_currency())
	{
	case Currency::USD:
		os << "USD";
		break;
	case Currency::EUR:
		os << "EUR";
		break;
	case Currency::UAH:
		os << "UAH";
		break;
	default:
		std::cerr << "invalid currency";
	}
	return os << mon.get_cents() / 100 << '.' << mon.get_cents() % 100;
}

std::istream& operator>>(std::istream& is, Money& mon)
{
	std::string temp, id, num;
	is >> temp;
	id = temp.substr(0, 3);
	num = temp.substr(3, std::string::npos);
	char c[10];
	for (int i{}; i < num.length(); i++)
	{
		c[i] = num[i];
	}
	c[num.length()] = '\0';
	double d{ std::atof(c) };

	//assign currency
	if (id == "USD")
	{
		mon.set_currency(Currency::USD);
	}
	else if (id == "UAH")
	{
		mon.set_currency(Currency::UAH);
	}
	else if (id == "EUR")
	{
		mon.set_currency(Currency::EUR);
	}
	else
	{
		std::cerr << "invalid currency assignment";
		return is;
	}

	//assign cents (assuming d is within <long> range
	if (d * 100 == (long)(d * 100))
	{
		mon.set_cents(d * 100);
	}
	else
	{
		long temp = static_cast<long>(d*100);
		mon.set_cents((d *100 - temp) < .5 ? temp : (temp + 1));
	}
	return is;
}

Money& operator+(const Money m1, const Money m2)
{
	double temp_cents = static_cast<double>(m1.get_cents());

	switch (m1.get_currency())
	{
	case Currency::USD:
		switch (m2.get_currency())
		{
		case Currency::USD:
			temp_cents += m2.get_cents();
			break;
		case Currency::EUR:
			temp_cents += m2.get_cents() * 1.07;
			break;
		case Currency::UAH:
			temp_cents += m2.get_cents() * .027;
		default:
			std::cerr << "invalid currency";
			break;
		}
	case Currency::EUR:
		switch (m2.get_currency())
		{
		case Currency::EUR:
			temp_cents += m2.get_cents();
			break;
		case Currency::USD:
			temp_cents += m2.get_cents() * .94;
			break;
		case Currency::UAH:
			temp_cents += m2.get_cents() * .025;
			break;
		default:
			std::cerr << "invalid currency";
			break;
		}
	case Currency::UAH:
		switch (m2.get_currency())
		{
		case Currency::EUR:
			temp_cents += m2.get_cents() * 39.36;
			break;
		case Currency::USD:
			temp_cents += m2.get_cents() * 36.87;
			break;
		case Currency::UAH:
			temp_cents += m2.get_cents();
			break;
		default:
			std::cerr << "invalid currency";
			break;
		}
	}

	if (std::numeric_limits<long>::max() > temp_cents && std::numeric_limits<long>::min() < temp_cents)
	{
		Money result(m1.get_currency(), static_cast<long>(temp_cents));
		return result;
	}
	else
	{
		std::cerr << "invalid cent amount";
	}
}