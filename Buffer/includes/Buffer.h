/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */
#ifndef O_DIRECT
#define O_DIRECT 0
#endif
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#ifndef BUFFER_H_
#define BUFFER_H_
static const int buffsize=512;
using namespace std;


class Buffer {
public:
	Buffer(char *filename);
	virtual ~Buffer();
	char getChar();
//	void putChar(char c);
	void ungetChar();
	void ungetCharMulti(int num);
	int getLine();
	int getColumn();
	bool fileEnded();
bool eofReached;
private:
bool ungetCharBufEndCalled;
	void openFile();
//	void createFile();
	void fillBuffer();
	void addColumnLine();
	void reduceColumnLine();
	unsigned int bufferLength;
	char *leftBuffer;
	char *rightBuffer;
	const char *sourceFile;
	char *leftBufStart;
	char *rightBufStart;
//	char currentChar;
	char *current;
	char *next;
	char eof;

	bool leftBufActive;
	int bytesRead;
//	int byteLeft;
	int fRead;
	bool fileIsOpen;
	int line;
	int column;
	bool lineEndDetected;
	int prevColumn;//als hilfsvariable bei ungetchar




};

#endif /* BUFFER_H_ */
