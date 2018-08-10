#include <stdio.h>
#include "def.h"
#include "game.h"
#include "board.h"

void setupKnightTests(Game g){
	setBoardBlank(g);
	set(g, KNIGHT, 3, 3);
}

void setupPawnTests(Game g, bool isBlk){
	setBoardBlank(g);
	if(isBlk){
		set(g, PAWN + BLK, 0, 6);
	}else{
		set(g, PAWN, 0, 1);
	}
}

void knightTests(Game g){

	// Up and Right
	setupKnightTests(g);
	assert(move(g, 3, 3, 4, 5));

	// Right and Up
	setupKnightTests(g);
	assert(move(g, 3, 3, 5, 4));

	// Down and Right
	setupKnightTests(g);
	assert(move(g, 3, 3, 5, 2));

	// Right and Down
	setupKnightTests(g);
	assert(move(g, 3, 3, 4, 1));

	// Left and Up
	setupKnightTests(g);
	assert(move(g, 3, 3, 1, 4));

	// Up and Left
	setupKnightTests(g);
	assert(move(g, 3, 3, 2, 5));

	// Left and Down
	setupKnightTests(g);
	assert(move(g, 3, 3, 1, 2));

	// Down and Left
	setupKnightTests(g);
	assert(move(g, 3, 3, 2, 1));

}

void pawnTests(Game g){

	// white pawn 1 space
	setupPawnTests(g, false);
	assert(move(g, 0, 1, 0, 2));

	// black pawn 1 space
	setupPawnTests(g, true);
	assert(move(g, 0, 6, 0, 5));

	// white pawn 2 space
	setupPawnTests(g, false);
	assert(move(g, 0, 1, 0, 3));

	// black pawn 2 space
	setupPawnTests(g, true);
	assert(move(g, 0, 6, 0, 4));

	// black pawn 1 space at wrong direction (FAIL)
	setupPawnTests(g, true);
	assert(!move(g, 0, 6, 0, 7));

	// white pawn 1 space wrong direction (FAIL)
	setupPawnTests(g, true);
	assert(!move(g, 0, 1, 0, 0));

	// pawn side 1 space (FAIL)
	setupPawnTests(g, false);
	assert(!move(g, 0, 1, 1, 1));

	// pawn 2 space wrong place (FAIL)
	setupPawnTests(g, false);
	move(g, 0, 1, 0, 2);
	assert(!move(g, 0, 2, 0, 4));

	// pawn 3 spaces (FAIL)
	setupPawnTests(g, false);
	assert(!move(g, 0, 1, 0, 4));

	// pawn CAPTURE right
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 1, 2);
	assert(move(g, 0, 1, 1, 2));

	// pawn CAPTURE left
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 0, 2);
	set(g, PAWN, 1, 1);
	assert(move(g, 1, 1, 0, 2));

	// pawn CAPTURE straight 1 space (FAIL)
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 0, 2);
	assert(move(g, 0, 1, 0, 2));

	// pawn CAPTURE straight 2 space (FAIL)
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 0, 3);
	assert(move(g, 0, 1, 0, 3));

}

int main(){

	Game g;

	newGameObj(&g, "test1");

	pawnTests(Game g);

	printBoard(g);

	getchar();
	return 0;
}


