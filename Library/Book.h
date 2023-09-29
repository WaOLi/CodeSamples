#pragma once
#include<iostream>
#include<vector>
#include"MyDate.h"

enum class Genre
{
	fiction = 1, nonfiction, periodical, biography, children
};

class Book
{
	std::string ISNB{};
	std::string title{};
	std::string author{};
	Chrono::Date cpyrt_date{};
	bool is_checkedout{};
	Genre genre{};


	bool is_genre();
	bool is_book();
	bool is_ISNB();

public:
	class Error
	{
	public:
		Error(std::string message)
		{
			std::cerr << message;
		}
	};


	std::string get_ISNB() const { return ISNB; }
	std::string get_author() const { return author; }
	std::string get_title() const { return title; }
	Genre get_genre() const { return genre; }
	Chrono::Date get_cpr_date() const { return cpyrt_date; }
	bool get_is_checkedout() const { return is_checkedout; }

	void check_in() { is_checkedout = false; }
	void check_out() { is_checkedout = true; }

	Book(std::string author, std::string title, Genre genre, Chrono::Date date, std::string ISNB);
};

bool operator==(Book& b1, Book& b2);
bool operator!=(Book& b1, Book& b2);
std::ostream& operator<<(std::ostream& os, Book& b);
std::ostream& operator<<(std::ostream& os, const Genre& g);