#pragma once
#include"Book.h"
#include"Patron.h"

class Library
{
	std::vector<Book> books{};
	std::vector<Patron> patrons{};

	struct Transaction
	{
		Book book;
		Patron patron;
		Chrono::Date date;
	};
	
	std::vector<Transaction> transactions{};

public:
	void add_book(Book book);
	void add_patron(Patron patron);

	void checkout(Patron& patron, Book& book, Chrono::Date& date);
	void checkin(Patron& patron, Book& book);

	std::vector<Patron>& get_fee_owers() const;
};