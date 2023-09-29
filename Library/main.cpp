/*
There are a couple of issues pending for solution:
1) workout the mechanics of checkout & checkin books
2) make a sensible help-disclaimer at the start
3) build an interactive terminal interface


*/

#include"Library.h"

int main()
{
	Library my_lib{};
	my_lib.add_book(Book{ "Lewis Carrol",
		"Alice in wonderland",
		Genre::children,
		Chrono::Date{2012, Chrono::Month::Jul,21},
		"12-14-11-a2" });
	my_lib.add_book(Book{ "J.K. Rowling",
		"Harry Potter",
		Genre::children,
		Chrono::Date{2012, Chrono::Month::Jul,21},
		"52-1784-11-a2" });
	my_lib.add_patron(Patron{ "Meaux", 1341 });
	my_lib.add_patron(Patron{ "Lucy", 4122 });


}