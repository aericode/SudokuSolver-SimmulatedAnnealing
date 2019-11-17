#ifndef simmulation_h
#define simmulation_h

#include "cell.h"
#include "sudoku.h"
#include <vector>
#include <string>


class Simmulation{
public:
	int perfectScore;

	Sudoku* best;
	int bestScore;

	Sudoku* current;
	int currentScore;

	Sudoku* next;
	int nextScore;

	float temperature;
	float cooldownRate;

	int iterations;

	vector<int> swappableCols;

	Simmulation();
	Simmulation(string,float,float);

	bool testFlip();

	void refrigerate();

	void simStep();

	void seekAnswer(int);

};

#endif