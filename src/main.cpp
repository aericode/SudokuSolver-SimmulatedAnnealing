#include "cell.h"
#include "sudoku.h"
#include <string>
#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>  

using namespace std;

int main(){
	srand(time(NULL));

	Sudoku orig("0111122203330444");
	Sudoku test(orig);
	//cout<<test.calcScore()<<endl;
	Cell** col;
	cout<<test.cellCount<<endl;
	cout<<test.size<<endl;
	cout<<test.level<<endl;

	/*
	for(int i=0;i<16;i++){
		cout<<test.puzzle[i].value;
		if(test.puzzle[i].is_tip)cout<<" - é dica";

		cout<<endl;
	}
	*/
	
	/*
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
	*/
	test.printPuzzle();
	test.initCol(0);
	test.printPuzzle();

}