#include "../includes/Token.h"


#include <iostream>
using namespace std;

Token::Token(TokenType type, int line, int column) {
	mType = type;
	mLine = line;
	mColumn = column;
}

Token::Token(TokenType type, int line, int column, long information) {
	mType = type;
	mLine = line;
	mColumn = column;
	mInformation = information;
}
//Token::Token(TokenType type, int line, int column, SymtabEntry* key) {
//	mType = type;
//	mLine = line;
//	mColumn = column;
//	mKey = key;
//}
//Statt Symbolentry als Key zu benutzen wurde jz Info als Key eingesetz, falls nicht erlaubt verwenden wir wieder Symtabentry
Token::Token(TokenType type, int line, int column, Info* key) {
	mType = type;
	mLine = line;
	mColumn = column;
	mKey = key;
}

Token::Token(int line, int column, char* errorSign) {
	mType = ERROR;
	mLine = line;
	mColumn = column;
	mErrorSign = errorSign;
}
Token::Token(int line, int column, char errorSignSingle) {
	mType = ERROR;
	mLine = line;
	mColumn = column;
	mErrorSignSingle = errorSignSingle;

}
//Token::Token(int line, int column, String* errorSign) {
//	mType = ERROR;
//	mLine = line;
//	mColumn = column;
//	mErrorSign = errorSign;
//}
void Token::print() {

	cout << "Token " << tokenTypeToString() << " Line: " << mLine << " Column: " << mColumn;

	switch (mType)
	{
		break;
	case INTEGER:
		cout << " Value: " << mInformation;
		break;
	case IDENTIFIER:

		cout << " Key: " << mKey->getNamePtr();
		break;
	case ERROR:
		if(mErrorSignSingle){


		cout << " ErrorSign: " << mErrorSignSingle;
		}else if(mErrorSign){
			cout << " ErrorSign: " << mErrorSign;
		}
		break;
	default:
		break;
	}
	std::cout << std::endl;
}
const char *Token::tokenToString() {
	int space=0;
    char *buffer = (char *) calloc(256, sizeof(char)); // wieso kann ich die anzahl (vor sizeof) beliebig wählen und es gibt trotzdem ganze länge raus;mitom123

    if(mType==INTEGER){
    	space=snprintf(buffer, 256, "Token %-20s Line: %5d  Column: %3d  Value: %ld", tokenTypeToString(), mLine, mColumn, mInformation);

    }else if(mType==IDENTIFIER){
    	space=snprintf(buffer, 256, "Token %-20s Line: %5d  Column: %3d  Key: %3s", tokenTypeToString(), mLine, mColumn, mKey->getNamePtr());

    }else if(mType==ERROR){
    	if(mErrorSignSingle){
    		space=snprintf(buffer, 256, "Unknown Token %-20s Line: %5d  Column: %3d  ErrorSign: %5c", tokenTypeToString(), mLine, mColumn, mErrorSignSingle);
    	}else if(mErrorSign){
    		space=snprintf(buffer, 256, "Unknown Token %-20s Line: %5d  Column: %3d  ErrorSign: %5s", tokenTypeToString(), mLine, mColumn, mErrorSign);
    	}
    }else {
    	space=snprintf(buffer, 256, "Token %-20s Line: %5d  Column: %3d", tokenTypeToString(), mLine, mColumn);

    }
if(space>256){
    cerr<<"Das Token: "<<tokenTypeToString()<<"  in Zeile "<<mLine<<"  und Spalte : "<<mColumn<<"  ist zu lang und wird daher nicht vollständig gezeigt, bitte kürzen, wenn möglich"<<endl;
}
    return buffer;
}
const char* Token::tokenTypeToString(){
	switch(mType){
	case start: return "start";
	case SIGN_PLUS: return "SIGN_PLUS";
	case SIGN_MINUS: return "SIGN_MINUS";
	case SIGN_COLON: return "SIGN_COLON";
	case SIGN_STAR: return "SIGN_STAR";
	case SIGN_LESS: return "SIGN_LESS";
	case SIGN_GREATER: return "SIGN_GREATER";
	case SIGN_EQUALS: return "SIGN_EQUALS";
	case SIGN_ASSIGN: return "SIGN_ASSIGN";
	case SIGN_EQUALS_COLON_EQUALS: return "SIGN_EQUALS_COLON_EQUALS";
	case SIGN_EXCLAMATION: return "SIGN_EXCLAMATION";
	case SIGN_AND: return "SIGN_AND";
	case SIGN_SEMICOLON: return "SIGN_SEMICOLON";
	case SIGN_BRACKETOPEN: return "SIGN_BRACKETOPEN";
	case SIGN_BRACKETCLOSE: return "SIGN_BRACKETCLOSE";
	case SIGN_BRACEOPEN: return "SIGN_BRACEOPEN";
	case SIGN_BRACECLOSE: return "SIGN_BRACECLOSE";
	case SIGN_SQUAREBRACKETOPEN: return "SIGN_SQUAREBRACKETOPEN";
	case SIGN_SQUAREBRACKETCLOSE: return "SIGN_SQUAREBRACKETCLOSE";
	case SIGN_ERROR: return "SIGN_ERROR";
	case SIGN_COMPARE: return "SIGN_COMPARE";
	case COMMENT_START: return "COMMENT_START";
	case COMMENT_END: return "COMMENT_END";
	case ERROR: return "ERROR";
	case INTEGER: return "INTEGER";
	case IDENTIFIER: return "IDENTIFIER";
	case KEYWORD_WRITE: return "KEYWORD_WRITE";
	case KEYWORD_READ: return "KEYWORD_READ";
	case KEYWORD_IF: return "KEYWORD_IF";
	case KEYWORD_ELSE: return "KEYWORD_ELSE";
	case KEYWORD_WHILE: return "KEYWORD_WHILE";
	case KEYWORD_INT: return "KEYWORD_INT";
	default: return"Unknown Type in Method TokenTypeToString";
	}

}
