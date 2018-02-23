  /*Airplane Seat Assigning System
Author: Matthew Henschke
Date: 2/17/2017 */
//Header Files
#include<iostream>
#include<string>
using namespace std;

int main(){

	//declaration of variables
	int row;
	string cont;
	char letter;
	char air[7][4];
	int counterX = 0;
	int total = 0;
	
	int i, j;

	//display original seating chart
	for (i = 0; i < 7; i++){
		cout << i + 1 << " ";
		for (j = 0; j < 4; j++){

			if (j == 0)
				air[i][j] = 'A';
			else if (j == 1)
				air[i][j] = 'B';
			else if (j == 2)
				air[i][j] = 'C';
			else if (j == 3)
				air[i][j] = 'D';
			cout << air[i][j];
		}
		cout << endl;;
	}

	while (true){
		

		cout << "Welcome to the Airplane Seat Asigning System" << endl;
		cout << "What row number would you like to sit in?";
		cin >> row;
		cout << "What column letter would you like to sit in?" << endl;
		cin >> letter;
		
		//checks to see if input is invalid
		if ((row != 1 && row != 2 && row != 3 && row != 4 && row != 5 && row != 6 && row != 7) ||
			(letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D')){
			cout << "Invalid seat." << endl;
			cout << "Please enter another row number." << endl;
			cin >> row;
			cout << "Please enter another column letter." << endl;
			cin >> letter;
		}
		if (air[row - 1][static_cast<int>(letter % 65)] == 'X'){
			cout << "That seat is taken already I am sorry." << endl;

		}


		else{
			for (i = 0; i < 7; i++){
				cout << i + 1 << " ";
				for (j = 0; j < 4; j++){

					if (air[i][j] == 'X')
						air[i][j] = 'X';
					else if (j == 0)
						air[i][j] = 'A';
					else if (j == 1)
						air[i][j] = 'B';
					else if (j == 2)
						air[i][j] = 'C';
					else if (j == 3)
						air[i][j] = 'D';
					air[row - 1][static_cast<int>(letter % 65)] = 'X';
					cout << air[i][j];
				}
				cout << endl;

			}

			cout << "There you go, you are all set to go on board." << endl;
			counterX++;
			if (counterX == 28){
				cout << "All seats are taken now. System shutting down." << endl;
				break;
			}
		}
		cout << "Do you want another seat? Answer either yes or no" << endl;
		cin >> cont;
		if (cont == "yes")
			continue;


		else if (cont == "no")
			break;


	}


	return 0;
}





