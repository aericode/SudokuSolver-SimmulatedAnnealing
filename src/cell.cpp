#include "cell.h"

Cell::Cell(){}

Cell::Cell(int value_){
	is_tip = (value_ == 0);
	value  = value_; 
}

void Cell::setValue(int value_){
	is_tip = (value_ == 0);
	value  = value_; 
}