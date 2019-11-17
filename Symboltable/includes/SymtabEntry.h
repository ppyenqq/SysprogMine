/*
 * SymtabEntry.h
 *
 *  Created on: 07.11.2018
 *      Author: Didi
 */
#include "../includes/Info.h"
#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

class SymtabEntry {
private:
	SymtabEntry* nextSymtabEntry;
	Info* info;
public:
	SymtabEntry();
	virtual ~SymtabEntry();
	void setNextSymtabEntry(SymtabEntry* nextSymtabEntry);
	SymtabEntry* getNextSymtabEntry();
	Info* getInfoPtr();
};

#endif /* SYMTABENTRY_H_ */
