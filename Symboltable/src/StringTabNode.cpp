/*
 * StringTabNode.cpp
 *
 *  Created on: 06.11.2018
 *      Author: Jack
 */
#include "../includes/StringTabNode.h"
#include <iostream>

using namespace std;

StringTabNode::StringTabNode() {
	//cout << "StringTabNode()" << endl;
	clearNode(); //sets the storage which has been allocated to '0'
	next = 0; // next zeigt zu Beginn auf keinen folgenden Knoten; nullptr nicht 'erlaut'
}

StringTabNode::~StringTabNode() {
	//cout << "~StringTabNode()" << endl;
}

/**
 * Gibt einen einzelnen Knoten aus.
 */
void StringTabNode::printNode(){
	cout << "|";
	for(unsigned int i = 0; i < sizeof(vector); i++){
		if (vector[i] == '\0'){
			cout << "*" ;
		}
		else cout << vector[i];
	}
	cout << "|" << endl;
}

/**
 * Setzt die Werte im vector[] auf 0.
 */
void StringTabNode::clearNode(){
	for(unsigned int i = 0; i < sizeof(vector); i++){
		vector[i] = '0';
	}
}

/**
 * Gibt den Pointer von vector[i] zurueck
 */
char* StringTabNode::getVectorPtr(int i){
	return &vector[i];
}

/**
 * Setzt den naechsten Knoten, der mit den naechsten Lexem gefuellt wird.
 */
void StringTabNode::setNextNode(StringTabNode* node){
	this->next = node;
}

/**
 * Gibt die Groesse des vector[]-Array zurueck.
 */
int StringTabNode::getVectorSize(){
	return STRING_TAB_NODE_SIZE;
}

/**
 * Gibt den char i aus dem vector[i] zurueck.
 */
char StringTabNode::getVector(int i){
	return vector[i];
}

/**
 * Gibt den naechsten Knoten zurueck.
 */
StringTabNode* StringTabNode::getNextNode(){
	return next;
}



