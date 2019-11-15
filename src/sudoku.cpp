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