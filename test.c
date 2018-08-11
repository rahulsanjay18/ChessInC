#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "game.h"
#include "piece.h"
#include "board.h"

int i = 1;

void assert(bool isPassed){
	if(!isPassed){
		printf("Test # %d Failed.\n", i);
	}else{
		printf("Test # %d Passed.\n", i);
	}
	i++;
}

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

	// 14. Up and Right
	setupKnightTests(g);
	assert(move(g, 3, 3, 4, 5));

	// 15. Right and Up
	setupKnightTests(g);
	assert(move(g, 3, 3, 5, 4));

	// 16. Down and Right
	setupKnightTests(g);
	assert(move(g, 3, 3, 5, 2));

	// 17. Right and Down
	setupKnightTests(g);
	assert(move(g, 3, 3, 4, 1));

	// 18. Left and Up
	setupKnightTests(g);
	assert(move(g, 3, 3, 1, 4));

	// 19. Up and Left
	setupKnightTests(g);
	assert(move(g, 3, 3, 2, 5));

	// 20. Left and Down
	setupKnightTests(g);
	assert(move(g, 3, 3, 1, 2));

	// 21. Down and Left
	setupKnightTests(g);
	assert(move(g, 3, 3, 2, 1));

	// 22. Moved up three steps (FAIL)
	setupKnightTests(g);
	assert(!move(g, 3, 3, 3, 6));

}

void pawnTests(Game g){

	// 1. white pawn 1 space
	setupPawnTests(g, false);
	assert(move(g, 0, 1, 0, 2));
	
	// 2. black pawn 1 space
	setupPawnTests(g, true);
	assert(move(g, 0, 6, 0, 5));

	// 3. white pawn 2 space
	setupPawnTests(g, false);
	assert(move(g, 0, 1, 0, 3));

	// 4. black pawn 2 space
	setupPawnTests(g, true);
	assert(move(g, 0, 6, 0, 4));

	// 5. black pawn 1 space at wrong direction (FAIL)
	setupPawnTests(g, true);
	assert(!move(g, 0, 6, 0, 7));

	// 6. white pawn 1 space wrong direction (FAIL)
	setupPawnTests(g, true);
	assert(!move(g, 0, 1, 0, 0));

	// 7. pawn side 1 space (FAIL)
	setupPawnTests(g, false);
	assert(!move(g, 0, 1, 1, 1));

	// 8. pawn 2 space wrong place (FAIL)
	setupPawnTests(g, false);
	move(g, 0, 1, 0, 2);
	assert(!move(g, 0, 2, 0, 4));

	// 9. pawn 3 spaces (FAIL)
	setupPawnTests(g, false);
	assert(!move(g, 0, 1, 0, 4));

	// 10. pawn CAPTURE right
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 1, 2);
	assert(move(g, 0, 1, 1, 2));

	// 11. pawn CAPTURE left
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 0, 2);
	set(g, PAWN, 1, 1);
	assert(move(g, 1, 1, 0, 2));

	// 12. pawn CAPTURE straight 1 space (FAIL)
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 0, 2);
	assert(!move(g, 0, 1, 0, 2));

	// 13 .pawn CAPTURE straight 2 space (FAIL)
	setupPawnTests(g, false);
	set(g, BISHOP + BLK, 0, 3);
	assert(!move(g, 0, 1, 0, 3));

}

int main(){

	Game g;

	newGameObj(&g, "test1");

	pawnTests(g);
	knightTests(g);

	return 0;
}


