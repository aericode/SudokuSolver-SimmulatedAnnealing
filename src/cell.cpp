#include "cell.h"

Cell::Cell(){
	is_tip = false;
}

Cell::Cell(int value_){
	value  = value_; 

	if(value == 0){
		is_tip = false;
	}else{
		is_tip = true;
	}
	
}