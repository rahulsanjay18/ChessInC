#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "game.h"
#include "board.h"
#include "piece.h"

extern unsigned char** gameBoard;

extern char * saveFile;

extern bool isWhiteTurn;

extern bool isCheckmate;

void Game_init(unsigned char ** boardPtr, char * saveFile, bool isWhiteTurn, bool isCheckMate){

	gameBoard = boardPtr;
	saveFile = saveFile;
	isWhiteTurn =  isWhiteTurn;
	isCheckmate = isCheckMate; 

}

void Game_create(char * file_name){
	printf("Game_create");
	bool isWhtTurn;
	bool isCheckMate;
	unsigned char ** board; 
	FILE * save_file;
	if(save_file = fopen(file_name, "r")){
		//file exists, so read it
		unsigned char * buffer = readFile(file_name);
		
		//determine some new booleans
		isWhtTurn = buffer[0] % 2 == 1;
		isCheckMate = buffer[0] % 4 == 1;
		
		// populate and return a board
		board = populateBoard(buffer);
	}else{
		//file does not exist, so create the board and populate the object
		isWhtTurn = true;
		isCheckMate = false;
		board = newBoard();	
	}

	Game_init(board, file_name, isWhtTurn, isCheckMate);

}

unsigned char * readFile(char * file_name){
	printf("readFile");
	FILE * fileptr = fopen(file_name, "rb");
	fseek(fileptr, 0, SEEK_END);
	long filelen = ftell(fileptr);

	rewind(fileptr);
	
	unsigned char * buffer = (char *) malloc((filelen+1) * sizeof(char));
	
	fread(buffer, filelen, 1, fileptr);
	
	fclose(fileptr);
	
	return buffer;

}
//void Game_destroy(Game * self);

//void saveFile();

//void makeMove(char * move);
