#include <iostream>
#include "Nazo.h"

using namespace std;

int main(void ){
	Nazo foo;
	foo.height = 13.5;
	foo.age = 5;
	foo.alive = true;

	cout << "foo: " << endl;
	cout << "  height: " << foo.height << endl;
	cout << "  age: " << foo.age << endl;

	foo.sayHi();
	cout << endl;

	foo.age = 9;
	foo.alive = false;
	cout << "foo: " << endl;
	cout << "  height: " << foo.height << endl;
	cout << "  age: " << foo.age << endl;
	
	foo.sayHi();
	cout << endl;

	return 0;
}