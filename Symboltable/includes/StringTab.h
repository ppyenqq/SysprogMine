/*
 * StringTab.h
 *
 *  Created on: 06.11.2018
 *      Author: Didi
 */
#include "../includes/StringTabNode.h"
#ifndef STRINGTAB_H_
#define STRINGTAB_H_

class StringTab{
private:
	char* freeP;
	int freeSpace;
	StringTabNode* first;
	StringTabNode* currentNode;
public:
	StringTab();
	virtual ~StringTab();

	char* insert(char* lexem, int size);
	void printStringTable();

};



#endif /* STRINGTAB_H_ */
