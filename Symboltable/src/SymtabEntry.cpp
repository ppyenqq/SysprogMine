/*
 * SymtabEntry.cpp
 *
 *  Created on: 07.11.2018
 *      Author: Didi
 */

#include "../includes/SymtabEntry.h"
#include <iostream>
using namespace std;

SymtabEntry::SymtabEntry() {
	//cout << "SymtabEntry()" << endl;
	nextSymtabEntry = nullptr;
	info = new Info();
}

SymtabEntry::~SymtabEntry() {
	//cout << "~SymtabEntry()" << endl;
}

/**
 * Setzt das naechste SymtabEntry.
 */
void SymtabEntry::setNextSymtabEntry(SymtabEntry* nextSymtabEntry){
	this->nextSymtabEntry = nextSymtabEntry;
}

/**
 * Gibt das naechste SymbtabEntry zurueck.
 */
SymtabEntry* SymtabEntry::getNextSymtabEntry(){
	return nextSymtabEntry;
}

/**
 * Gibt den Pointer auf das Info-Objekt zurueck.
 */
Info* SymtabEntry::getInfoPtr(){
	return info;
}




