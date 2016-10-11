/**************************************************************

piece.h
Jacob Holle
Project 7

**************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "color.h"
using namespace std;

class piece{
	public:
		piece(){color = "empty";}
		piece(string in){color = in;}
		void output();
		void flip();
		string opposite();
		piece set_color(string type);
		void make_black();
		void make_white();
		void operator =(const piece& other){color = other.color;}
		bool is_black();
		bool is_white();
		bool is_empty();
		friend ostream& operator<<(ostream& os, piece& p);
		string get_color();
	private:
		string color;//if piece is black color = 'black', if its is white color = 'white'; if neither then it is default = 'empty' background color
		

};


