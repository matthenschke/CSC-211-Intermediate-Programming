//Matthew Henschke
//Tic Tac Toe Game using two-dimensional arrays

//Header Files
#include<iostream>
#ifndef BOARD_H
#define BOARD_H


using namespace std;

//two classes, the game board and the player
class Board{
public:

	static int nec;
	Board(int dim = 3);
	~Board(); //deallocation of memory
	void display();
	int size;
	
	
friend class Player;
private:
	char** bd;
	char ** Create2DArray(int r, int c);
	void Destroy2DArray(char ** arr);
};

class Player {
public:
	Player();
	~Player();
	bool move(int row, int col, Board &b);
	bool doIWin(int row, int col, Board &b);
	void setName(char c){ pn = c; }
	char getName() const { return pn; }
	bool occupied = false;

private:
	char pn;
	
};
int Board::nec = 0;
//Class function implementations
//Board Functions
Board::Board(int dim){
	size = dim;
	bd = Create2DArray(dim, size);

}
Board:: ~Board(){
	Destroy2DArray(bd);
}

//displays game board
void Board::display(){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << "[  " << bd[i][j] << "  ]" << "  ";
		}
		cout << endl;
	}
}

char** Board::Create2DArray(int r, int c){
	char **A = new char *[r];
	for (int i = 0; i < r; i++){
		A[i] = new char[c];
		for (int j = 0; j < c; j++) //  initialize each cell with ' '
			A[i][j] = ' ';
	}
	return A;

}
void Board::Destroy2DArray(char ** arr){
	for (int i = 0; i < size; i++)
		delete[] bd[i];
	delete[] bd;
}
//Player Functions
Player::Player(){
	char ch = ' ';
	pn = ch;
}
Player:: ~Player(){

}

//move function
bool Player::move(int row, int col, Board &b){

	if (row > 3 || col > 3 || row <= 0 || col <= 0)
		return false;
	else if (b.bd[row - 1][col - 1] != ' ')
		return false;
	else{
		b.bd[row - 1][col - 1] = pn;
		return true;
	}


}
//checks to see if player wins
bool Player::doIWin(int row, int col, Board &b){
	bool win = false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if ((b.bd[0][j] == pn && b.bd[1][j] == pn && b.bd[2][j] == pn)
				|| (b.bd[i][0] == pn && b.bd[i][1] == pn && b.bd[i][2] == pn)
				|| (b.bd[0][0] == pn && b.bd[1][1] == pn && b.bd[2][2] == pn)
				|| (b.bd[0][2] == pn && b.bd[1][1] == pn &&  b.bd[2][0] == pn)){
				win = true;
				break;

			}
			else continue;
			if (win == true)
				return true;
			else return false;
}


//Main
int main(){
	
	//declaratin of variables
	Player p1, p2;
	Board b;
	bool cont = true;
	int row, col;
	int i;
	char pl;
	
		cout << "Welcome to Tic-Tac-Toe" << endl;
		cout << "There are two characters, X and O, who shall move first?" << endl;
		cout << "enter 'X', for X to move first, anything else O moves first" << endl;
		cin >> pl;
		p1.setName(pl);
		if (p1.getName() == 'X')
			p2.setName('O');
		else{
			p1.setName('O');
			p2.setName('X');
		}
		cout << p1.getName()<< " will go first" << endl;
		cout << '\t' << "Initial Board" << endl;
		b.display();
		for (i = 9; i > Board::nec; i--){
			if (i == 9 || i % 2 == 1){
				cout << "\n" << p1.getName() << " it is your turn " << endl;
				while (cont){
					cout << "Please enter the row" << endl;
					cin >> row;
					cout << "Please enter the column" << endl;
					cin >> col;
					if (p1.move(row, col, b) == false){
						cout << "Invalid move, try again" << endl;
						continue;
					}
					else
						break;

				}
				b.display();
				if (p1.doIWin(row, col, b) == true){
					cout << '\n' << p1.getName() << " is the winner!! Congratulations!!! :)" << endl;
					break;
				}
				else continue;
			}
			else
			{

				cout << "\n" << p2.getName() << " it is your turn " << endl;
				while (cont){
					cout << "Please enter the row" << endl;
					cin >> row;
					cout << "Please enter the column" << endl;
					cin >> col;
					if (p2.move(row, col, b) == false){
						cout << "Invalid move, try again" << endl;
						continue;
					}
					else

						break;

				}
				b.display();
				if (p2.doIWin(row, col, b) == true){
					cout << '\n' << p2.getName() << " is the winner!! Congratulations!!! :)" << endl;
					break;
				}
				else continue;
			}

		}
		if (i == 0)
			cout << "\nNo One Wins..." << endl;
		    cout << "Thank you for playing and please come again!!!  " << endl;
	
		
					
	return 0;
}                    


#endif