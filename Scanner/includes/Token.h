#pragma once

#include "../../Symboltable/includes/Info.h"
#include "String.h"
#include "TokenType.h"

class Token
{
private:
	TokenType mType;
	int mLine, mColumn;
	long mInformation;// vom int zu long verändert
	char* mErrorSign;
	char mErrorSignSingle;
	Info* mKey;

public:
	Token(TokenType type, int line, int column);
	Token(TokenType type, int line, int column, long information);// vom int zu long verändert
	Token(TokenType type, int line, int column, Info* key);
void print();
	Token(int line, int column, char* errorSign);
	Token(int line, int column, char errorSignSingle);
	~Token();
const char* tokenTypeToString();

	const char* tokenToString();

	TokenType geTokenType() {
		return mType;
	}
	int getLine() {
		return mLine;
	}
	int getColumn() {
		return mColumn;
	}
	Info* getKey() {
		return mKey;
	}
	long getInformation() { // vom int zu long verändert
		return mInformation;
	}
	char* getErrorSign() {
		return mErrorSign;
	}
	char getErrorSignSingle() {
			return mErrorSignSingle;
		}
};
