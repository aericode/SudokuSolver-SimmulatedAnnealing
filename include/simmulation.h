#ifndef simmulation_h
#define simmulation_h

#include "cell.h"
#include "sudoku.h"
#include <vector>
#include <string>


class Simmulation{
public:
	Sudoku* best;
	int bestScore;

	Sudoku* current;
	int currentScore;

	Sudoku* next;
	int nextScore;

	float temperature;

	int iterations;

	vector<int> swappableCols;

	Simmulation();
	Simmulation(string);

};

#endif