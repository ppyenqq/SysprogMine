#include <iostream>
using namespace std;
#include "../includes/Automat.h"

int main() {

	Automat* automat = new Automat();

	automat->step(':');
	automat->step('=');
	automat->getTokenType();
	automat->reset();

	automat->step('a');
	automat->step('0');
	automat->step('Z');
	automat->getTokenType();
	automat->reset();

	automat->step('=');
	automat->getTokenType();
	automat->step(':');
	automat->getTokenType();
	automat->step('=');
	automat->getTokenType();
	automat->reset();

	automat->step('&');
	automat->step('b');
	automat->step('&');
	automat->reset();

	automat->step('i');
	automat->step(' ');
	automat->step('F');
	automat->getTokenType();


	delete automat;
	cout << "Test" << endl;
	std::cin.get();

	return 0;
}
