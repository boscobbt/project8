#include <iostream>
#include "classes.h"
#include <string>
using namespace std;

player::player()
{
	name="First Last";
	bet=0.0;
}
player::~player()
{
	
}
void player::set_name(string a)
{
	name = a;
}
void player::set_hand()
{

	
}
void player::set_bet()
{

}
string player::get_name()
{
	return name;
}
card* player::get_hand()
{
	return hand[5];
}

float player::get_bet()
{
	return bet;
}
