
void move(char x1, char y1, char x2, char y2);
bool isValid(char piece, char x1, char y1, char x2, char y2);
bool isStraightLine(char x1, char y1, char x2, char y2);
bool isDiagonal(char x1, char y1, char x2, char y2);
bool isLShape(char x1, char y1, char x2, char y2);
bool isPawnMove(char x1, char y1, char x2, char y2, bool isBlk);
bool isKingMove(char x1, char y1, char x2, char y2);
bool isPawnAtk(bool color, char x1, char y1, char x2, char y2);
