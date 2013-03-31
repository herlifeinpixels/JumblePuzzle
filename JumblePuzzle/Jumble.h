// Jumble.h
 
#include "stdafx.h"
#include <iostream>
using namespace std;
typedef char* charArrayPtr;
 
class BadJumbleException {
  public:
		BadJumbleException(const string&);
		string& what();
	private:
		string message;
};
 
class JumblePuzzle {
	public:
		JumblePuzzle(const string&, const string&); // Constructor
		JumblePuzzle(const JumblePuzzle&);			// Copy Constructor
		~JumblePuzzle();							// Destructor
		charArrayPtr* getJumble();
		int getSize();
		int getRowPos();
		int getColPos();
		char getDirection();
	private:
		charArrayPtr* createMatrix(const int&);
		string hiddenword;
		string difficulty;
		int len;
		charArrayPtr* matrix;
};