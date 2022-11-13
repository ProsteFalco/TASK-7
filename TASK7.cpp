#include <iostream>
#include "Robot.h"

int main()
{
    srand(time(0)); //srand for the "true" random

    //allocation of three different 2D int arrays and filling their indexes with 0s or 1s (coin or !coin)

    int** array1 = new int*[5];

    for (int i = 0; i < 5; i++) {
        array1[i] = new int[6];
        for (int j = 0; j < 6; j++) {
            array1[i][j] = rand() % 2;
        }
    }

    int** array2 = new int* [4];

    for (int i = 0; i < 4; i++) {
        array2[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            array2[i][j] = rand() % 2;
        }
    }

    int** array3 = new int* [10];

    for (int i = 0; i < 10; i++) {
        array3[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            array3[i][j] = rand() % 2;
        }
    }


    //creation of three robot objects
    Robot r1(5, 6);
    Robot r2(4, 4);
    Robot r3(10,10);

    //printout of all boards after algorithm and their paths

    int result1 = r1.SolveCoinProblem(array1);
    std::cout << "Board 1: (max coins: " << result1 << "):" << std::endl;
    r1.PrintBoard();
    std::cout << "Path 1:" << std::endl;
    r1.FindPath();

    std::cout << std::endl;

    int result2 = r2.SolveCoinProblem(array2);
    std::cout << "Board 2: (max coins: " << result2 << "):" << std::endl;
    r2.PrintBoard();
    std::cout << "Path 2:" << std::endl;
    r2.FindPath();

    std::cout << std::endl;

    int result3 = r3.SolveCoinProblem(array3);
    std::cout << "Board 3 (max coins: " << result3 << "):" << std::endl;
    r3.PrintBoard();
    std::cout << "Path 3:" << std::endl;
    r3.FindPath();

    //deallocation 

    for (int i = 0; i < 5; i++) {
        delete[] array1[i];
    }
    delete[] array1;

    for (int i = 0; i < 2; i++) {
        delete[] array2[i];
    }
    delete[] array2;

    for (int i = 0; i < 10; i++) {
        delete[] array3[i];
    }
    delete[] array3;
    
}



