#include "cell.h"
#include "sudoku.h"
#include <string>
#include <math.h>
#include <vector>
#include <iostream>


using namespace std;


Sudoku::Sudoku(){}

Sudoku::Sudoku(string tip_){
	cellCount = tip_.size();
	puzzle = new Cell[cellCount];

	size  = sqrt(cellCount);
	level = sqrt(size);

	//melhor nota para linha = size
	//nº linhas = size
	//mesma coisa para blocos
	int perfectScore = 2*size*size;

	int currentValue;
	for (int i = 0; i<cellCount; i++) { 
    	currentValue = tip_[i] - 48;
    	puzzle[i].value  = currentValue;
    	
    	puzzle[i].is_tip = (currentValue != 0);
    }
}

Sudoku::Sudoku(Sudoku original){
	cellCount = original.cellCount;
	size      = original.size;
	level     = original.level;

	perfectScore = original.perfectScore;

	puzzle = new Cell[cellCount];
	for(int i = 0; i<cellCount; i++){
		puzzle[i].value  = original[i].value;
		puzzle[i].is_tip = original[i].is_tip;
	}
}

int Sudoku::lineScore(int lineIndex){
	int score = 0;
	//todos os caracteres já vistos
	bool* seen = new bool[size+1];
	//(inclusive) ponto do sudoku linearizado onde começar
	int startPoint = lineIndex*size;
	//(non-inclusive) ponto de parada
	int endPoint   = startPoint + size;
	for(int i = 0; i < size; i++){
		seen[i] = false;
	}

	int seenIndex;
	for (int i = startPoint; i < endPoint; i++){
		seenIndex = puzzle[i].value;
		seen[seenIndex] = true;
	}

	for(int i = 1; i < (size+1); i++){
		if(seen[i])score++;
	}

	delete[] seen;

	return score;
}

int Sudoku::blockScore(int index){
	int score = 0;
	//todos os caracteres vistos
	// bool[1] = true significa que eu já vi o 1
	//"lista dos numeros ja vistos"
	//se tem um faltando há repetiçãp
	bool* seen = new bool[size+1];
	for(int i = 0; i < (size+1); i++){
		seen[i] = false;
	}
	int seenIndex;//o numero observado

	int rowIndex   = (index/size)*size; //a linha a que pertence
	int colIndex   =  index%size;       //a coluna a que pertence
	int blockIndex = ((rowIndex/level)*level + colIndex/level); //o bloco a que pertence
	int current; //o indice do elemento sendo avalado dentro do laço

	//auxilio para calcular a celula onde iniciar a busca
	int blockCol = blockIndex%level;
	int blockRow = blockIndex/level;

	//diz o número de linhas para pular a cada linha de bloco
	//é a célula que inicia o bloco
	int startCellIndex = blockRow*level*size + blockCol*level;

	int i;//linha de bloco
	int j;//coluna de bloco
	for(i = 0;i < level; i ++){//cada "i" que aumenta vai pular size blocos
		for(j = 0; j < level;j++){
			current = startCellIndex + (size*i + j); //avançar size coloca você na coluna abaixo da sua
			seenIndex = puzzle[current].value;
			seen[seenIndex] = true;
		}
		j=0;//volta pra colina zero
	}

	for(int i = 1; i < (size+1); i++){
		if(seen[i])score++;
	}

	delete[] seen;

	return score;

}

int Sudoku::calcScore(){
	int score = 0;
	for(int i=0;i<size;i++){
		score += lineScore(i);
	}

	for(int i=0;i<size;i++){
		score += blockScore(i);
	}

	return score;
}

Cell** Sudoku::getColumn(int index){
	int current;
	Cell** col = new Cell*[size];
	for (int i=0;i<size;i++){
		//offset to get a collumn
		current = index + i*size;
		col[i] = &puzzle[current];
	}
	return col;
}

//inicia uma coluna sem numeros repetidos
void Sudoku::initCol(int index){
	Cell** col = getColumn(index);

	vector<int> randomPool;
	bool* seen = new bool[size+1];
	int seenIndex;
	for (int i = 0; i < size; i++){
		seenIndex = col[i]->value;
		seen[seenIndex] = true;
	}

	//só numeros que nao foram dados como dica na coluna podem ser adicionados
	//pula o zero
	for(int i=1; i < (size+1);i++){
		if(!seen[i]){
			randomPool.push_back(i);
		}
	}

	//selected from pool index, adds to col then removes from pool
	int poolIndex;
	for(int i = 0; i < size; i++){
		if(col[i]->value == 0){
			//pega um valor entre os restantes e atribui ao elemento
			poolIndex = rand() % randomPool.size();
			//pega o valor e coloca na coluna
			col[i]->value = randomPool[poolIndex];
			//remove o valor da pool
			randomPool.erase(randomPool.begin() + poolIndex);
		}
	}

	delete[] col;
}

void Sudoku::initSudoku(){
	for(int i = 0;i < size; i++){
		initCol(i);
	}
}

vector<int> Sudoku::getSwappableCols(){
	vector<int> swappableList;
	Cell** current;
	int count;
	for(int i = 0;i < size; i++){//pega colunas
		count = 0;
		current = getColumn(i);
		for(int j = 0; j < size; j++){//pega elementos das colunas
			if(current[j]->is_tip)count++;
		}

		if(count < (size-1) ){
			swappableList.push_back(i);
		}
	}
}