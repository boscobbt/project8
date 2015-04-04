#include <iostream>
#include <string>
using namespace std;
class card
{
	private:
		string suit;
		string rank;
		string location;
	public:
		
		card();
		~card();
		void set_suit(string a);
		void set_rank(string a);
		void set_location(string a);
		string get_suit();
		string get_rank();
		string get_location();
	
};

class player
{
	public:
		player();
		~player();
		void set_name(string a);
		void set_hand();
		void set_bet();
		string get_name();
		card* get_hand();
		float get_bet();
	private:
		string name;
		card* hand[5];
		float bet;
		
};
