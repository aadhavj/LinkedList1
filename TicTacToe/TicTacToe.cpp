#include <iostream>
#include <cstring>
using namespace std;

//Prints the grid
void printGrid(char grid[3][3]){
	cout << endl;
	char letters[3] = {'a','b','c'};
	cout << "  1 2 3" << endl;
	for (int i = 0; i < 3; i++){
		cout << letters[i] << " ";
		for (int b = 0; b < 3; b++){
			cout << grid[i][b] << " ";
		}
		cout << endl;
	}
}


//Checks if someone has won
bool isWon(char grid[3][3]){
	char PlayerType[2] = {'X','O'};
	int countRow;
	int countCol;
	for (int i = 0; i < 2;i++){
		
		//Check Rows & Columns
		for (int k = 0;k < 2;k++){
			countRow = 0;
			countCol = 0;
			for (int j = 0; j < 3; j++){
				if (grid[k][j] == PlayerType[i]){
					countRow+=1;
				}
				if (grid[j][k] == PlayerType[i]){
					countCol += 1;
				}
			}
			if (countRow == 3 or countCol == 3){
				return true;
			}	
		}

		//Diagonal
		if ((grid[0][0] == PlayerType[i] and grid[1][1] == PlayerType[i] and grid[2][2] == PlayerType[i]) or (grid[2][0] == PlayerType[i] and grid[1][1] == PlayerType[i] and grid[0][2] == PlayerType[i])){
			return true;
		}


	}


	return false;

}
//Returns whether it is a tie
bool isTie(char grid[3][3]){
	int tilesFilled = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (not (grid[i][j] == ' ')){
				tilesFilled += 1;
			}
		}
	}
	return ((tilesFilled == 9) and (not isWon(grid)));
}

int main(){
	
	
	//Creates base grid and avaliable moves
	char grid[3][3];
	//Letter array index
	char letters[3] = {'a','b','c'};
	char nums[3] = {'1','2','3'};

	//Player turns
	int turn;
	char PlayerType[2] = {'X', 'O'};

	//Move data
	char move[100];
	bool isValid;


	//PlayAgain?
	char playAgain = 'y';
	while (playAgain == 'y'){
		
		//Initalize new game values
		for (int i = 0; i < 3; i++){
			for (int j = 0;j < 3;j++){
				grid[i][j] = ' ';
			}
		}
		turn = 0;

		//Program beginning text	
		cout << "\n" << "Welcome to Tic Tac Toe! Let's play!";

		//Program run algorithm
		while (not isWon(grid) and not isTie(grid)){

			//Show grid, player turn
			printGrid(grid);
			cout << "Player " << PlayerType[turn] << " - What is your move?(a3, b2, etc.): ";
		
			//Prompt for move and display
			cin >> move;
			move[2] = '\0';
			cout << "Player " << PlayerType[turn] << " - " << move;
		
		
			//Check if a move is valid
			isValid = false;
			for (int i = 0; i < 3;i++){
				for (int j = 0; j < 3; j++){
					if (move[0] == letters[i] and move[1] == nums[j]){
						isValid = true;
						move[0] = i + '0';
					}
				}
			}

			//If valid, do turn and go to next person
			if (isValid and grid[move[0]-'0'][move[1]-1-'0'] == ' '){
				grid[move[0]-'0'][move[1]-1-'0'] = PlayerType[turn];
				turn = (turn+1)%2;
			}
			else{
				cout << "\n" << "Invalid move please try again." << endl;
			}

			printGrid(grid);
			if (isWon(grid)){
				cout << "PLAYER " << PlayerType[(turn + 1) % 2] << " has won!";
			}
			else if (isTie(grid)){
				cout << "TIE!!!";
			}
		}
		cout << "\n" << "Do you want to play again?(y/n): ";
		cin >> playAgain;
	}

	cout << "Thanks for playing!" << endl;

	return 0;
}
