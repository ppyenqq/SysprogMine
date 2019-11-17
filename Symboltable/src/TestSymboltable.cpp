#include "../includes/Symboltable.h"
#include "../includes/StringTab.h"
#include "../includes/StringTabNode.h"
#include "../includes/SymtabEntry.h"
#include "../includes/Info.h"
#include <iostream>
using namespace std;


int main(int argc, char **argv) {

	cout << "**********************Initialisierung ***" << endl;

	Symboltable* symboltable;
	symboltable = new Symboltable();

	StringTab* stringTab;
	stringTab = new StringTab();

	StringTabNode* stringTabNode;
	stringTabNode = new StringTabNode();

	SymtabEntry* symtabEntry;
	symtabEntry = new SymtabEntry();

	cout << "*********************Ende der Initialisierung ***" << endl;
	cout << endl;

	cout << "************************************************" << endl;
	cout << "*********************SPIELWIESE*****************" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	cout << "************************************************" << endl;
	cout << "**************Test von printStringTable()*******" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	stringTab->printStringTable();
	stringTab->insert("123", 3);
	stringTab->printStringTable();
	stringTab->insert("4", 1);
	stringTab->printStringTable();
	stringTab->insert("wel", 3);
	stringTab->printStringTable();
	stringTab->insert("worl", 4);
	stringTab->printStringTable();
	stringTab->insert("momo", 4);
	stringTab->printStringTable();
	stringTab->insert("lalelu", 6);
	stringTab->printStringTable();
	stringTab->insert("lalelu", 6);
	stringTab->printStringTable();
	stringTab->insert("lalelu", 6);
	stringTab->printStringTable();

	/* hash()-Methode private, zum Testen public machen
	cout << "************************************************" << endl;
	cout << "**************Test von hash()*******" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	cout << symboltable->hash("lalellu") << endl;
	cout << symboltable->hash("TestWeltHallo") << endl;
	cout << symboltable->hash("pj") << endl;
	cout << symboltable->hash("tisch") << endl;
	cout << symboltable->hash("lalellu") << endl;
	cout << symboltable->hash("TestWeltHallo") << endl;
	cout << symboltable->hash("pj") << endl;
	*/

	cout << "************************************************" << endl;
	cout << "**************Test von compareLexem()***********" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	Info* infoCompare = new Info();
	infoCompare->setNamePtr("Hallo");
	cout << "Sind Hallo und miep gleich?:" << infoCompare->compareLex("mip")<< endl;
	cout << "Sind Hallo und Hallo gleich?:" << infoCompare->compareLex("Hallo")<< endl;


	cout << "************************************************" << endl;
	cout << "******Test von insert() der Stringtabelle*******" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	cout << "Einfügen von lalala zum ersten Mal:"<< endl;
	cout << symboltable->insert("lalala", ERROR) << endl;
	symboltable->getStringTable()->printStringTable();
	cout << endl;

	cout << "Einfügen von lalala zum zweiten Mal:"<< endl;
	cout << symboltable->insert("lalala", ERROR) << endl;
	symboltable->getStringTable()->printStringTable();

	symboltable->insert("haus", ERROR);

	cout << "Elnfügen von Maus:"<< endl;
	cout << symboltable->insert("Maus", ERROR) << endl;

	symboltable->getStringTable()->printStringTable();

	cout << "************************************************" << endl;
	cout << "************Test von calculateLexemSize()*******" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	unsigned int haus = symboltable->calculateLexemSize("Haus");
	cout << "Haus hat die Größe: " << haus << endl;

	unsigned int HausVomNikolaus = symboltable->calculateLexemSize("HausVomNikolaus");
	cout << "HausVomNikolaus hat die Größe: " << HausVomNikolaus << endl;


	cout << "************************************************" << endl;
	cout << "**************Test von lookup()*****************" << endl;
	cout << "************************************************" << endl;
	cout << endl;

	SymtabEntry* symtabEntryMaus = symboltable->insert("maus", ERROR);
	symboltable->getStringTable()->printStringTable();
	Info* infoMaus = symboltable->lookup(symtabEntryMaus);
	cout << infoMaus->getNamePtr() << endl;

	SymtabEntry* symtabEntryGarten = symboltable->insert("Garten", ERROR);
	Info* infoGarten = symboltable->lookup(symtabEntryGarten);
	cout << infoGarten->getNamePtr() << endl;

	SymtabEntry* symtabEntryMusik = symboltable->insert("musika", ERROR);
	Info* infoMusik = symboltable->lookup(symtabEntryMusik);
	cout << infoMusik->getNamePtr() << endl;

	symboltable->getStringTable()-> printStringTable();

}
