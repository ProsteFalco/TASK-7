#include <iostream>
#include <vector>

class Robot
{
private:
	int** board;								//board 2D array
	int sizeX;									//rows
	int sizeY;									//columns									
	void ResetBoard();							//function to reset board to default
	int Max(int a, int b);						//function to determine bigger of two numbers
public:
	Robot(int sizeX, int sizeY);				//constructor
	void AllocateBoard();						//function to allocate board
	void DeallocateBoard();						//function to deallocate board
	int SolveCoinProblem(int ** inputArray);	//algorithm returning max number of coins
	void PrintBoard();							//printout of board
	void FindPath();							//printout of found path
};


