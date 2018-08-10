unsigned char ** newBoard();
void setBoardBlank(Game gameInPlay);
void printBoard(Game gameInPlay);
void set(Game gameInPlay, char val, char x, char y);
void swap(Game gameInPlay, char x1, char y1, char x2, char y2);
char get(Game gameInPlay, char x, char y);
void erase(Game gameInPlay, char x, char y);
unsigned char ** allocateBoardMemory();

