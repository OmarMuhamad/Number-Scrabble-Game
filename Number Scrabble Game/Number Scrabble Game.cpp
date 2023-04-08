// Author: Omar Mohammad Fayek
// Number Scrabble Game 
#include <iostream>
#include <vector>
#include <algorithm>
int GOAL = 15;
using namespace std;
bool checkWinner(vector<int>, int); // return true if player1/2 wins
void displayBoard(vector<int>);		// display the Game Board
void updateBoard(vector<int>&, int);	// update the board
void generateBoard(vector<int>& Board, int limit) {
	for (int i = 1; i <= limit; i++) {
		Board.push_back(i);
	}

} // generate the array of element to be chosed from
int main() {
	vector<int> Board;
	generateBoard(Board, 9);
	string playerNmI, playerNmII;
	cout << "Enter Name of Player One: "; cin >> playerNmI;
	cout << "\nEnter Name of Player Two: "; cin >> playerNmII;
	vector<int> player1, player2;
	int turn = 1;
	int p1, p2; p1 = p2 = 0;
	// while board size is not ZERO
	while (Board.size() != 0) {
		if (turn == 1) {
			int move;
			cout << "Player ONE turn: \nEnter a valid move from this list: "; 
			displayBoard(Board);
			cin >> move;
			while(move < 0 and move > GOAL) {
				cout << "Enter a valid move: ";
				cin >> move;
				cout << '\n';
			}
			p1 += move;
			cout << "Player ONE Statues: " << p1 << '\n';
			player1.push_back(move);
			updateBoard(Board, move);
			if (checkWinner(player1, GOAL)) {
				cout << "Player 1 WINS!\n";
				return 0;
			}
			turn = 2;
		}
		else {
			int move;
			cout << "Player TWO turn: \nEnter a valid move from this list: ";
			displayBoard(Board);
			cin >> move;
			while (move < 0 and move > GOAL) {
				cout << "Enter a valid move: ";
				cin >> move;
				cout << '\n';
			}
			p2 += move;
			cout << "Player TWO Statues: " << p2 << '\n';
			player2.push_back(move);
			updateBoard(Board, move);
			if (checkWinner(player2, GOAL)) {
				cout << "Player 2 WINS!\n";
				return 0;
			}
			turn = 1;
		}
	}
	cout << "DRAW!" << endl;
	return 0;
}
// goal means what summation should make the player win
bool checkWinner(vector<int>player, int GOAL) {
	int s = 0;
	for (int i = 0; i < player.size(); i++) {
		s += player[i];
	}
	return s == GOAL;
}
void displayBoard(vector<int> Board) {
	cout << "[ ";
	for (int i = 0; i < Board.size() - 1; i++) {
		cout << Board[i] << ", ";
	}
	cout << Board[Board.size() - 1] << " ]\n";
}
void updateBoard(vector<int>& Board, int move) {
	auto iter = Board.begin();
	for (iter; iter < Board.end(); iter++) {
		if (*iter == move) {
			break;
		}
	}
	Board.erase(iter);
}
