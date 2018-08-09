

extern unsigned char** gameBoard;

extern char * saveFile;

extern bool isWhiteTurn;

extern bool isCheckmate;

// initializes the game instance
void Game_create(char * file_name);

unsigned char * readFile(char * file_name);

// clears the game instance
//void Game_destroy(Game * self);

// saves the file
//void saveFile();

// decodes the move and passes it to piece.c
//void makeMove(char * move);


