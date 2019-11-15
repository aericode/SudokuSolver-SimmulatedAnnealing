#include "cell.h"
#include "sudoku.h"
#include <string>


using namespace std;


Sudoku::Sudoku(){}

Sudoku::Sudoku(string tip_){
	int cellCount = tip_.size();
	puzzle = new Cell[cellCount];
	int currentValue;

	for (int i = 0; i<cellCount; i++) { 
    	currentValue = tip_[i] - 48;
    	puzzle[i].setValue(currentValue);
    }
}