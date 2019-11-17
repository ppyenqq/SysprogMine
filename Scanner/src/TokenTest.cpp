#include "../includes/Token.h"

#include <iostream>

//void printToken(Token* token) {
//	std::cout << "Token " << tokenNames[token->getType()] << " Line: " << token->getLine() << " Column: " << token->getColumn();
//	switch (token->getType())
//	{
//		break;
//	case INTEGER:
//		std::cout << " Value: " << token->getInformation();
//		break;
//	case IDENTIFIER:
//		std::cout << " Key: " << token->getInformation();
//		break;
//	case ERROR:
//		std::cout << " ErrorSign: " << token->getErrorSign();
//		break;
//	default:
//		break;
//	}
//	std::cout << std::endl;
//}

void testToken() {
	Token* token;
	token = new Token(INTEGER, 3, 1, 2);
	token->print();
	token = new Token(IDENTIFIER, 1, 1, 0x12);
	token->print();

}
