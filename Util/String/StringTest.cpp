#include "../../Scanner/includes/String.h"

#include <iostream>

void testString() {
	String a("Awesome string class!");
	a.print();
	std::cout << a << std::endl;
	std::cout << a[1] << std::endl;
	String b('b');
	b.print();
	b = a;
	b.print();
	a += b;
	a.print();

	a += '_';
	a.print();
	a -= 3;
	a.print();

	String s1("abc");
	String s2("Wort2");
	char* c1 = s1.get();
	char* c2 = s2.get();
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	c2 = String::strcpy(c1);
	std::cout << c2 << std::endl;

	// bool comp1 = String("abc") == String("abC");
	// bool comp2 = String("equal") == String("equal");
	// std::cout << comp1 << std::endl;
	// std::cout << comp2 << std::endl;

	// std::cin.get();
}


