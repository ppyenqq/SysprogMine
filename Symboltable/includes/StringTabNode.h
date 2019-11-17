/*
 * StringTabNode.h
 *
 *  Created on: 06.11.2018
 *      Author: Didi
 */

#ifndef STRINGTABNODE_H_
#define STRINGTABNODE_H_
#define STRING_TAB_NODE_SIZE 10000
//#define STRING_TAB_NODE_SIZE 10  <- nur zum Testen :)

class StringTabNode{

private:
	char vector[STRING_TAB_NODE_SIZE];
	StringTabNode* next;
	void clearNode();

public:
	StringTabNode();
	virtual ~StringTabNode();
	void printNode();
	char* getVectorPtr(int i);
	char getVector(int i);
	void setNextNode(StringTabNode* node);
	StringTabNode* getNextNode();
	int getVectorSize();

};

#endif /* STRINGTABNODE_H_ */
