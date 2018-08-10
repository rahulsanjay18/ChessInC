
bool move(Game gameInPlay, char x1, char y1, char x2, char y2);
bool isValid(Game gameInPlay, char piece, char x1, char y1, char x2, char y2);
bool isStraightLine(Game gameInPlay, char x1, char y1, char x2, char y2);
bool isDiagonal(Game gameInPlay, char x1, char y1, char x2, char y2);
bool isLShape(char x1, char y1, char x2, char y2);
bool isPawnMove(Game gameInPlay, char x1, char y1, char x2, char y2, bool isBlk);
bool isKingMove(char x1, char y1, char x2, char y2);
bool isPawnAtk(Game gameInPlay, bool color, char x1, char y1, char x2, char y2);
