#include <iostream>
#include "classes.h"
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
void read_cards(card*unshuffled_deck, card*shuffled_deck);
void shuffle(card*unshuffled_deck,card *shuffled_deck);
void read_players(int players, player*friends);
void deal(int players, card*shuffled_deck, player*friends);
void print(card*deck);
void print_discard(card*deck);
void print_stock(card*deck);
void print_player(int players, card*deck,player*friends);
int main()
{
	bool menu = true;
	int players;
	cout<<"Please enter the number of players (2-8)"<<endl;
	cin>> players;
	if(players<2||players>8)
	{
		cout<<"please enter a valid number of players (2-8)"<<endl;
		cin>>players;
	}
	int function;
	card *unshuffled_deck = new card[52];
	card *shuffled_deck = new card[52];
	player*friends = new player[players];
	read_cards(unshuffled_deck, shuffled_deck);
	read_players(players,friends);
	srand(time(NULL));
	while(menu!= false)
	{
		cout<<"Please Choose a function"<<endl;
		cout<<"1 - Shuffle cards"<<endl;
		cout<<"2 - Deal the first hand"<<endl;
		cout<<"3 - Print the unshuffled deck"<<endl;
		cout<<"4 - Print the shuffled deck"<<endl;
		cout<<"5 - Print discard pile"<<endl;
		cout<<"6 - Print the stock pile"<<endl;
		cout<<"7 - Print the player information"<<endl;
		cout<<"8 - Quit"<<endl;
		cin>>function;
		if(function>0&&function<9)
		{
			switch(function)
			{
				case 1:
					shuffle(unshuffled_deck,shuffled_deck);
					break;
				case 2:
					deal(players,shuffled_deck,friends);
					break;
				case 3:
					print(unshuffled_deck);
					break;
				case 4:
					print(shuffled_deck);
					break;
				case 5:
					print_discard(shuffled_deck);
					break;
				case 6:
					print_stock(shuffled_deck);
					break;
				case 7:
					print_player(players,shuffled_deck,friends);
					break;
				case 8:
					menu= false;
					break;
			}
		}
		else
		{
			cout<<"Please enter a valid choice"<<endl;
			cin>>function;
		}	
	}
	delete[]unshuffled_deck;
	delete[]shuffled_deck;
	delete[]friends;
	return 0;
}
void read_cards(card*unshuffled_deck, card*shuffled_deck)
{
	string a;
	ifstream fin;
	fin.open("deck");
	if(fin.is_open())
	{
		cout<<"Sucessfully unwrapped deck"<<endl;
		for(int i=0; i<52; i++)
		{
			fin>> a;
			unshuffled_deck[i].set_suit(a);
			shuffled_deck[i].set_suit(a);
			unshuffled_deck[i].set_location("unshuffled");
			shuffled_deck[i].set_location("shuffled");
			fin>> a;
			unshuffled_deck[i].set_rank(a);
			shuffled_deck[i].set_rank(a);
		}
	}
	else
	{
		cout<<"Searched through drawers, but could not find an deck of cards"<<endl;
	}
	string b,c;
}
void shuffle(card*unshuffled_deck, card*shuffled_deck)
{
	string a,b,c,d;
	for (int i = 0; i <= 500; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			int n = rand() % 52;
			a=shuffled_deck[j].get_suit();
			b=shuffled_deck[n].get_suit();
			shuffled_deck[j].set_suit(b);
			shuffled_deck[n].set_suit(a);
			c=shuffled_deck[j].get_rank();
			d=shuffled_deck[n].get_rank();
			shuffled_deck[j].set_rank(d);
			shuffled_deck[n].set_rank(c);			
		}
	}
}
void read_players(int players, player*friends)
{
	string a,b;
	ifstream fin;
	fin.open("players");
	if(fin.is_open())
	{
		cout<<"Sucessfully invited "<< players<<" players"<<endl;
		for(int i=0; i<players; i++)
		{
			getline(fin,a);
			friends[i].set_name(a);
		}
	}
	else
	{
		cout<<"Nobody could come to the poker game"<<endl;
	}
}	
void deal(int players,card*shuffled_deck,player*friends)
{
	string a;
	int n=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<players;j++)
		{
			a=friends[j].get_name();
			shuffled_deck[n].set_location(a);
			n++;
		}
		shuffled_deck[n].set_location("discard");
		n++;
	}
	while(n<52)
	{
	shuffled_deck[n].set_location("stock");
	n++;
	}
}
void print(card*deck)
{
	string a,b,c;
	for(int i=0; i<52; i++)
	{
		a=deck[i].get_suit();
		b=deck[i].get_rank();
		c=deck[i].get_location();
		cout<< a<< " "<<b<<" "<<c<<endl;
	}
}
void print_discard(card*deck)
{
	string a,b,c,d;
	for (int i=0;i<52;i++)
	{
		a=deck[i].get_location();
		if(a=="discard")
		{
			b=deck[i].get_suit();
			c=deck[i].get_rank();
			d=deck[i].get_location();
			cout<< a<< " "<<b<<" "<<c<<endl;
		}
	}
}
void print_stock(card*deck)
{
	string a,b,c,d;
	for (int i=0;i<52;i++)
	{
		a=deck[i].get_location();
		if(a=="stock")
		{
			b=deck[i].get_suit();
			c=deck[i].get_rank();
			d=deck[i].get_location();
			cout<< a<< " "<<b<<" "<<c<<endl;
		}
	}
}
void print_player(int players, card*deck,player*friends)
{
	string a,b,c,d;
	for(int n=0;n<players;n++)
	{
		d=friends[n].get_name();
		for (int i=0;i<52;i++)
		{
			a=deck[i].get_location();
			if(a==d)
			{
				b=deck[i].get_suit();
				c=deck[i].get_rank();
				cout<<d<<": "<<b<<" "<<c<<endl;
			}
		}
	}
}
