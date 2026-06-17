#include <iostream>
#include "Nazo.h"

using namespace std;

int main(void ){
	Nazo foo;											// なぞのいきものfooを作る
	foo.height = 13.5;									// メンバへは`(オブジェクト).メンバ名`でアクセスする
	foo.age = 5;
	foo.alive = true;

	cout << "foo: " << endl;
	cout << "  height: " << foo.height << endl;			// メンバへは`(オブジェクト).メンバ名`でアクセスする
	cout << "  age: " << foo.age << endl;

	foo.sayHi();										// 関数の使い方も同じ
	cout << endl;

	foo.age = 9;										// 上書きしようと思えばできる
	foo.alive = false;
	cout << "foo: " << endl;
	cout << "  height: " << foo.height << endl;
	cout << "  age: " << foo.age << endl;
	
	foo.sayHi();
	cout << endl;

	return 0;
}