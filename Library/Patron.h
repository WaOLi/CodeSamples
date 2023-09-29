#pragma once
#include<iostream>

class Patron
{
	std::string name{};
	int lib_card_num{};
	int fees_owed{};
public:
	bool does_owe() const { return fees_owed; }
	int get_fees_owed() const { return fees_owed; }
	void set_fees(int fee) { fees_owed = fee; }

	std::string get_name() const { return name; }
	int get_lib_card_num() const { return lib_card_num; }

	Patron(std::string n, int card);
};

bool operator==(const Patron& p1, const Patron& p2);