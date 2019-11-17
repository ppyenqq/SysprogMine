#pragma once

#include <iostream>
//#using namespace std;

class String
{
private:
	char* str;
public:
	static int getLength(char* _str);
	int length;
	 long numberValue=NULL;
	String();
	String(char* _str);
	String(char c);
	~String();
	friend std::ostream& operator<< (std::ostream &out, String &s);
	char& operator[] (int index);
	String& operator= (String &s);
	String& operator+= (String &s);
	String& operator+= (char c);
	String& operator-= (int a);
	friend bool operator== (String &a, String &b);
	int stringToInt();
	void print();

	char* get();
	static char* strcpy(char* from);

};
