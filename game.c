#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "game.h"
#include "board.h"
#include "piece.h"


void initGame(Game * gameInPlay, unsigned char** board, char * file_name, bool isWhtTurn, bool isCheckMate){
	gameInPlay->board = board;
	gameInPlay->saveFile = file_name;
	gameInPlay->isWhiteTurn = isWhtTurn;
	gameInPlay->isCheckmate = isCheckMate;
}

void newGameObj(Game * gameInPlay, char * file_name){
	
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
		//save_file = fopen(file_name, "w");
		isWhtTurn = true;
		isCheckMate = false;
		board = newBoard();	
	}

	initGame(gameInPlay, board, file_name, isWhtTurn, isCheckMate);

}

unsigned char * readFile(char * file_name){
	FILE * fileptr = fopen(file_name, "rb");
	fseek(fileptr, 0, SEEK_END);
	long filelen = ftell(fileptr);

	rewind(fileptr);
	
	unsigned char * buffer = (char *) malloc((filelen+1) * sizeof(char));
	
	fread(buffer, filelen, 1, fileptr);
	
	fclose(fileptr);
	
	return buffer;

}
/*void Game_destroy(Game * self){
	free(self);
}

void saveFile(Game g){
	unsigned char ** saveData = malloc(8 * sizeof(unsigned char));
}
*/
//void makeMove(char * move);
