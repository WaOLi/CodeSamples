#include"Library.h"

void Library::add_book(Book book)
{
	books.push_back(book);
}

void Library::add_patron(Patron patron)
{
	patrons.push_back(patron);
}

void Library::checkin(Patron& patron, Book& book)
{
	if (book.get_is_checkedout() && std::count(patrons.begin(), patrons.end(), patron) == 1)
		book.check_in();
	else
		throw Book::Error("can't check in the book");
}

void Library::checkout(Patron& patron, Book& book, Chrono::Date& date)
{
	if (!book.get_is_checkedout()
		&& std::count(patrons.begin(), patrons.end(), patron) != 1
		&& patron.get_fees_owed() != 0)
	{
		book.check_in();
		transactions.push_back(Transaction{ book, patron, date });
	}
	else
		throw Book::Error("can't check out the book");
}

std::vector<Patron>& Library::get_fee_owers() const
{
	std::vector<Patron> owers;
	for (int i{}; i < patrons.size(); i++)
	{
		if (patrons[i].does_owe()) owers.push_back(patrons[i]);
	}
	return owers;
}