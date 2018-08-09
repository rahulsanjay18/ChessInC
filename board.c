#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "game.h"

unsigned char ** allocateBoardMemory(){
	// creates a blank 8x8 array
	unsigned char** board = (unsigned char**) malloc(8*sizeof(unsigned char *));

	for(char i = 0; i < 8; i++){
		board[i] = (unsigned char*) malloc(4*sizeof(unsigned char));
	}

	return board;
}

//reads buffer file
unsigned char** populateBoard(char * buffer){
	unsigned char** board = allocateBoardMemory();

	// row THEN col
	for(char i = 0; i < 8; i++){
		if(i == 0){
			board[i][0] = ((BLK + ROOK) << 4) + (BLK + BISHOP);
			board[i][1] = ((BLK + KNIGHT) << 4) + (BLK + QUEEN);
			board[i][2] = ((BLK + KING) << 4) + (BLK + KNIGHT);
			board[i][3] = ((BLK + BISHOP) << 4) + (BLK + ROOK);
		}else if(i == 7){
			board[i][0] = ((ROOK) << 4) + (BISHOP);
		    board[i][1] = ((KNIGHT) << 4) + (QUEEN);
	        board[i][2] = ((KING) << 4) + (KNIGHT);
            board[i][3] = ((BISHOP) << 4) + (ROOK);
	
		}else if(i == 1){
			for(char j = 0; j < 4; j++){
				board[i][j] = ((PAWN + BLK) << 4) + (PAWN + BLK);
			}
		}else if(i == 6){
			for(char j = 0; j < 4; j++){
				board[i][j] = (PAWN << 4) + PAWN;
			}
		}else{
			for(char j = 0; j < 4; j++){
				board[i][j] = (BLANK << 4) + BLANK;
			}
		}
	}
	
	return board;
} 

// creates a new board for a new game
unsigned char** newBoard(){
	
	unsigned char** board = allocateBoardMemory();

	// row THEN col
	for(char i = 0; i < 8; i++){
		if(i == 0){
			board[i][0] = ((BLK + ROOK) << 4) + (BLK + BISHOP);
			board[i][1] = ((BLK + KNIGHT) << 4) + (BLK + QUEEN);
			board[i][2] = ((BLK + KING) << 4) + (BLK + KNIGHT);
			board[i][3] = ((BLK + BISHOP) << 4) + (BLK + ROOK);
		}else if(i == 7){
			board[i][0] = ((ROOK) << 4) + (BISHOP);
		    board[i][1] = ((KNIGHT) << 4) + (QUEEN);
	        board[i][2] = ((KING) << 4) + (KNIGHT);
            board[i][3] = ((BISHOP) << 4) + (ROOK);
	
		}else if(i == 1){
			for(char j = 0; j < 4; j++){
				board[i][j] = ((PAWN + BLK) << 4) + (PAWN + BLK);
			}
		}else if(i == 6){
			for(char j = 0; j < 4; j++){
				board[i][j] = (PAWN << 4) + PAWN;
			}
		}else{
			for(char j = 0; j < 4; j++){
				board[i][j] = (BLANK << 4) + BLANK;
			}
		}
	}
	
	return board;
}

// outputs the current board
void printBoard(Game gameInPlay){
	
	for(char i = 0; i < 8 ; i++){
		for(char j = 0; j < 4 ;j++){
			printf("%x", gameInPlay.board[i][j]);
		}
		printf("\n");
	}

}

// puts a value in a certain position
void set(Game gameInPlay, char val, char x, char y){

	bool isLow = y % 2;
	y = y / 2;
	char editedByte;

	if(isLow){
		editedByte = setLow(gameInPlay.board[x][y], val);
	}else{
		editedByte = setHigh(gameInPlay.board[x][y], val);
	}
	
	gameInPlay.board[x][y] = editedByte;

}

// returns the value at the location
char get(Game gameInPlay, char x, char y){

	bool isLow = y % 2;
	y = y / 2;

	if(isLow){
		return getLow(gameInPlay.board[x][y]);
	}else{
		return getHigh(gameInPlay.board[x][y]);
	}

}

// sets the position in the currentGame.board to a blank value
void erase(Game gameInPlay, char x, char y){
	set(gameInPlay, BLANK, x, y);
}

// switches two values in the currentGame.board
void swap(Game gameInPlay, char x1, char y1, char x2, char y2){
	
	unsigned char pHold = get(gameInPlay, x1, y1);

	set(gameInPlay, gameInPlay.board[x2][y2], x1, y1);

	set(gameInPlay, pHold, x2, y2);

}
