#include <iostream>
#include "Nazo.h"

using namespace std;

int main(void ){
	Nazo foo;											// なぞのいきものfooをデフォルトで作る
	cout << "foo: " << endl;
	foo.displayInfo();									// fooは多分ID0、0才で、生きてる
	foo.sayHi();
	cout << endl;

	Nazo bar(10);										// なぞのいきものbarを、年令を指定して作る
	cout << "bar: " << endl;
	bar.displayInfo();									// barは多分ID1、10才で、生きてる
	bar.sayHi();
	cout << endl;

	bool result;
	result = foo.kill();								// fooを殺す
	cout << "foo: " << endl;
	foo.displayInfo();									// fooは多分ID0、0才で、死んでる
	foo.sayHi();										// 死んじゃったので挨拶しない
	cout << endl;

	Nazo * habitat = new Nazo(3);						// new演算子は新しいオブジェクトを作って、そのポインタを返す
	(*habitat).displayInfo();							// 生息地にくらしているのは、多分ID2、3才で生きてるなぞのいきもの
	habitat->setAge(4);									// thisでできたことは普通のポインタでもできる
	habitat->kill();									// 4才にして殺してみる
	habitat->displayInfo();
	delete habitat;										// 生息地を消すとこのいきものもいなくなる 消し忘れるとずっとパソコンに棲みつづける
	cout << endl;

//	habitat->displayInfo();								// いなくなったいきものの情報を見ることはできない

//	new Nazo(20);										// なぜこういうことをしてはいけないのだろう?

	return 0;
}