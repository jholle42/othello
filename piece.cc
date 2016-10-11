/*************************************************

piece.cc
Jacob Holle
Project 7

*************************************************/

#include "piece.h"

void piece::flip(){
	if(color == "black"){make_white();}
	else{make_black();}
}

void piece::make_black(){
	color = "black";
}

string piece::opposite(){
	if(color == "white"){
		return "black";
	}else if(color == "black"){
		return "white";
	}else{
		return "empty";
	}
}

void piece :: output(){
	if(get_color()=="empty"){
		cout << B_RED << "   " << RESET;
	}
	else if(get_color()=="white"){
		
		cout << B_WHITE << "   " << RESET;
	}
	else if(get_color()=="black"){
		
		cout << B_BLUE << "   " << RESET;
	}
}

piece piece::set_color(string type){
	piece tmp;
	tmp.color = type;
	return tmp;
	
}

void piece::make_white(){
	color = "white";
}

bool piece::is_white(){
	if(color == "white"){return true;}
	else{return false;}
}

bool piece::is_black(){
	if(color == "black"){return true;}
	else{return false;}
}

string piece::get_color(){
	return color;
}

bool piece::is_empty(){
	return color == "empty";
}

ostream& operator<<(ostream& os, piece& p){
	os << p.get_color();
	return os;
}
