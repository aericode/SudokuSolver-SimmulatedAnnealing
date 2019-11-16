#include "simmulation.h"
#include "cell.h"
#include "sudoku.h"
#include <vector>
#include <string>
#include <math.h>

#define EULER 2.718

Simmulation::Simmulation(){}

Simmulation::Simmulation(string tip, float init_temp){
	temperature = init_temp;

	best = new Sudoku(tip);
	swappableCols = best->getSwappableCols();

	best->initSudoku();
	bestScore = best->calcScore();

	current = new Sudoku(*best);
	currentScore = bestScore;

	next = new Sudoku(*best);
	nextScore = 0;
}


bool Simmulation::testFlip(){
	int delta   = nextScore - currentScore;
	float value = pow(EULER, delta)/temperature;

	float rng   = ((double) rand() / (RAND_MAX));

	return(value > rng);
}