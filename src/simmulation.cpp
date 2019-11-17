#include "simmulation.h"
#include "cell.h"
#include "sudoku.h"
#include <vector>
#include <string>
#include <math.h>

#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>

using namespace std;

#define EULER 2.718

Simmulation::Simmulation(){}

Simmulation::Simmulation(string tip, float init_temp, float cooldownRate_){
	temperature = init_temp;
	cooldownRate = cooldownRate_;

	best = new Sudoku(tip);
	swappableCols = best->getSwappableCols();

	best->initSudoku();
	bestScore = best->calcScore();

	current = new Sudoku(*best);
	currentScore = bestScore;

	next = new Sudoku(*best);
	nextScore = 0;

	perfectScore = current->perfectScore;
}


bool Simmulation::testFlip(){
	int delta   = nextScore - currentScore;
	float value = pow(EULER, delta)/temperature;

	float rng   = ((double) rand() / (RAND_MAX));

	return(value > rng);
}

void Simmulation::refrigerate(){
	temperature = temperature*cooldownRate;
}

void Simmulation::simStep(){
	int auxRandCol;
	int swapCol;

	delete next;
	next = new Sudoku(*current);

	auxRandCol = rand()%swappableCols.size();
	swapCol    = swappableCols[auxRandCol];

	next->swapRandCells(swapCol);
	nextScore = next->calcScore();

	if(nextScore > currentScore){
		delete current;
		current = new Sudoku(*next);
		currentScore = nextScore;

		if(nextScore > bestScore){
			delete best;
			best = new Sudoku(*next);
			bestScore    = nextScore;
		}

	}else{
		if(testFlip()){
			delete current;
			current = new Sudoku(*next);

			currentScore = nextScore;
		}
	}

	refrigerate();

}

void Simmulation::seekAnswer(int step_limit){
	int step = 0;

	while(bestScore < perfectScore && step != step_limit){
		simStep();
		step++;

		cout<<"current : "<<currentScore<<endl;
		cout<<"best    : "<<bestScore<<endl;

		cout<<endl<<endl;
	}

	cout<<"after "<<step <<" attempts"<<endl;
	if(bestScore == perfectScore){
		cout<<"exact solution found : "<<endl;
	}else{
		cout<<"exact solution not found "<<endl;
		cout<<"best attempt score: "<< bestScore <<endl;
		cout<<"closest result found: "<<endl;
	}

	best->printPuzzle();

}