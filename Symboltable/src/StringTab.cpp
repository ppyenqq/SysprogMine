/*
 * StringTab.cpp
 *
 *  Created on: 06.11.2018
 *      Author: Didi
 */
#include "../includes/StringTab.h"
#include <iostream>
#include <cstring>
using namespace std;

StringTab::StringTab() {
	//cout << "StringTab()" << endl;

	// first initialisieren
	this->first = new StringTabNode();

	// zeige auf das aktuelle Objekt
	this->currentNode = first;

	// freeSpace initialisieren
	//this->freeSpace = sizeof(first);
	freeSpace = first->getVectorSize();

	// freeP initialisieren
	this->freeP = first->getVectorPtr(0);
}

StringTab::~StringTab() {
	//cout << "~StringTab()" << endl;
}

/**
 * Fuegt ein Lexem in die Stringtabelle ein.
 * (!) Es gibt noch eine insert()-Methode in der Symboltabellen-Klasse.(!)
 */
char* StringTab::insert(char* lexem, int size) {
	//cout << "0 insert(lexem, size) " << endl;

	// tmp enthaelt den Zeiger auf das Lexem, das neu eingefeugt
	char* tmp = this->freeP;

	if (size < this->freeSpace) { // if the lexem fits into the current StringTabNode
		//cout << "1a insert(lexem, size): Lexem passt in den aktuellen Knoten " << endl;
		memcpy(this->freeP, lexem, size + 1);  // copy it into the StringTabNode
		this->freeP[size] = '\0';  // mark the end of the lexem with null
		this->freeP += size + 1;  // move pointer to the next free position
		this->freeSpace -= size + 1;  // adapt latest space which is left in the StringTabNode
	} else {
		//cout << "1b insert(lexem, size): Lexem wird in einem neuen Knoten gespeichert." << endl;

		//cout << "Aktueller Inhalt der Stringtabelle" << endl;
		//cout << "currentNode: ";currentNode->printNode();
		//cout << "first      : ";first->printNode();
		// << endl;

		StringTabNode* nextFollowingNode = new StringTabNode();  // erzeuge einen neuen Knoten
		//cout << "2 insert(lexem, size): Der naechstfolgende Knoten wurde erstellt." << endl;
		//cout << "currentNode: ";currentNode->printNode();
		//cout << "first      : ";first->printNode();
		//cout << endl;

		StringTabNode* tmpNode = currentNode;
		//cout << "3 insert(lexem, size): Ein temporaerer Knoten wurde erstellt." << endl;
		//cout << "currentNode: ";currentNode->printNode();
		//cout << "first      : ";first->printNode();
		//cout << "tmpNode    : ";tmpNode->printNode();
		//cout << endl;

		currentNode = nullptr;
		//cout << "4 insert(lexem, size): Der Zeiger currentNode wurde mit nullptr deklariert." << endl;
		//cout << "first      : ";first->printNode();
		//cout << endl;

		tmpNode->setNextNode(nextFollowingNode);  // der Pointer 'next' vom vorherigen Knoten, muss auf das neue Objekt zeigen
		//cout << "5 insert(lexem, size): Für tmpNode wurde nextFollowingNode als nächster Node gesetzt." << endl;
		//cout << "first      : ";first->printNode();
		//cout << endl;

		currentNode = nextFollowingNode;
		//cout << "6 insert(lexem, size): currentNode wurde dem nextFollowingNode zugewiesen." << endl;
		//cout << "currentNode: ";currentNode->printNode();
		//cout << "first      : ";first->printNode();
		//cout << endl;

		freeSpace = first->getVectorSize();
		//cout << "7 insert(lexem, size): Der freie Speicher wird wieder auf den Anfangswert gesetzt:" << freeSpace << endl;
		//cout << "first      : ";first->printNode();
		//cout << endl;

		this->freeP = currentNode->getVectorPtr(0);
		//cout << "8 insert(lexem, size): Der Zeiger freeP zeigt wieder auf den Anfang des naechsten Knotens." << endl;
		//cout << "first      : ";first->printNode();
		//cout << endl;

		tmp = this->freeP;
		//cout << "9 insert(lexem, size): Der Rückgabezeiger tmp erhaelt den Wert von freeP." << endl;
		//cout << "first      : ";first->printNode();
		//cout << endl;

		// copied from if-branch
		memcpy(this->freeP, lexem, size + 1);  // copy it into the StringTabNode
		this->freeP[size] = '\0';  // mark the end of the lexem with null
		this->freeP += size + 1;  // move pointer to the next free position
		this->freeSpace -= size + 1;
	}
	return tmp;
}

/**
 * Gibt die komplette Stringtabelle aus.
 */
void StringTab::printStringTable(){
	cout << "Aktueller Inhalt der Stringtabelle:" << endl;
	first->printNode();
	StringTabNode* nextNodeToPrint = first->getNextNode();
	while (nextNodeToPrint != nullptr){
		nextNodeToPrint -> printNode(); // gibt den naechsten Knoten aus
	    StringTabNode* tmp = nextNodeToPrint->getNextNode();  // hole den darauf folgenden Knoten
		cout.flush(); // leere vorsichtshalber den Buffer
		nextNodeToPrint = nullptr;  // setze den Zeiger auf null (vorsichtshalber)
		nextNodeToPrint = tmp;  // weise dem Zeiger den darauf folgenden Node zu
	}
	cout << endl;
}
