#include "simmulation.h"
#include "cell.h"
#include "sudoku.h"
#include <vector>
#include <string>

Simmulation::Simmulation(){}

Simmulation::Simmulation(string tip){
	best = new Sudoku(tip);
	swappableCols = best->getSwappableCols();

	best->initSudoku();
	bestScore = best->calcScore();

	current = new Sudoku(*best);
	currentScore = bestScore;
}