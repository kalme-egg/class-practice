#include <iostream>
#include "Nazo.h"

using namespace std;

int main(void ){
	Nazo foo;											// なぞのいきものfooをデフォルトで作る
	cout << "foo: " << endl;
	foo.displayInfo();									// fooは0才で、生きてる
	foo.sayHi();
	cout << endl;

	Nazo bar(10);										// なぞのいきものbarを、年令を指定して作る
	cout << "bar: " << endl;
	bar.displayInfo();									// barは10才で、生きてる
	bar.sayHi();
	cout << endl;

	bool result;
	result = foo.kill();								// fooを殺す
	cout << "foo: " << endl;
	foo.displayInfo();									// fooは0才で、死んでる
	foo.sayHi();										// 死んじゃったので挨拶しない
	cout << endl;

	if (foo.getAlive() == false) {
		cout << "fooが死んじゃった..." << endl;
	}
	
	if (result == true) {								// resultにはfoo.kill()の結果を入れてある
		cout << "fooを殺した" << endl;
	}

//	foo.setAlive(true);									// セッタにアクセスできなくなったのでもう蘇生できない
//	foo.sayHi();

	result = foo.kill();
	foo.setAge(8);										// 死んだので成長もしない
	if (result == true) {								// 2回死ぬこともない
		cout << "fooをもう一回殺した" << endl;
	}
	foo.displayInfo();

	return 0;
}