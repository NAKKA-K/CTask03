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
	unsigned int ansNum;	//�����i�[(����)

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
};

void HackBrute1();



//�p���Ƃ�����ɂȂ�������ł��B�����Ă��������B
//�ύX������ꏊ��2���������Ȃ�ł��B�����܂���B
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
	unsigned int ansNum;	//�����i�[(����)

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
};

void HackBrute2();



#endif // !_HACK_BRUTEFORCE_H