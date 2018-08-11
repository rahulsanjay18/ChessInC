// definitions for each of the pieces as integers
/* Pieces are defined as 4 bits:
0 0 0 0
^ ^ ^ ^
3 2 1 0

bits 0-2: Define type of piece
bit 3: define color

*/
#define PAWN 1
#define ROOK 2
#define BISHOP 3
#define KNIGHT 4
#define QUEEN 5
#define KING 6
#define BLANK 7

#define BLK 8
#define WHT 0

// define macros
#define setLow(num, pt) (num & 240) + pt
#define setHigh(num, pt) (num & 15) + (pt << 4)
#define getLow(num) num & 15
#define getHigh(num) (num & 240) >> 4
#define getPiece(p) p & 7
#define getColor(p) p & 8

// define bool type
typedef enum {false,true} bool;
