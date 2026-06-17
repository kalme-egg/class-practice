#include "Nazo.h"				// ヘッダファイルをインクルードして定義する
#include <iostream>

using namespace std;

void Nazo::sayHi(void )			// cppファイルなどでクラスのメンバを再定義するときは`クラス名::メンバ名`を使う
{
	cout << "Hi!" << endl;
	return;
}