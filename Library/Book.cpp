#include"Book.h"

bool Book::is_ISNB()
{
	std::vector<std::string> elems{};

	int counter{};

	//count '-'s
	for (int i{}; i < ISNB.size(); i++)
	{
		if (ISNB[i] == '-')
		{
			counter++;
		}
	}
	if (counter != 3)
	{
		throw Error("ISNB invalid\n");
	}

	//parse the ISNB into elements
	for (int i{}; i < 4; i++)
	{
		size_t index = ISNB.find('-');
		elems.push_back(ISNB.substr(0, index));
		ISNB.erase(0, index + 1);
	}

	//check the contents of the parsed ISNB elements
	for (int i{}; i < elems.size(); i++)
	{
		if (elems[i] == "") throw Error("ISNB invalid\n");


		for (int j{}; j < elems[i].size(); j++)
		{
			if (i == 3)
			{
				if (isdigit(elems[i][j]) || isalpha(elems[i][j])) {}
				else
					throw Error("ISNB invalid\n");
			}
			else
			{
				if (isdigit(elems[i][j])) {}
				else
					throw Error("ISNB invalid\n");
			}
		}
	}
	return true;
}

bool Book::is_genre()
{
	int g = static_cast<int>(get_genre());

	if (g < 1 || g > 5)
		return false;
	else
		return true;
}

bool Book::is_book()
{
	return (is_ISNB() && get_author().size() > 0 && get_title().size() > 0 && is_genre()) ? true : false;
}

Book::Book(std::string author, std::string title, Genre genre, Chrono::Date date, std::string ISNB)
	:author(author), title(title), genre(genre), cpyrt_date(date), ISNB(ISNB)
{
	if (!is_book()) throw Error("wrong book declaration");
}

bool operator==(Book& b1, Book& b2)
{
	return (b1.get_ISNB() == b2.get_ISNB()) ? true : false;
}

bool operator!=(Book& b1, Book& b2)
{
	return !(b1 == b2);
}

std::ostream& operator<<(std::ostream& os, Book& b)
{
	return os << "author: " << b.get_author() << std::endl
		<< "title: " << b.get_title() << std::endl
		<< "genre: " << b.get_genre() << std::endl
		<< "ISNB: " << b.get_ISNB() << std::endl
		<< "copyright date: " << b.get_cpr_date();
}

std::ostream& operator<<(std::ostream& os, const Genre& g)
{
	switch (g)
	{
	case Genre::children:
		return os << "children";
	case Genre::biography:
		return os << "biography";
	case Genre::periodical:
		return os << "periodical";
	case Genre::fiction:
		return os << "fiction";
	case Genre::nonfiction:
		return os << "nonfiction";
	default:
		throw Book::Error("invalid genre");
	}
}