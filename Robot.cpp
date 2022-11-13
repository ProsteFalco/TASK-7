#include "Robot.h"
#include <iostream>

Robot::Robot(int sizeX, int sizeY) { //constructor to assign values of rows and columns, also calls AllocateBoard
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	AllocateBoard();
}

int Robot::Max(int a, int b) { //function to determine which number is bigger
	if (a < b)
		return b;
	else
		return a;
}

int Robot::SolveCoinProblem(int ** inputArray) { //algorith based on pseudocode

	board[0][0] = inputArray[0][0];
	
	for (int i = 1; i < sizeY; i++) {
		board[0][i] = board[0][i - 1] + inputArray[0][i];
	}

	for (int i = 1; i < sizeX; i++) {
		board[i][0] = board[i - 1][0] + inputArray[i][0];
		for (int j = 1; j < sizeY; j++) {
			board[i][j] = Max(board[i - 1][j], board[i][j - 1]) + inputArray[i][j];
		}
	}

	return board[sizeX - 1][sizeY - 1];
}

void Robot::PrintBoard() { //prints out the board
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void Robot::ResetBoard() { //resets board to default
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			board[i][j] = 0;
		}
	}
}

void Robot::AllocateBoard() { //function to allocate 2D pointer array to board based on local X,Y values

	board = new int* [sizeX];

	for (int i = 0; i < sizeX; i++) {
		board[i] = new int[sizeY];
		for (int j = 0; j < sizeY; j++) {
			board[i][j] = 0;
		}
	}
}

void Robot::DeallocateBoard() { //function to deallocate board
	for (int i = 0; i < sizeX; i++) {
		delete[] board[i];
	}
	delete[] board;
}

void Robot::FindPath() { //function to find and print out found path

	//sets x,y to coordinates of last value in array (max column, max row)
	int x = sizeX - 1; 
	int y = sizeY - 1;

	//declaration and allocation of 2D char array, filling all values with 'O'
	char** path = new char* [sizeX];

	for (int i = 0; i < sizeX; i++) {
		path[i] = new char[sizeY];
		for (int j = 0; j < sizeY; j++) {
			path[i][j] = 'O';
		}
	}

	//while that runs until values get from end to start of the board array
	while (!(x == 0 && y == 0)) {
		path[x][y] = 'X'; //assign 'X' to coordinates of path


		//deciding on direction
		if (x == 0)
			y--;
		else if (y == 0)
			x--;
		else if (board[x - 1][y] > board[x][y - 1])
			x--;
		else if (board[x - 1][y] < board[x][y - 1])
			y--;
		else
			x--;
	}

	//sets start to 'X'
	path[0][0] = 'X';

	//printout of path array
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			std::cout << path[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//deallocation of path array
	for (int i = 0; i < sizeX; i++) {
		delete[] path[i];
	}
	delete[] path;

}