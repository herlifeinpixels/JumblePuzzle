/ JumblePuzzle
#include "stdafx.h"
#include <iostream>
#include <sstream>  	// Only used by conversion constructor
#include "Jumble.h"
using namespace std;
 
// Exception thrown if attempt is made to go out of bounds on the buffer
BadJumbleException::BadJumbleException (const string& m) : message(m) {}
string& BadJumbleException::what() { return message; }
 
// Default constructor
JumblePuzzle::JumblePuzzle(const string& word, const string& dif) {
	hiddenword = word;
	difficulty = dif;
	// Get h x w of matrix
	if (dif == "easy") { 
		len = hiddenword.length() * 2;
	} else if (dif == "medium") {
		len = hiddenword.length() * 3;
	} else if (dif == "hard") {
		len = hiddenword.length() * 4;
	} else {
		throw BadJumbleException("No such level of difficulty.");
	}

	charArrayPtr* matrix = createMatrix(len);		// Using heap
}

// Matrix genreator, returns an array of array pointers
charArrayPtr* JumblePuzzle::createMatrix(const int& len) {
	charArrayPtr* ary = new char*[len];
	for(int i = 0; i < len; i++) {
		ary[i] = new char[len];
	}
	return ary;
}

// Copy Constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& other) {
	
}

// Destructor
JumblePuzzle::~JumblePuzzle() {
	
	delete[] matrix;
}