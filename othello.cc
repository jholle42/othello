/*********************************************************

othello.cc
Jacob Holle
Project 7

*********************************************************/
#include <sstream>
#include "othello.h"
		
/*
	12/7/2015
	Professor Dolan,

	I made my own othello functions for this game instead of using the authors given ones such as "eval_with_lookahead(int look_ahead, int beat_this)"
	This was much easier for me while i was doing the projects as i knew what i was doing as apposed to trying to figure out what the author wanted.
	
	Thanks,

	jake holle

*/


		void othello::play(){
			restart();
			while(!no_more_moves()){
				display_status();
				//waitup();
				if(move_number%2==0){				
					if(!should_skip_player()){//make_human_move();
						make_human_move();
					}	
				}else{
					if(!should_skip_player()){computer_move();}	
					
				}			
								
				++ move_number;
			}
			cout << "\n\n\n\n";
			winner();
					
		}

		void othello::waitup(){
			char d;
			cout << "press any key to continue";
			cin >> d;
		}

		void othello::winner(){
			int b = 0;
			int w = 0;			
			for(int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					if(board[i][j].get_color() == "black"){ ++b;}
					if(board[i][j].get_color() == "white"){ ++w;}
					if(board[i][j].get_color() == "empty"){}			
				}
			}
			if(b > w){ cout << "THE WINNER IS BLUE!!!!!"<< endl;
			}else if(w > b){ cout << "THE WINNER IS WHITE!!!!!" << endl;}
			
		}

		bool othello::should_skip_player(){
			queue<string> moves;
			for(int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					string move = convert(i , j);
					moves.push(move);				
				}
			}
			if(moves.empty()){return true;}else{return false;}	
		}	

		void othello::flipping(int x , int y){
			int change = 1;
			int side = x;
			int vert = y;
			number_flipped = 0;
			if(side+change<=7){	//E								
				if(board[vert][side+change].get_color() == board[vert][side].opposite()){
					if(can_flip("E",side , vert)){							
						int e = 1;						
						while((board[vert][side+e].get_color() == board[vert][side].opposite()) && side+e <= 7){						
							board[vert][side+e].flip();
							++number_flipped;
							++e;
						}
					}
				}
			}
			if(side-change>=0){	//W
				if(board[vert][side-change].get_color() == board[vert][side].opposite()){
					if(can_flip("W" ,side , vert)){
						int w = 1;
						while((board[vert][side-w].get_color() == board[vert][side].opposite()) && side-w >= 0){						
							board[vert][side-w].flip();
							++number_flipped;
							
														
							++w;
						}													
					}
				}
			}
			if(vert-change >= 0){//N
				if(board[vert-change][side].get_color() == board[vert][side].opposite()){
					if(can_flip("N" ,side , vert)){
						int n = 1;
						while((board[vert-n][side].get_color() == board[vert][side].opposite()) && vert-n >= 0){						
							board[vert-n][side].flip();
							++number_flipped;
							
							++n;
						}
					}
				}
			}
			if(vert+change <=7){	//S
				if(board[vert+change][side].get_color() == board[vert][side].opposite()){
					if(can_flip("S" ,side , vert)){					
						int s = 1;
						while((board[vert+s][side].get_color() == board[vert][side].opposite()) && vert+s < 8){						
							board[vert+s][side].flip();
							++number_flipped;
							
							++s;
						}
					}
				}
			}
			if(vert-change >= 0 && side+change <=7){	//NE				
				if(board[vert-change][side+change].get_color() == board[vert][side].opposite()){
					if(can_flip("NE" ,side , vert)){
						int ne = 1;
						while((board[vert-ne][side+ne].get_color() == board[vert][side].opposite()) && side+ne < 8 && vert-ne >= 0){						
							board[vert-ne][side+ne].flip();
							++number_flipped;
							
							++ne;
						}
					}
				}
			}
			if(vert+change <=7 && side+change <=7){	//SE
				if(board[vert+change][side+change].get_color() == board[vert][side].opposite()){
					if(can_flip("SE" ,side , vert)){
						int se = 1;
						while((board[vert+se][side+se].get_color() == board[vert][side].opposite()) && side+se < 8 && vert+se < 8){						
							board[vert+se][side+se].flip();
							++number_flipped;
							
							++se;
						}
					}
				}
			}
			if(vert-change >=0 && side-change >=0){	//NW
				if(board[vert-change][side-change].get_color() == board[vert][side].opposite()){
					if(can_flip("NW" ,side , vert)){
						int nw = 1;
						while((board[vert-nw][side-nw].get_color() == board[vert][side].opposite()) && side-nw >= 0 && vert-nw >= 0){						
							board[vert-nw][side-nw].flip();
							++number_flipped;
							
							++nw;
						}
					}
				}
			}
			if(vert+change <=7 && side-change >= 0){	//SW
				if(board[vert+change][side-change].get_color() == board[vert][side].opposite()){
					if(can_flip("SW" ,side , vert)){
						int sw = 1;
						while((board[vert+sw][side-sw].get_color() == board[vert][side].opposite()) && side-sw >= 0 && vert+sw < 8){						
							board[vert+sw][side-sw].flip();
							++number_flipped;
							
							++sw;
						}
					}
				}
			}
				
						
}	
		bool othello::can_flip(string dir , int x , int y){
			int change = 2;	
			bool answer = false;
			string initial = board[y][x].get_color();		
			if(dir == "E"){
				while(x + change <= 7){
					if(board[y][x+change].get_color() == board[y][x].get_color()){
						return true;	
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "W"){
				while(x - change >= 0){
					if(board[y][x-change].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "N"){
				while(y - change >= 0){
					if(board[y-change][x].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "S"){
				while(y + change <= 7){
					if(board[y+change][x].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "NE"){
				while(x + change <= 7 && y - change > 1){
					if(board[y-change][x+change].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "NW"){
				while(x - change >= 0 && y - change >= 0){
					if(board[y-change][x-change].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "SE"){
				while(x + change <= 7 && y + change <= 7){
					if(board[y+change][x+change].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}else if(dir == "SW"){
				while(x - change >= 0 && y + change <= 7){
					if(board[y+change][x-change].get_color() == board[y][x].get_color()){
						return true;		
					}else{
						answer = false;
					}
					++change;
				}
			}
			return answer;
			
		}
		void othello::restart(){
			for (int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					piece tmp;
					if(i==3 && j==3 || i==4&&j==4){
						board[i][j].make_white(); 
					}
					else if(i==3 && j==4 || i==4&&j==3){
						board[i][j].make_black();
					}
				}
			}  
			move_number = 0;			 
		}

		void othello::display_status(){
			cout << "    0   1   2   3   4   5   6   7" << endl;
			cout << "  ---------------------------------" << endl;
			for (int i=0; i < 8; i++){
				cout << i << " |";
				for (int j=0; j < 8; j++){
					
					board[i][j].output();
					if(j!=8){cout << "|";}
				}
				cout << endl << "  ---------------------------------" << endl;
			}
		}

		string othello::get_user_move( ) const{
			string answer;
			if(move_number%2==0){				
				cout << "Blue's Turn!" << endl;	
			}else{
				cout << "White's Turn!"<< endl;	
			}
			cout << "Enter move as an xy coordinate!" << endl;
			cout << "Your move, please: ";
			
			getline(cin, answer);
			return answer;
  		} 
		
		void othello::make_human_move( ){
		        string move;
			move = get_user_move( );
			while (!is_legal(move)){
	   			cout << "Illegal move.\n";
	    			move = get_user_move( );
        		}
			make_move(move);
    		}

		void othello::make_move(string move){
			char m1 = move[0], m2 = move[1];
			int y = m2 - '0';
			int x = m1 - '0';
			if(is_legal(move)){
				if(move_number%2==0){				
					board[y][x].make_black();
					flipping(x,y);
				}else{
					board[y][x].make_white();
					flipping(x,y);
				}
			}else{
				cout << "invalid move";
			}
			
		}
		
		
		bool othello::is_legal(const std::string& move){
			char m1 = move[0], m2 = move[1];
			int y = m2 - '0' , x = m1 - '0';
			string opposite_color , current;
			if(board[y][x].get_color() != "empty"){ return false;}
			if(move_number%2==0){				
				opposite_color = "white";
				current = "black";	
			}else{
				opposite_color = "black";
				current = "white";	
			}			
			if(x>7 ||x < 0 || y< 0 || y >7){return false;}
			for(int i =-1; i < 2; ++ i){
				if(y+i >=0 && y+i<8)
				for(int j =-1; j <2; j++){
					if(x + j >= 0 && x +j < 8){					
						if(i==0 && j==0);
						else if(board[y+i][x+j].get_color() == opposite_color){	
							for(int k = 2; k < 8; k++){
								if(y+k*i < 0 || y + k*i >7 || x+k*j < 0 || x+k*j > 7);
								else if(board[y+i*k][x+j*k].get_color() == "empty") break;
								else if(board[y+i*k][x+j*k].get_color() == current) { 
									return true;
								} // legal move
							}
						}
					}
				}
			}
			return false;
		}
		
		bool othello::no_more_moves(){
						
			for(int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					if(board[i][j].get_color()=="empty"){return false;}
					
				}
				
			}
			return true;
		}
		
		void othello::computer_move(){
			queue<string> moves;
			int best_value = 0;
			bool corner = false;
			string corner_move;
			compute_moves(moves);
			string best_move;
			string move;
			while(!moves.empty()){
				othello clone;
				clone.move_number = move_number;
				for(int i=0; i < 8; i++){
					for (int j=0; j < 8; j++){
						clone.board[i][j] = board[i][j];
					}
				}
				clone.number_flipped = 0;
				clone.make_move(moves.front());
				if(moves.front() == "00"||moves.front() == "07"||moves.front() == "70"||moves.front() == "77"){
					corner = true;					
					corner_move = moves.front(); 
				}
				if(clone.number_flipped > best_value){
					best_value = clone.number_flipped;					
					best_move = moves.front();
				}
				moves.pop();
			}
			if(move_number == 0){
				string seed;
				cout << "enter a seed move";				
				cin >> seed;				
				best_move = seed;			
			}
			
			if(corner == true){best_move = corner_move;}
			make_move(best_move);
		}
		
		
		
		void othello::compute_moves(std::queue<std::string>& moves){
			for(int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					string tmp = convert(j , i);					
					if(is_legal(tmp)){
						moves.push(tmp);
					}
				}
			}
		}

		void othello::clone_board( ){
			for(int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					clone[i][j] = board[i][j];
				}
			}
		}

		void othello::reverse_clone(){
		for(int i=0; i < 8; i++){
				for (int j=0; j < 8; j++){
					board[i][j] = clone[i][j];
				}
			}
		}

	

		string othello::convert(int x , int y){
			stringstream ss;
			ss << x << y;
			return ss.str();
			
		}
		int othello::get_numberflipped(){
			return number_flipped;
		}

			
