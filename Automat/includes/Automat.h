#pragma once
#include "../../Scanner/includes/Token.h"

class Automat {
private:
	const int STATE_COUNT = 25;
	const int ASCII_COUNT = 128;
	int currentState;
	TokenType* finalStates = new TokenType[25];
	char** transitionTable = new char*[STATE_COUNT];
public:
	Automat();
	virtual ~Automat();

	bool step(char c);

	TokenType getTokenType();

	void reset();

	int getCurrentState();

	bool isFinal();
};
