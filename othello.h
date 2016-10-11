/**********************************************

othello.h
Jacob Holle
Project 7

**********************************************/

#include "game.h"
#include "piece.h"
using namespace main_savitch_14;

class othello:public game{
	public:
		
		void play();
		void flipping(int x , int y);
		bool can_flip(string dir , int x , int y);
		void restart();
		void display_status();
		string get_user_move( ) const;
		void make_human_move( );
		void make_move(string move);
		bool is_legal(const std::string& move);
		bool no_more_moves();
		bool is_game_over( );
		void computer_move();
		void compute_moves(std::queue<std::string>& moves);
		void clone_board( );
		void reverse_clone();
		int evaluate( );
		string convert(int x , int y);
		int get_numberflipped();
		bool should_skip_player();
		void winner();
		void waitup();

private:
		piece board[8][8];
		int move_number;
		piece clone[8][8];
		int number_flipped;
};


