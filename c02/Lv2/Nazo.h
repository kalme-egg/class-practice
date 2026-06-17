#ifndef _NAZO_H_
#define _NAZO_H_

class Nazo {													// クラス定義 ゲッタ/セッタといった簡単なものはヘッダに書いてしまう
private:														// 外からアクセスできない、main.cppから直接読んだりできない
	float height;
	int age;
	bool alive;

	void setAlive(bool alive) {this->alive = alive;}			// setAliveをprivateに移動した
	void setHeight(float height) {this->height = height;}
public:															// 外からアクセスできる

	Nazo(void );												// デフォルトコンストラクタ 何も宣言せずに作ると呼ばれる関数
	Nazo(int age);												// コンストラクタはクラス名とまったく同じ名前の関数
																// 引数を変えてオーバーロードを使用し、呼び出し方によって作り方を少し変えられる

	float getHeight(void ) {return height;}
	int getAge(void ) {return age;}
	void setAge(int age);
	bool getAlive(void ) {return this->alive;}

	void sayHi(void );
	void calculateHeight(void );								// 体長を計算する関数
	bool kill(void );											// なぞのいきものを殺す関数 殺したかを返す
	void displayInfo(void );									// coutへ情報を表示する関数
};

#endif /* _NAZO_H_ */