/*
 * Info.h
 *
 *  Created on: 06.12.2018
 *      Author: jack
 */
#include "../../Scanner/includes/String.h"
#include "../../Scanner/includes/TokenType.h"
#ifndef SYMBOLTABLE_INCLUDES_INFO_H_
#define SYMBOLTABLE_INCLUDES_INFO_H_

class Info{

private:
	char* name;
	TokenType mTokenType;

public:
	Info();
	virtual ~Info();
	char* getNamePtr();
	void setNamePtr(char* namePtr);
	bool compareLex(char* lexem);
	void setTokenType(TokenType tokenType);
	TokenType getTokenType();

};



#endif /* SYMBOLTABLE_INCLUDES_INFO_H_ */
