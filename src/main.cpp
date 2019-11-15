#include "cell.h"
#include "sudoku.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
	Sudoku test("1111222233334444");
	//cout<<test.calcScore()<<endl;
	Cell** col = test.getColumn(0);
	cout<<test.cellCount<<endl;
	cout<<test.size<<endl;
	cout<<test.level<<endl;

	for(int i=0;i<4;i++){
		cout<<col[0]->value<<endl;
	}
}