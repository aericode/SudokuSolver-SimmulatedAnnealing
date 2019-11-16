#ifndef sudoku_h
#define sudoku_h


#include "cell.h"
#include <vector>
#include <string>

using namespace std;

class Sudoku{
public:
	Cell* puzzle;
	int level;//sqrt do size 
	int size;//tamanho da lateral (e nº de digitos)
	int cellCount;//num celulas

	int perfectScore;

	Sudoku();
	Sudoku(string);
	Sudoku(const Sudoku&);

	~Sudoku();

	int calcScore();
	int lineScore(int);
	int blockScore(int);

	Cell** getColumn(int);
	void initCol(int);
	void initSudoku();

	vector<int> getSwappableCols();
	void swapRandCells(int);

	void printPuzzle();
};

#endif