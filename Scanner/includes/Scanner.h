#ifndef SCANNER_H_
#define SCANNER_H_

#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"
#include "Token.h"

class Scanner {
private:
	Automat* automat;
	Buffer* buffer;
	Symboltable* symboltable;
	bool fileEnded;


	Token* saveToken(TokenType lastValidTokenType,String lexem,int tokenLine, int tokenColumn);
public:
	Scanner(char* fileName);
	virtual ~Scanner();

	Token* getToken();
	bool hasFileEnded(){
		return fileEnded;
	}
	Symboltable* getSymboltable();

};

#endif /* SCANNER_H_ */
