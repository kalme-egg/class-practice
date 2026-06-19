function trigger(){
addFile("Nazo.h",`
#ifndef _NAZO_H_
#define _NAZO_H_

class Nazo {
public:
	float height;
	int age;
	bool alive;

	void sayHi(void );
};

#endif /* _NAZO_H_ */`)
addFile("Nazo.cpp",`
// ここは変えなくて良さそうなのだ！
#include "Nazo.h"
#include <iostream>

using namespace std;

void Nazo::sayHi(void )
{
	cout << "Hi!" << endl;
	return;
}`)
deleteFile(0,{stopPropagation(){}})
addFile("main.cpp",`
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
	cout << "  birthday: " << foo.birthMonth << "/" << foo.birthDay << endl; // 6/19 って出したいのだ！
	return 0;
}`)
}