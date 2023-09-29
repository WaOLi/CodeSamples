#pragma once
#include<iostream>

enum class Currency
{
	USD, EUR, UAH
};

class Money
{
	long int cents;
	Currency currency;
public:
	long get_cents() const { return cents; }
	Currency get_currency() const { return currency; }

	void set_cents(long c) { cents = c; }
	void set_currency(Currency c) { currency = c; }

	Money() :cents{}, currency{ static_cast<Currency>(0) } {};
	Money(Currency cur, double c);
};

std::ostream& operator<<(std::ostream& os, Currency& cur);

std::ostream& operator<<(std::ostream& os, const Money& mon);
std::istream& operator>>(std::istream& is, Money& mon);

Money& operator+(const Money m1, const Money m2);