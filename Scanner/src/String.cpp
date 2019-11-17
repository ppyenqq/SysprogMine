#include "../../Scanner/includes/String.h"
#include <math.h>

#include <iostream>

int String::getLength(char* _str) {
	int _length = 0;
	for (int i = 0; _str[i]; i++) {
		_length++;
	}
	return _length;
}

String::String()
{
	str = "";
	length = 0;
}

String::String(char* _str) {
	length = getLength(_str);
	str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		str[i] = *_str;
		_str++;
	}
	str[length] = '\0';
}

String::String(char c) {
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
	length = 1;
}

String::~String()
{
	delete[] this->str;
}

std::ostream& operator<< (std::ostream& out, String& s) {
	out << s.str;
	return out;
}

char& String::operator[] (int index) {
	return str[index];
}

String& String::operator= (String &s) {
	length = s.length;

	char* newStr = new char[s.length + 1];

	for (int i = 0; i < length + 1; i++) {
		newStr[i] = s.str[i];
	}

	delete[] str;
	str = newStr;

	return *this;
}

String& String::operator+= (String &s) {
	int newLength = length + s.length;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < length; i++) {
		newStr[i] = str[i];
	}
	for (int i = 0; i < s.length; i++) {
		newStr[length + i] = s.str[i];
	}
	newStr[newLength] = '\0';

	delete[] str;
	str = newStr;
	length = newLength;

	return *this;
}

String& String::operator+= (char c) {
	int newLength = length + 1;
	char* newStr = new char[newLength + 1];
	for (int i = 0; i < length; i++) {
		newStr[i] = str[i];
	}
	newStr[newLength - 1] = c;
	newStr[newLength + 0] = '\0';
	delete[] str;
	str = newStr;
	length = newLength;

	return *this;
}

String& String::operator-= (int a) {
	int newLength = length - a;
	if (newLength < 0) newLength = 0;

	char* newStr = new char[newLength + 1];
	for (int i = 0; i < newLength; i++) {
		newStr[i] = str[i];
	}
	newStr[newLength] = '\0';
	delete[] str;
	str = newStr;
	length = newLength;

	return *this;
}

bool operator== (String &a, String &b) {
	if (a.length != b.length) return false;

	for (int i = 0; i <= a.length; i++) {
		if (a.str[i] != b.str[i]) return false;
	}

	return true;
}

void String::print() {
	std::cout << "[" << length << "] " << str << std::endl;
}

char* String::get() {
	char* cpy = new char[length + 1];
	for (int i = 0; i <= length; i++) {
		cpy[i] = str[i];
	}
	return cpy;
}
int String::stringToInt(){
	try{
		if(length==0){
			throw "String ist leer/Methode wird noch nachverbessert";
		}
	for(int j=0;j<length;j++){
		if(str[j]<'0'||str[j]>'9'){
			throw "String besteht nicht nur aus Zahlen// Methode wird noch nachverbessert";
			break;
		}
	}
	}catch(char const* ex){
		printf(ex);
	}

		int result=0;
		for(int i=0;i<length;i++){

			result+=(str[i]-48)*pow(10,(length-i-1));
		}
		return result;
}

char* String::strcpy(char* from) {
	int _length = getLength(from);
	char* to = new char[_length];
	for (int i = 0; i <= _length; i++) {
		to[i] = from[i];
	}
	return to;
}



