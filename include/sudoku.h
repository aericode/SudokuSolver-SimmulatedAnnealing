#ifndef sudoku_h
#define sudoku_h

#include "cell.h"
#include <string>

using namespace std;

class Sudoku{
	Cell* puzzle;

	Sudoku();
	Sudoku(string);
};

#endif