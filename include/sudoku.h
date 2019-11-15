#ifndef sudoku_h
#define sudoku_h

#include "cell.h"
#include <string>

using namespace std;

class Sudoku{
	Cell* puzzle;
	int size;
	int level;

	Sudoku();
	Sudoku(string);

	//int calcScore();
	int lineScore(int);
	int blockScore(int);
};

#endif