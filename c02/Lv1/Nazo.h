#ifndef _NAZO_H_
#define _NAZO_H_

class Nazo {													// クラス定義 ゲッタ/セッタといった簡単なものはヘッダに書いてしまう
private:														// 外からアクセスできない、main.cppから直接読んだりできない
	float height;												// 変数そのものはprivateに隠す
	int age;
	bool alive;

	void setHeight(float height) {this->height = height;}		// セッタをprivateにすると自分以外が上書きできない変数を作れる
public:															// 外からアクセスできる

	float getHeight(void ) {return height;}						// 同名の引数や局所変数がなければ`this->`は省略出来る
	int getAge(void ) {return age;}								// ゲッタでは常にreturnするが、セッタではインライン展開するときはreturnを省略してよい
	void setAge(int age);										// 複雑なことをする場合はセッタヤゲッタもcppファイルに置く
	bool getAlive(void ) {return this->alive;}					// ゲッタ 自分の変数の値を返す関数
	void setAlive(bool alive) {this->alive = alive;}			// セッタ 自分の変数へ値を代入する関数

	void sayHi(void );
	void calculateHeight(void );								// 体長を計算する関数
	void displayInfo(void );									// coutへ情報を表示する関数
};

#endif /* _NAZO_H_ */