#ifndef _NAZO_H_
#define _NAZO_H_

class Nazo {					// クラス定義 ヘッダでは基本的に関数の中身などは定義しない
public:							// 外からアクセスできる
	float height;				// 体長
	int age;					// 年令
	bool alive;					// 生きてるか

	void sayHi(void );			// 挨拶をする関数
};

#endif /* _NAZO_H_ */