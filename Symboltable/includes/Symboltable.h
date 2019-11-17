/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */
#include "../includes/SymtabEntry.h"
#include "../includes/Info.h"
#include "../includes/StringTab.h"
#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#define HASH_TABLE_SIZE 211
#define EOS '\0'

class Symboltable {
private:
	SymtabEntry* hashTable[HASH_TABLE_SIZE];
	void initSymbols();
	StringTab* stringTable;
	unsigned int hash(const char *lexem);
	void initializeHashTable();
public:
	Symboltable();
	virtual ~Symboltable();
	//unsigned int hash(const char *lexem);
	SymtabEntry* insert(char* lexem, TokenType tokenType);
	Info* lookup(SymtabEntry* key);
	StringTab* getStringTable();
	unsigned int calculateLexemSize(char* lexem);

};

#endif /* SYMBOLTABLE_H_ */
