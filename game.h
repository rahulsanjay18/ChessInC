struct Game{

	unsigned char ** board;
	char * saveFile;
	bool isWhiteTurn;
	bool isCheckmate;

};

typedef struct Game Game;

// initializes the game instance
void newGameObj(Game * gameInPlay, char * file_name);

unsigned char * readFile(char * file_name);

// clears the game instance
//void Game_destroy(Game * self);

// saves the file
//void saveFile();

// decodes the move and passes it to piece.c
//void makeMove(char * move);


