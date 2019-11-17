#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../includes/String.h"
#include <math.h>
#include <fstream>

#include <iostream>
#include <limits.h>
int main(int argc, char **argv) {


	 char *inFile = argv[1];
	const char *outFilename = argv[2];

	Scanner scanner (inFile);
	ofstream outFile;
		outFile.open(outFilename);

		Token* token = scanner.getToken();
		while (!scanner.hasFileEnded()) {

			if (token->geTokenType() == ERROR) {

//				 if(token->geTokenType()==ERROR){
//								    	if(token->getErrorSignSingle()){
//								    		cerr<<"Token: "<< token->tokenTypeToString()<<"  Line: "<< token->getLine()<<"  Column: "<<token->getColumn()<<"  Errorsign: "<<token->getErrorSignSingle()<<endl;
//
//								    	}else if(token->getErrorSign()){
//								    		cerr<<"Token: "<< token->tokenTypeToString()<<"  Line: "<< token->getLine()<<"  Column: "<<token->getColumn()<<"  Errorsign: "<<token->getErrorSign()<<endl;
//								    	}
//				}
				 cerr << token->tokenToString() << endl;

			} else {

				outFile << token->tokenToString() << endl;
//				if(token->geTokenType()==INTEGER){
//					outFile<<"Token: "<< token->tokenTypeToString()<<"  Line: "<< token->getLine()<<"  Column: "<<token->getColumn()<<"  Value: "<<token->getInformation()<<endl;
//
//
//				    }else if(token->geTokenType()==IDENTIFIER){
//				    	outFile<<"Token: "<< token->tokenTypeToString()<<"  Line: "<< token->getLine()<<"  Column: "<<token->getColumn()<<"  Key: "<<token->getKey()->getNamePtr()<<endl;
//
//
//
//				    }else {
//				    	outFile<<"Token: "<< token->tokenTypeToString()<<"  Line: "<< token->getLine()<<"  Column: "<<token->getColumn()<<endl;
//
//				    }

			}

			token = scanner.getToken();
		}
		outFile.close();


}

