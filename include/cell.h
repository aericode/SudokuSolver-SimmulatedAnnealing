#ifndef cell_h
#define cell_h

class Cell{
public:
	int value;
	bool is_tip;

	Cell();
	Cell(int);

	void setValue(int);
};


#endif