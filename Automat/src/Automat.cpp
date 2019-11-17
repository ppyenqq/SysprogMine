#include "../includes/Automat.h"
#include <iostream>

Automat::Automat() {
	std::cout << "[AUTOMAT CONSTRUCTOR] : " << this << std::endl;

	for (int i = 0; i < STATE_COUNT; i++) {
		transitionTable[i] = new char[ASCII_COUNT];
	}

	for (int i = 0; i < STATE_COUNT; i++) {
		for (int j = 0; j < ASCII_COUNT; j++) {
			transitionTable[i][j] = -1;
		}
	}

	currentState = 0;

	transitionTable[0]['+'] = 1;
	transitionTable[0]['-'] = 2;
	transitionTable[0]['*'] = 3;
	transitionTable[10]['*'] = 12;
	transitionTable[0][':'] = 10;
	//transitionTable[3][':'] = 4;
	transitionTable[7][':'] = 8;
	transitionTable[0]['<'] = 5;
	transitionTable[0]['>'] = 6;
	transitionTable[0]['='] = 7;
	transitionTable[8]['='] = 9;
	transitionTable[10]['='] = 11;
	transitionTable[0]['!'] = 13;
	transitionTable[0]['&'] = 14;
	transitionTable[14]['&'] = 15;
	transitionTable[0][';'] = 16;
	transitionTable[0]['('] = 17;
	transitionTable[0][')'] = 18;
	transitionTable[0]['{'] = 19;
	transitionTable[0]['}'] = 20;
	transitionTable[0]['['] = 21;
	transitionTable[0][']'] = 22;
	transitionTable[0]['&'] = 14;
	// Digits
	for (int i = 48; i < 58; i++) {
		transitionTable[0][i] = 23;
		transitionTable[23][i] = 23;
		transitionTable[24][i] = 24;
	}
	// LETTERS
	for (int i = 65; i < 91; i++) {
		transitionTable[0][i] = 24;
		transitionTable[24][i] = 24;
	}
	// letters
	for (int i = 97; i < 123; i++) {
		transitionTable[0][i] = 24;
		transitionTable[24][i] = 24;
	}

	finalStates = new TokenType[STATE_COUNT];

	finalStates[1] = SIGN_PLUS;
	finalStates[2] = SIGN_MINUS;
	finalStates[3] = SIGN_STAR;
	finalStates[4] = COMMENT_END;
	finalStates[5] = SIGN_LESS;
	finalStates[6] = SIGN_GREATER;
	finalStates[7] = SIGN_EQUALS;
	finalStates[8] = ERROR_SIGN_COMPARE; //XXXXXXXX26.09XXXXX von Error zu Error_Sign_Equal
	finalStates[9] = SIGN_COMPARE;
	finalStates[10] = SIGN_COLON;
	finalStates[11] = SIGN_ASSIGN;
	finalStates[12] = COMMENT_START;
	finalStates[13] = SIGN_EXCLAMATION;
	finalStates[14] = ERROR;
	finalStates[15] = SIGN_AND;
	finalStates[16] = SIGN_SEMICOLON;
	finalStates[17] = SIGN_BRACKETOPEN;
	finalStates[18] = SIGN_BRACKETCLOSE;
	finalStates[19] = SIGN_BRACEOPEN;
	finalStates[20] = SIGN_BRACECLOSE;
	finalStates[21] = SIGN_SQUAREBRACKETOPEN;
	finalStates[22] = SIGN_SQUAREBRACKETCLOSE;
	finalStates[23] = INTEGER;
	finalStates[24] = IDENTIFIER;



}

Automat::~Automat() {
	std::cout << "[DESTRUCTOR Automat] : " << this << std::endl;
	for (int i = 0; i < STATE_COUNT; i++) {
		delete[] transitionTable[i];
	}
	delete[] finalStates;
}

bool Automat::step(char c) {
	//std::cout << "currentState: " << currentState << " c: " << c << " step to: " << (int)transitionTable[currentState][c];
	if (transitionTable[currentState][c] > -1) {
		//std::cout << "   ACCEPT" << std::endl;
		currentState = transitionTable[currentState][c];
		isFinal();
		return true;
	}
	//std::cerr << "   DECLINE" << std::endl;
	return false;
}

TokenType Automat::getTokenType() {
	//std::cout << "getTokenType : " << currentState << std::endl;
	if (currentState < 0 || currentState >= STATE_COUNT) {
		return ERROR;
	}
	else {
		return finalStates[currentState];
	}
}

void Automat::reset() {
	//std::cout << "reset" << std::endl << std::endl;
	currentState = 0;
}

bool Automat::isFinal() {
	bool isFinal = false;
	if (finalStates[currentState] != ERROR) {
		isFinal = true;
		//std::cout << "FINAL" << std::endl;
	}
	else {
		//std::cout << "NOT FINAL" << std::endl;
	}
	return isFinal;
}
