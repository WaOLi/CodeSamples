#include"Patron.h"

bool operator==(const Patron& p1, const Patron& p2)
{
	return (p1.get_name() == p2.get_name() && p1.get_lib_card_num() == p2.get_lib_card_num()) ? true : false;
}

Patron::Patron(std::string n, int card)
	:name(n), lib_card_num(card)
{

}