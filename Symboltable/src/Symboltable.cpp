/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Symboltable.h"
#include <iostream>
using namespace std;

Symboltable::Symboltable() {
	//cout << "Symboltable()" << endl;
	stringTable = new StringTab();
	initializeHashTable();
	initSymbols();

}

Symboltable::~Symboltable() {
	//cout << "~Symboltable()" << endl;
}

/**
 * Initialisiert die Symboltabelle mit den Schluesselwoertern.
 */
void Symboltable::initSymbols(){
	insert("while", KEYWORD_WHILE);
	insert("WHILE",KEYWORD_WHILE);
	insert("if",KEYWORD_IF);
	insert("IF",KEYWORD_IF);
}

/**
 *  Die Hash-Funktion nennt sich hashpjw() von P.J. Weinbergers C-Compiler
 *  siehe Seite 534 aus "Compilerbau Teil1" (Ullmann)
 *  Funktionsweise:
 *  1."fuer jedes Zeichen werden die Bits von h vier Positionen nach
	   links geschoben und zu dem Lexem addiert"
 *  2."falls einer der vier hoechstwertigen Bits von h gleich 1 ist,"
 *  3."werden diese vier Bits um 24 Positionen nach rechts rotiert
	   und durch xor mit h verbunden"
	4. "anschließend werden die vier heochstwertigen Bits auf Null gesetzt"
 */
unsigned int Symboltable::hash(const char *lexem){
	const char* p;
	unsigned h = 0, g;
	for(p = lexem; *p != EOS; p = p + 1){
		h = (h << 4) + (*p); 		// 1.
		if ((g = h) & 0xf00000){    // 2.
			h = h ^ (g >> 24);      // 3.
			h = h ^ g;			    // 4.
		}
	}
	return h % HASH_TABLE_SIZE;
}

/**
 * Fuegt das Lexem in die Symboltabelle ein.
 * (!) Es gibt noch eine insert()-Methode in der StringTab-Klasse.
 * Diese fuegt jediglich das Lexem in die Stringtabelle ein.(!)
 */
SymtabEntry* Symboltable::insert(char* lexem, TokenType tokenType){
	//cout << "0 insert(lexem): Die Methode insert() wurde aufgerufen: " << endl;

	// Hash-methode aufrufen
	int indexInHashtable = hash(lexem);
	//cout << "1 insert(lexem): Die Hash-Methode wurde aufgerufen." << endl;

	// ein temporaeres SymtabEntry wird zum Iterieren erzeugt
	SymtabEntry* tmp = hashTable[indexInHashtable];
	SymtabEntry* lastSymtabEntry = new SymtabEntry();
	lastSymtabEntry = tmp;
	//cout << "2 insert(lexem): Ein temporaeres SymtabEntry-Objekt wird zum Iterieren erzeugt" << endl;
	//cout << tmp << endl;
	//cout << hashTable[indexInHashtable] << endl;

	// falls das aktuelle SymtabEntry auf ein Objekt zeigt
	while (tmp != nullptr){
		//cout << "3 insert(lexem): Eintreten der while-Schleife, "
		//	"falls das aktuelle SymtabEntry auf ein Objekt zeigt" << endl;

		// Uberpruefe, ob das aktuelle Lexem bereits gespeichert ist
		Info* infoPointer = tmp->getInfoPtr();
		bool result = infoPointer->compareLex(lexem);
		//if (tmp->getInfoPtr()->compareLex(lexem)){  // diese Zeile liefert false(?) -> nicht benutzen
		if (result){
			//cout << "3a insert(lexem): Lexem bereits in der Stringtabelle vorhanden :)" << endl;
			// falls ja, gib den aktuelle SymtabEntry-Zeiger zurueck
			return tmp;
		} else{
			// falls nein, weiter gehts
			lastSymtabEntry = tmp;
			tmp = tmp->getNextSymtabEntry();
			//cout << "3b insert(lexem): Lexem nicht in der Stringtabelle vorhanden" << endl;
		}
	}
	// ein neuer Eintrag wird erzeugt
	SymtabEntry* newEntry = new SymtabEntry;
	newEntry->getInfoPtr()->setTokenType(tokenType); // setzt den TokenTyp
	//cout << "4 insert(lexem): ein neuer Eintrag wird erzeugt" << endl;
	//cout << endl;

	// die Groesse des Lexems wird bestimmt
	int sizeLexem = calculateLexemSize(lexem);
	//cout << "5 insert(lexem): die Groesse des Lexems wird bestimmt:" << lexem << sizeLexem<< endl;
	//cout << endl;

	// in die StringTabelle wird das lexem eingefuegt und der Pointer zurueckgegeben
	char* pointerToLexem = stringTable->insert(lexem, sizeLexem);
	//cout << "6 insert(lexem): in die StringTabelle wird das lexem eingefuegt und der Pointer zurueckgegeben" << endl;
	//cout << endl;

	// falls der erste Eintrag noch nicht existiert
	if(lastSymtabEntry == nullptr){
		//cout << "7a insert(lexem): neuer Eintrag in der Symboltabelle" << endl;
			hashTable[indexInHashtable] = newEntry;  // fuege den ersten hinzu
			newEntry->getInfoPtr()->setNamePtr(pointerToLexem);  // setze den Lexempointer

			return newEntry;
	}else{
		//cout << "7b insert(lexem): erster Eintrag in der Hashtabelle schon belegt" << endl;

		// man holt sich das Info-Objekt aus dem aktuellen SymtabEntry-Objekt
		Info* info = newEntry->getInfoPtr();
		//cout << "8 insert(lexem): man holt sich das Info-Objekt "
		//"aus dem aktuellen SymtabEntry-Objekt" << endl;
			//cout << endl;

		// im info-Objekt wird der obige Zeiger, der auf das Lexem in der Stringtabelle zeigt, hinterlegt
		info->setNamePtr(pointerToLexem);
		//cout << "8 insert(lexem): im info-Objekt wird der obige Zeiger, der auf das Lexem zeigt, hinterlegt" << endl;

		// den neu erzeugten SymtabEntry in die Liste anhaengen
		lastSymtabEntry->setNextSymtabEntry(newEntry);
		//cout << "9 insert(lexem): den neu erzeugten SymtabEntry in die Liste anhaengen" << endl;

		return newEntry;
	}

}

/**
 * Gibt fuer einen SymtabEntry* key den entsprechenden Zeiger, auf
 * das Info-Objekt zurueck.
 */
Info* Symboltable::lookup(SymtabEntry* key){
	return key->getInfoPtr();
}

/**
 * Initialisiert die Hashtabelle mit nullptr.
 */
void Symboltable::initializeHashTable(){
	for (int i = 0; i < HASH_TABLE_SIZE; i++){
		hashTable[i] = nullptr;
	}
}

/**
 * Gibt die Stringtabelle zurueck.
 */
StringTab* Symboltable::getStringTable(){
	return stringTable;
}

/**
 * Berechnet die Groesse des Lexems.
 */
unsigned int Symboltable::calculateLexemSize(char* lexem){
	unsigned int summe = 0;
	for (int i = 0; lexem[i] != '\0'; i++){
		summe = summe + 1;
	}
	return summe;
}

