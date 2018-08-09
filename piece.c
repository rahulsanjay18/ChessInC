#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "def.h"
#include "game.h"

bool isStraightLine(char x1, char y1, char x2, char y2){
	
	char high;
	char low;
	char val;
	if(x1 == x2){
		high = (y1 > y2) ? y1 : y2;
		low = (y2 > y1) ? y1 : y2;
	}else if(y1 == y2){
		high = (x1 > x2) ? x1 : x2;
		low = (x2 > x1) ? x2 : x1;
	}else{
		return false;
	}

	for(char i = low; i <= high; i++){
		val = (x1 == x2) ? get(x1, i) : get(i, y1);

		if(val != BLANK){
			return false;
		}
	}
	
	return true;

}

bool isDiagonal(char x1, char y1, char x2, char y2){
	
	if(x1 - x2 == y1 - y2){
		for(char i = 0; i <= x1 - x2; i++){
			
			if(get(x1 + i, y1 + i) != BLANK){
				return false;
			}
			
		}

		return true;
	}

	return false;

}

bool isLShape(char x1, char y1, char x2, char y2){

	return (abs(x1 - x2) == 3 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 3);

}

bool isPawnMove(char x1, char y1, char x2, char y2, bool isBlk){

	return (((x1 == 1 && isBlk == BLK) || (x1 == 7 && isBlk == WHT)) && (x1 == x2 && y1 + 2 == y2)) || (x1 == x2 && y1 + 1 == y2);
	
}

bool isKingMove(char x1, char y1, char x2, char y2){

	return abs(x1 - x2) == 1 || abs(y1 - y2) == 1;

}

bool isPawnAtk(bool color, char x1, char y1, char x2, char y2){
	
	bool sideBoard;

	if(color){

		sideBoard = y2 - y1 == 1;

	}else{

		sideBoard = y1 - y2 == 1;
	
	}

	return sideBoard && abs(x1 - x2) == 1 && get(x2, y2) != BLANK;

}


bool isValid(char piece, char x1, char y1, char x2, char y2){

	bool isBlk = getColor(piece) == BLK;

	piece = getPiece(piece);

	if(x1 == x2 && y1 == y2){
		return false;
	}
	// MISSING: Check if move is being made by the correct player
	if(get(x1, y1) == BLANK){
		return false;
	}

	if(get(x2, y2) != BLANK && getColor(get(x1, y1)) == getColor(get(x2, y2))){
		return false;
	}

	switch(piece){
		case PAWN:
			return isPawnMove(x1, y1, x2, y2, isBlk) || isPawnAtk(isBlk, x1, y1, x2, y2);
		break;
		case KNIGHT:
			return isLShape(x1, y1, x2, y2);
		break;
		case ROOK:
			return isStraightLine(x1, x2, y1, y2);
		break;
		case BISHOP:
			return isDiagonal(x1, y1, x2, y2);
		break;
		case QUEEN:
			return isStraightLine(x1, y1, x2, y2) || isDiagonal(x1, y1, x2, y2);
		break;
		case KING:
			return isKingMove(x1, y1, x2, y2);
		break;
		default:
			printf("Invalid piece. How did that happen?");
		break;
	}

	return false;

}


void move(char x1, char y1, char x2, char y2){

	char piece = get(x1, y1);

	if(isValid(piece, x1, y1, x2, y2)){
		set(piece, x2, y2);
		erase(x2, y2);
	}
	
}


