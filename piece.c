#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "game.h"
#include "board.h"



bool isStraightLine(Game gameInPlay, char x1, char y1, char x2, char y2){
	
	char high;
	char low;
	char val;

	if(x1 == x2){

		high = (y1 > y2) ? y1 : y2;
		low = (y2 > y1) ? y1 : y2;
	}else if(y1 == y2){
		
		high = (x1 > x2) ? x1 : x2;
		low = (x2 > x1) ? x1 : x2;
	}else{

		return false;
	}
	
	for(char i = low + 1; i < high; i++){
		val = (x1 == x2) ? get(gameInPlay, x1, i) : get(gameInPlay, i, y1);
		if(val != BLANK){
			return false;
		}
	}
	
	return true;

}

bool isDiagonal(Game gameInPlay, char x1, char y1, char x2, char y2){
	char lenX = (x1 > x2) ? x1 - x2 : x2 - x1;
	char lenY = (y1 > y2) ? y1 - y2 : y2 - y1;

	if(lenX == lenY){
		char dx = 0;
		char dy = 0;
		for(char i = 1; i < lenX; i++){
			dx = (x1 > x2) ? x1 - i: x1 + i;
			dy = (y1 > y2) ? y1 - i: y1 + i;
			if(get(gameInPlay, dx, dy) != BLANK){
				return false;
			}
			
		}

		return true;
	}

	return false;

}

bool isLShape(char x1, char y1, char x2, char y2){

	bool xLong = abs(x1 - x2) == 2 && abs(y1 - y2) == 1;
	bool yLong = abs(x1 - x2) == 1 && abs(y1 - y2) == 2;

	return xLong || yLong;

}

bool isPawnMove(Game gameInPlay, char x1, char y1, char x2, char y2, bool isBlk){
	
	bool isStraight = (x1 == x2);

	bool isTwoMove = (((y1 == 1 && !isBlk) && y1 + 2 == y2) || ((y1 == 6 && isBlk)) && y1 - 2 == y2);
	
	bool isOneMove = (!isBlk && y1 + 1 == y2) || (isBlk && y1 - 1 == y2);
	
	bool isPathClear = get(gameInPlay, x2, y2) == BLANK;

	return isStraight && isPathClear && (isOneMove || isTwoMove);
	
}

bool isKingMove(Game gameInPlay, char x1, char y1, char x2, char y2){

	return abs(x1 - x2) == 1 || abs(y1 - y2) == 1;

}

bool isPawnAtk(Game gameInPlay, bool color, char x1, char y1, char x2, char y2){
	
	bool sideBoard;

	if(color){

		sideBoard = y1 - y2 == 1;

	}else{

		sideBoard = y2 - y1 == 1;
	
	}

	return sideBoard && abs(x1 - x2) == 1 && get(gameInPlay, x2, y2) != BLANK;

}

bool isInBounds(char x1, char y1, char x2, char y2){
	if(x1 < 0 && x1 > 7){
		return false;
	}

	if(x2 < 0 && x2 > 7){
		return false;
	}

	if(y1 < 0 && y1 > 7){
		return false;
	}

	if(y2 < 0 && y2 > 7){
		return false;
	}

	return true;
}

bool isMoveAble(Game gameInPlay, char x1, char y1, char x2, char y2){
	// same move
	if(x1 == x2 && y1 == y2){
		return false;
	}
	// MISSING: Check if move is being made by the correct player

	// there is no piece there
	if(get(gameInPlay, x1, y1) == BLANK){
		return false;
	}

	// if the piece cannot be overriden
	if(get(gameInPlay, x2, y2) != BLANK && getColor(get(gameInPlay, x1, y1)) == getColor(get(gameInPlay, x2, y2))){
		return false;
	}

	return true;
}

bool canPieceMove(Game gameInPlay, char piece, char x1, char y1, char x2, char y2, bool isBlk){
	
	switch(piece){
		case PAWN:
			return isPawnMove(gameInPlay, x1, y1, x2, y2, isBlk) || isPawnAtk(gameInPlay, isBlk, x1, y1, x2, y2);
		break;
		case KNIGHT:
			return isLShape(x1, y1, x2, y2);
		break;
		case ROOK:
			return isStraightLine(gameInPlay, x1, y1, x2, y2);
		break;
		case BISHOP:
			return isDiagonal(gameInPlay, x1, y1, x2, y2);
		break;
		case QUEEN:
			return isStraightLine(gameInPlay, x1, y1, x2, y2) || isDiagonal(gameInPlay, x1, y1, x2, y2);
		break;
		case KING:
			return isKingMove(gameInPlay, x1, y1, x2, y2);
		break;
		default:
			printf("Invalid piece. How did that happen?\n");
		break;
	}

	return false;
}

bool isValid(Game gameInPlay, char piece, char x1, char y1, char x2, char y2){
	
	bool isBlk = false;

	if(piece > BLK){
		isBlk = true;
	}

	piece = getPiece(piece);
	
	return isInBounds(x1, y1, x2, y2) && isMoveAble(gameInPlay, x1, y1, x2, y2) && canPieceMove(gameInPlay, piece, x1, y1, x2, y2, isBlk);

}


bool move(Game gameInPlay, char x1, char y1, char x2, char y2){

	char piece = get(gameInPlay, x1, y1);

	if(isValid(gameInPlay, piece, x1, y1, x2, y2)){
		set(gameInPlay, piece, x2, y2);
		erase(gameInPlay, x2, y2);
		return true;
	}
	
	return false;
}


