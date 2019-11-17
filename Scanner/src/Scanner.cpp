#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../includes/String.h"//wenn man String.h benutzt bekommt man undefined reference,bitte beheben wenn Zeit zu verfügung steh
#include "../../Symboltable/includes/SymtabEntry.h"
#define BLANK ' '
#include <iostream>
#include <limits.h>

Scanner::Scanner(char* fileName) {
//	std::cout << "[SCANNER CONSTRUCTOR] : " << this << std::endl;

	this->automat = new Automat();
	this->buffer = new Buffer(fileName);
	this->symboltable = new Symboltable();
	fileEnded = false;

}

Scanner::~Scanner() {
	delete automat;
	delete buffer;
	delete symboltable;
}

Token* Scanner::getToken() {

	int line; //der hier ist fortlaufend, also "currentLine", während tokenLine die Start-Line/Column eines Token ist
	int column;
	int tokenLine;
	int tokenColumn;
	bool legal;

	String lexem("");
	int eyyy = lexem.length;
	TokenType lastValidTokenType;

	do {

		char c = buffer->getChar();
		line = buffer->getLine();
		column = buffer->getColumn();
		// check EOF
		if (c == '\0') {

			if (lexem.length > 0) {

				if (lastValidTokenType == ERROR) {

					return new Token(tokenLine, tokenColumn, lexem.get());

				} else if (lastValidTokenType == IDENTIFIER) {
					SymtabEntry* keyOne = symboltable->insert(lexem.get(),
							lastValidTokenType); //versuch lastValidTokenType mit automat->getTokenType zu wechseln, glaube mach keinen Unterschied
					Info* mainKey = symboltable->lookup(keyOne);
					return new Token(mainKey->getTokenType(), tokenLine,
							tokenColumn, mainKey);
				} else if (lastValidTokenType == INTEGER) {
//					int value = lexem.stringToInt();
					long value = strtol(lexem.get(), NULL, 10);
					if ((value == LONG_MIN || value == LONG_MAX)&& errno == ERANGE) {
						//Value out of range
						cout << "Inside Scanner: LONG_MIN OR LONG MAX DETECTED: " << value << endl;
						lastValidTokenType=ERROR;
						return new Token(tokenLine, tokenColumn,lexem.get());
					}else{
					return new Token(lastValidTokenType, tokenLine, tokenColumn,
							value);
					}
				} else {
					return new Token(lastValidTokenType, tokenLine, tokenColumn);
				}

			}
			fileEnded = true;
			return nullptr;

		}

		legal = automat->step(c);

		if (legal) {
			lexem += c;
			lastValidTokenType = automat->getTokenType();

			if (lexem.length == 1) {
				tokenLine = line;
				tokenColumn = column;
			}
		} else if (lexem.length > 0 ) { // sollte ich  lexem.length<1024 als grenze setzen??? es wird nie passieren aber wer weiß
			if (automat->getTokenType() == COMMENT_START) {

				// run to end of comment

				char lastChar = c;
				while (!(c == ':' && lastChar == '*') && c != '\0') {
					lastChar = c;
					c = buffer->getChar();
				}
				automat->reset();
				lexem.length = 0;
				legal = true;

			} else {


				Token* token;
				if (lastValidTokenType == ERROR) {

					token = new Token(tokenLine, tokenColumn, lexem.get());

				}else if(lastValidTokenType == ERROR_SIGN_COMPARE){
					buffer->ungetChar();
					token = new Token(SIGN_EQUALS, tokenLine,
												tokenColumn);

				}else if (lastValidTokenType == IDENTIFIER) {
					SymtabEntry* keyOne = symboltable->insert(lexem.get(),
							lastValidTokenType); //versuch lastValidTokenType mit automat->getTokenType zu wechseln, glaube mach keinen Unterschied
					Info* mainKey = symboltable->lookup(keyOne);
					token = new Token(mainKey->getTokenType(), tokenLine,
							tokenColumn, mainKey);
				} else if (lastValidTokenType == INTEGER) {
					//					int value = lexem.stringToInt();
										long value = strtol(lexem.get(), NULL, 10);
										if ((value == LONG_MIN || value == LONG_MAX)&& errno == ERANGE) {
											//Value out of range
											cout << "Inside Scanner: LONG_MIN OR LONG MAX DETECTED: " << value << endl;
											lastValidTokenType=ERROR;
											token= new Token(tokenLine, tokenColumn,lexem.get());
										}else{
										token= new Token(lastValidTokenType, tokenLine, tokenColumn,
												value);
										}
				} else {
					token = new Token(lastValidTokenType, tokenLine,
							tokenColumn);
				}

				automat->reset();
				buffer->ungetChar();
//				lexem -= lexem.length - 1;



				return token;
			}
		} else if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\a'
				|| c == '\b' || c == '\v' || c == '\f') {
			//cout << "Leerzeichnen oder  Steuerzeichen( wie newline oder Tab ) "<<endl;
			if (c == '\t') {
				column += 3;
			}
			automat->reset();
			legal = true;
		} else {
			automat->reset();

			return new Token(line, column, c);// hat das hie rnen Sinn??
		}

	} while (legal);

//	Token* token = new Token(lastValidTokenType, line, column);
//	automat->reset();
//	lexem -= lexem.length - 1;

	return nullptr;
}
// Probleme bei Funktion aufgetreten
Token* Scanner::saveToken(TokenType lastValidTokenType, String lexem,
		int tokenLine, int tokenColumn) {
	if (lastValidTokenType == ERROR) {

		return new Token(tokenLine, tokenColumn, lexem.get());

	} else if (lastValidTokenType == IDENTIFIER) {
		SymtabEntry* keyOne = symboltable->insert(lexem.get(),
				lastValidTokenType); //versuch lastValidTokenType mit automat->getTokenType zu wechseln, glaube mach keinen Unterschied
		Info* mainKey = symboltable->lookup(keyOne);
		return new Token(mainKey->getTokenType(), tokenLine, tokenColumn,
				mainKey);
	} else if (lastValidTokenType == INTEGER) {
		int value = lexem.stringToInt();
		return new Token(lastValidTokenType, tokenLine, tokenColumn, value);
	} else {
		return new Token(lastValidTokenType, tokenLine, tokenColumn);
	}
}

Symboltable* Scanner::getSymboltable() {

	return symboltable;
}

