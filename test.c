#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "game.h"
#include "piece.h"
#include "board.h"
/*
char i = 1;

void assert(bool isPassed){
	if(!isPassed){
		printf("Test # %d Failed.\n", i);
	}else{
		//printf("Test # %d Passed.\n", i);
	}
	i++;
}

void setupQueenTests(Game g, char x, char y){
	setBoardBlank(g);
	set(g, QUEEN, x, y);
}

void setupKnightTests(Game g){
	setBoardBlank(g);
	set(g, KNIGHT, 3, 3);
}

void setupBishopTests(Game g, char x, char y){
	setBoardBlank(g);
	set(g, BISHOP, x, y);
}

void setupRookTests(Game g){
	setBoardBlank(g);
	set(g, ROOK, 0, 0);
}
void setupPawnTests(Game g, bool isBlk){
	setBoardBlank(g);
	if(isBlk){
		set(g, PAWN + BLK, 0, 6);
	}else{
		set(g, PAWN, 0, 1);
	}

}
void bishopTests(Game g){

	// 23. iterate from bottom left corner to top right
	setupBishopTests(g, 0, 7);
	bool assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 7, i, 7-i)){
			assertVal = false;
		}else{
			move(g, i, 7-i, 0, 7);
		}
		
	}
	assert(assertVal);

	// 24. iterate from bottom right corner to top left
	setupBishopTests(g, 7, 7);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 7, 7, 7-i, 7-i)){
			assertVal = false;
			
		}else{
			move(g,  7-i, 7-i, 7, 7);
		}
		
	}
	assert(assertVal);

	// 25. iterate from top left corner to bottom right
	setupBishopTests(g, 0, 0);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 0, i, i)){
			assertVal = false;
			
		}else{
			move(g, i, i, 0, 0);
		}
		
	}
	assert(assertVal);

	// 26. iterate from top right corner to bottom left
	setupBishopTests(g, 7, 0);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 7, 0, 7-i, i)){
			assertVal = false;
			
		}else{
			move(g, 7-i, i, 7, 0);
		}
		
	}
	assert(assertVal);

	// 27. move straight 3 spaces (FAIL)
	setupBishopTests(g, 0, 0);
	assert(!move(g, 0, 0, 0, 3));

	// 28. Move to the side 3 spaces (FAIL)
	setupBishopTests(g, 0, 0);
	assert(!move(g, 0, 0, 3, 0));

	// 29. Move piece so something is blocking the path (FAIL)
	setupBishopTests(g, 0, 0);
	set(g, PAWN, 1, 1);
	assert(!move(g, 0, 0, 3, 3));

}

void rookTests(Game g){
	// 30. Iterate from bottom left to bottom right
	setupRookTests(g);
	bool assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 0, 0, i)){
			assertVal = false;
		}else{
			move(g, 0, i , 0, 0);
		}
	}
	assert(assertVal);


	// 31. Iterate from bottom left to top left
	setupRookTests(g);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 0, i, 0)){
			assertVal = false;
		}else{
			move(g, i, 0, 0, 0);
		}
	}
	assert(assertVal);

	// 32. move diagonally 3 spaces (FAIL)
	setupRookTests(g);
	assert(!move(g, 0, 0, 3, 3));

	// 33. move with a piece in the way (FAIL)
	setupRookTests(g);
	set(g, PAWN, 1, 0);
	assert(!move(g, 0, 0, 3, 0));
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

void queenTests(Game g){
	
	// 34. Iterate from bottom left to bottom right
	setupQueenTests(g, 0, 0);
	bool assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 0, 0, i)){
			assertVal = false;
		}else{
			move(g, 0, i , 0, 0);
		}
	}
	assert(assertVal);


	// 35. Iterate from bottom left to top left
	setupQueenTests(g, 0, 0);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 0, i, 0)){
			assertVal = false;
		}else{
			move(g, i, 0, 0, 0);
		}
	}

	// 36. iterate from bottom left corner to top right
	setupQueenTests(g, 0, 7);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 7, i, 7-i)){
			assertVal = false;
			
		}else{
			move(g, i, 7-i, 0, 7);
		}
		
	}
	assert(assertVal);

	// 37. iterate from bottom right corner to top left
	setupQueenTests(g, 7, 7);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 7, 7, 7-i, 7-i)){
			assertVal = false;
			
		}else{
			move(g,  7-i, 7-i, 7, 7);
		}
		
	}
	assert(assertVal);

	// 38. iterate from top left corner to bottom right
	setupQueenTests(g, 0, 0);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 0, 0, i, i)){
			assertVal = false;
			
		}else{
			move(g, i, i, 0, 0);
		}
		
	}
	assert(assertVal);

	// 39. iterate from top right corner to bottom left
	setupQueenTests(g, 7, 0);
	assertVal = true;
	for(char i = 1; i < 8; i++){
		if(!move(g, 7, 0, 7-i, i)){
			assertVal = false;
			
		}else{
			move(g, 7-i, i, 7, 0);
		}
		
	}
	assert(assertVal);

	// 40. Up and Right
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 4, 5));

	// 41. Right and Up
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 5, 4));

	// 42. Down and Right
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 5, 2));

	// 43. Right and Down
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 4, 1));

	// 44. Left and Up
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 1, 4));

	// 45. Up and Left
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 2, 5));

	// 46. Left and Down
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 1, 2));

	// 47. Down and Left
	setupQueenTests(g, 3, 3);
	assert(!move(g, 3, 3, 2, 1));

}
*/
char main(){

	Game g;

	newGameObj(&g, "test1");

	printBoard(g);
	
	
	
	return 0;
}


