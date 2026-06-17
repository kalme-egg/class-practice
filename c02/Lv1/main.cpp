#include <iostream>
#include "Nazo.h"

using namespace std;

int main(void ){
	Nazo foo;											// なぞのいきものfooを作る
//	foo.age = 5;										// privateになったメンバへはアクセスできない
	foo.setAge(5);										// セッタを使うと値を代入できる
	foo.setAlive(true);
//	foo.setHeight(13.5);								// 自動で計算するので必要ないし、privateにしたので使えない

	cout << "foo: " << endl;
	foo.displayInfo();
	foo.sayHi();
	cout << endl;

	foo.setAge(9);										// 勿論上書きできる
	foo.setAlive(false);

	cout << "foo: " << endl;
	foo.displayInfo();
	foo.sayHi();										// 死んじゃったので挨拶しない
	cout << endl;

	if (foo.getAlive() == false) {						// mainからでももちろんゲッタを使えば値を読める
		cout << "fooが死んじゃった..." << endl;
	}

	foo.setAlive(true);									// セッタにアクセスできるので死んじゃった後に蘇生できる
	foo.sayHi();										// おかえり!

	return 0;
}