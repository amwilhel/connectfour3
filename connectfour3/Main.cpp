#include <iostream>
using namespace std;

int column;
int row;
bool gameover;
char winner;
char header[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char board[6][7] =
{
	{ '*', '*', '*', '*', '*', '*', '*' },
	{ '*', '*', '*', '*', '*', '*', '*' },
	{ '*', '*', '*', '*', '*', '*', '*' },
	{ '*', '*', '*', '*', '*', '*', '*' },
	{ '*', '*', '*', '*', '*', '*', '*' },
	{ '*', '*', '*', '*', '*', '*', '*' }
};


//Prints the current board
void printBoard() {
	cout << header << endl;
	for (int x = 0; x < 6; ++x)
	{
		for (int y = 0; y < 7; ++y)
		{
			cout << board[x][y];
		}
		cout << endl;
	}
}


//Resets the board
void newBoard() {
	gameover = false;
	for (int x = 0; x < 6; ++x)
	{
		for (int y = 0; y < 7; ++y)
		{
			board[x][y] = '*';
		}
	}

}

//Checks input for errors
char checkInputErrors(char move) {
	while (move != 'A' && move != 'B' && move != 'C' && move != 'D' && move != 'E' && move != 'F' && move != 'G')
	{
		cin.ignore(1000, '\n');
		cout << "You've entered an invalid move.  Please try again and enter a character A - G (case-sensitive): ";
		cin >> move; //Prompts again
	}
	cin.ignore(1000, '\n');
	return move;
}

//Player one's turn
void xMoves() {
	char move;

	//Read the input
	cout << "Ready Player One (aka 'X')?  Enter the letter of your next move: ";
	cin >> move;
	move = checkInputErrors(move);

	//Get the column
	for (int y = 0; y < 7; ++y) {
		if (header[y] == move) {
		column = y;
		}
	}

	//Place the piece
	for (int x = 0; x < 6; ++x)	{
		if (board[x][column] == 'X' || board[x][column] == 'O') {
			
			//First check if the column is full
			if (x == 0) {
				cout << "You cannot move there because the column is already full.  Please try again." << endl;
				xMoves();
				break;
			}
			else {
				row = x;
				row = --row;
				board[row][column] = 'X';
				break;
			}
		}
		else if (x == 5)
			board[x][column] = 'X';
	}
}

//Player two's turn
void yMoves() {
	char move;

	//Read the input
	cout << "Ready Player Two (aka 'O')?  Enter the letter of your next move: ";
	cin >> move;
	move = checkInputErrors(move);

	//Get the column
	for (int y = 0; y < 7; ++y) {
		if (header[y] == move) {
			column = y;
		}
	}

	//Place the piece
	for (int x = 0; x < 6; ++x) {
		
		if (board[x][column] == 'X' || board[x][column] == 'O') {
			
			//First check if the column is full
			if (x == 0) {
				cout << "You cannot move there because the column is already full.  Please try again." << endl;
				yMoves();
				break;
			}
			else {
				row = x;
				row = --row;
				board[row][column] = 'O';
				break;
			}
		}

		else if (x == 5)
			board[x][column] = 'O';
	}
}


//Checks for win conditions
void isGameOver() {
	int x;
	int y;

	for (x = 0; x < 6; ++x)
	{
		for (y = 0; y < 7; ++y)
		{
			//Checks for horizontal win
			if (y < 4 && board[x][y] == 'O' && board[x][y + 1] == 'O' && board[x][y + 2] == 'O' && board[x][y + 3] == 'O') {
				gameover = true;
				winner = 'O';
				break;
			}

			else if (y < 4 && board[x][y] == 'X' && board[x][y + 1] == 'X' && board[x][y + 2] == 'X' && board[x][y + 3] == 'X') {
				gameover = true;
				winner = 'X';
				break;
			}
			//Checks for verticle win
			else if (x < 3 && board[x][y] == 'O' && board[x + 1][y] == 'O' && board[x + 2][y] == 'O' && board[x + 3][y] == 'O') {
				gameover = true;
				winner = 'O';
				break;
			}

			else if (x < 3 && board[x][y] == 'X' && board[x + 1][y] == 'X' && board[x + 2][y] == 'X' && board[x + 3][y] == 'X') {
				gameover = true;
				winner = 'X';
				break;
			}

			//Checks for diagonal down win
			else if (board[x][y] == 'O' && board[x + 1][y + 1] == 'O' && board[x + 2][y + 2] == 'O' && board[x + 3][y + 3] == 'O') {
				gameover = true;
				winner = 'O';
				break;
			}
			else if (board[x][y] == 'X' && board[x + 1][y + 1] == 'X' && board[x + 2][y + 2] == 'X' && board[x + 3][y + 3] == 'X') {
				gameover = true;
				winner = 'X';
				break;
			}

			//Checks for diagonal up win
			else if (board[x][y] == 'O' && board[x][y - 1] == 'O' && board[x][y - 2] == 'O' && board[x][y - 3] == 'O') {
				gameover = true;
				winner = 'O';
				break;
			}
			else if (board[x][y] == 'X' && board[x][y - 1] == 'X' && board[x][y - 2] == 'X' && board[x][y - 3] == 'X') {
				gameover = true;
				winner = 'X';
				break;
			}

			//Checks for tie game
			else if (x == 0 && board[x][y] != '*' && board[x][y + 1] != '*' && board[x][y + 2] != '*' && board[x][y + 3] != '*' && board[x][y + 4] != '*' && board[x][y + 5] != '*' && board[x][y + 6] != '*') {
			gameover = true;
			winner = 'T';
			break;
			}
		}
	}
}


//Take turns playing until there is a winner
void playgame() {
	char playagain;
	newBoard();
	printBoard();

	while (gameover == false) {
		xMoves();
		printBoard();
		isGameOver();
		if (gameover == true)
		break;
		yMoves();
		printBoard();
		isGameOver();
	}

	if (winner == 'T')
		cout << "Its a tie game. " << endl;
	else
		cout << "Congratulations " << winner << ", you won the game!" << endl;
	cout << "Would you like to play again? Type Y for Yes and N for No. ";
	cin >> playagain;
	cin.get();
	if (playagain == 'Y')
		playgame();
	else if (playagain == 'N')
		return;
}

//Play the game;
int main() {
	playgame();
}