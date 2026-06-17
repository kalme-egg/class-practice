#include "Nazo.h"
#include <iostream>

using namespace std;

Nazo::Nazo(void )										// コンストラクタは長さに関わらずcppファイルに置く 返り値は書かない
{														// 初期状態を考えながら書く
	this->setAge(0);									// デフォルトなら0才
	this->setAlive(true);								// 最初は生きてる
}														// returnもいらない

Nazo::Nazo(int age)										// 年令を指定するコンストラクタ
{														// 初期状態を考えながら書く
	this->setAge(age);									// 指定された年令
	this->setAlive(true);								// 最初は生きてる
}														// returnもいらない

void Nazo::setAge(int age)
{
	if (!alive) return;									// 死んでたら年令を変えられないようにした
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

bool Nazo::kill(void )									// なぞのいきものを殺す関数
{
	bool killable = this->getAlive();					// 成功失敗の結果を返すような関数を作ることも多い
	this->setAlive(false);								// こことコンストラクタ以外でsetAlive()は呼ばれない
	return killable;
}

void Nazo::displayInfo(void )
{
	cout << "position: " << this << endl;
	cout << "height: " << this->getHeight() << endl;
	cout << "age: " << this->getAge() << endl;
	cout << "alive?: " << this->getAlive() << endl;
	cout << endl;
	return;
}