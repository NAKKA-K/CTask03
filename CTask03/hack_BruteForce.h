#ifndef _HACK_BRUTEFORCE_H
#define _HACK_BRUTEFORCE_H

class Brute1 {

public:
	Brute1();
	~Brute1();

	void BruteGraph();
	void BruteKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[4];
	char answer[8][4] = { "000","001","010","011","100","101","110","111" };
	unsigned int ansNum;	//答え格納(乱数)

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
};

void HackBrute1();



//継承とかする暇なかったんです。許してください。
//変更がある場所は2か所だけなんです。すいません。
class Brute2 {
public:
	Brute2();
	~Brute2();

	void BruteGraph();
	void BruteKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[4];
	char answer[8][4] = { "aaa","aab","aba","abb","baa","bab","bba","bbb" };
	unsigned int ansNum;	//答え格納(乱数)

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
};

void HackBrute2();



#endif // !_HACK_BRUTEFORCE_H