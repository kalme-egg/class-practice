#ifndef _NAZO_H_
#define _NAZO_H_

class Nazo {
private:
	static int maxID;											// IDを作るときに使うstatic変数
	int ID;														// なぞのいきもの毎固有のID
	float height;
	int age;
	bool alive;

	void setID(int ID) {this->ID = ID;}						// IDは外から変更してほしくないためprivate
	void setAlive(bool alive) {this->alive = alive;}
	void setHeight(float height) {this->height = height;}
public:

	Nazo(void );
	Nazo(int age);
	~Nazo();													// デストラクタは~(クラス名)、引数も指定しない

	int getID(void ) {return ID;}								// 外からはIDの取得だけできる
	float getHeight(void ) {return height;}						// maxIDは自分の関数内で直接参照、編集することにする
	int getAge(void ) {return age;}
	void setAge(int age);
	bool getAlive(void ) {return this->alive;}

	void sayHi(void );
	void calculateHeight(void );
	bool kill(void );
	void displayInfo(void );
};

#endif /* _NAZO_H_ */