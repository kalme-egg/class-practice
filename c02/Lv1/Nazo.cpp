#include "Nazo.h"
#include <iostream>

using namespace std;

void Nazo::setAge(int age)								// 複雑なことをする場合はセッタヤゲッタもcppファイルに置く
{
	this->age = age;									// `クラス名::メンバ関数`の中ではprivateの変数も触れる
	calculateHeight();									// 年令がセットされるたびに体長を再計算する
}

void Nazo::sayHi(void )
{
	if (this->alive) {									// `this->`を使うと自分の変数を参照できる
		cout << "Hi!" << endl;							// 死んでたら、つまり生きて無かったら挨拶しないようにした
	}
	return;
}

void Nazo::calculateHeight(void )						// 体長を計算する関数
{
	this->setHeight(this->getAge() + 8.5);				// 今回はやる必要はないが、関数の中でも極力セッタやゲッタを呼んだ方が良い
//	height = age + 8.5;									// これでも同じ動作をする 逆にセッタやゲッタを呼びたくないときは直接呼んでもいい
}

void Nazo::displayInfo(void )
{
	cout << "position: " << this << endl;				// そもそもthisは自分のポインタを指し示すキーワード
	cout << "height: " << this->getHeight() << endl;	// ->(アロー演算子)はポインタの先のオブジェクトのメンバを参照する演算子
	cout << "age: " << this->getAge() << endl;			// つまりこれらがやってることは全て`(*this).getAge()`に同じ
	cout << "alive?: " << this->getAlive() << endl;
	cout << endl;
}