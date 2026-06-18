#include "Nazo.h"
#include <iostream>

using namespace std;

int Nazo::maxID = 0;									// クラスのstatic変数はcppファイルで、staticを外した形で初期化する

Nazo::Nazo(void )
{														// 初期状態を考えながら書く
	this->setID(this->maxID);							// IDを今のmaxIDでセットする `this->maxID`の代わりに`Nazo::maxID`でもいい
	this->setAlive(true);
	this->setAge(0);
	this->maxID++;										// maxIDに1加算する 次に使うときはリセットされずに今より1増えた数がIDになる
}

Nazo::Nazo(int age)
{														// 初期状態を考えながら書く
	this->setID(this->maxID);							// IDを今のmaxIDでセットする `this->maxID`の代わりに`Nazo::maxID`でもいい
	this->setAlive(true);
	this->setAge(age);
	this->maxID++;										// maxIDに1加算する 次に使うときはリセットされずに今より1増えた数がIDになる
}

Nazo::~Nazo()											// デストラクタも中身は長さに関わらずcppファイルに置く 引数も返り値も書かない
{														// 何もしなくても定義するのが慣例
	cout << "bye." << endl;								// 今回はいなくなる度に挨拶してもらう
}

void Nazo::setAge(int age)
{
	if (!alive) return;
	this->age = age;
	calculateHeight();
	return;
}

void Nazo::sayHi(void )
{
	if (this->alive) {
		cout << "Hi!" << endl;
	}
	return;
}

void Nazo::calculateHeight(void )
{
	this->setHeight(this->getAge() + 8.5);
	return;
}

bool Nazo::kill(void )
{
	bool killable = this->getAlive();
	this->setAlive(false);
	return killable;
}

void Nazo::displayInfo(void )
{
	cout << "ID: " << this->getID() << endl;					// IDも一緒に表示する
	cout << "position: " << this << endl;
	cout << "height: " << this->getHeight() << endl;
	cout << "age: " << this->getAge() << endl;
	cout << "alive?: " << this->getAlive() << endl;
	cout << endl;
	return;
}