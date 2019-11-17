#include "cell.h"
#include "sudoku.h"
#include "simmulation.h"
#include <string>
#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>  

using namespace std;

int main(){
	srand(time(NULL));
	Simmulation test("1020020000040300",1000,0.9);

	test.seekAnswer(-1);

	/*
	Sudoku orig("0101132003030004");
	Simmulation test("0101132003030004",1000);

	test.best->printPuzzle();

	vector<int> swappable = test.swappableCols;

	for(int i=0;i<swappable.size();i++){
		cout<<swappable[i]<<endl;
	}

	
	Sudoku test(orig);
	//cout<<test.calcScore()<<endl;
	Cell** col;
	cout<<test.cellCount<<endl;
	cout<<test.size<<endl;
	cout<<test.level<<endl;

	
	for(int i=0;i<16;i++){
		cout<<test.puzzle[i].value;
		if(test.puzzle[i].is_tip)cout<<" - é dica";

		cout<<endl;
	}

	col = test.getColumn(0);
	for(int i=0;i<4;i++){
		cout<<col[i]->value;
		if(col[i]->is_tip)cout<<" - é dica";

		cout<<endl;
	}
	cout<<endl;
	test.initCol(0);
	for(int i=0;i<4;i++){
		cout<<col[i]->value;
		if(col[i]->is_tip)cout<<" - é dica";

		cout<<endl;
	}
	cout<<endl;
	test.swapRandCells(0);
	for(int i=0;i<4;i++){
		cout<<col[i]->value;
		if(col[i]->is_tip)cout<<" - é dica";

		cout<<endl;
	}

	test.printPuzzle();
	test.initSudoku();
	test.printPuzzle();
	*/

}