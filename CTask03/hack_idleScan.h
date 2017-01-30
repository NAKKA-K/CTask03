#ifndef _HACK_IDLESCAN_H
#define _HACK_IDLESCAN_H

class Idle
{
public:
	Idle();
	~Idle();

	void IdleMain();
	void IdleGraph(int animeFlg);
	void IdleKey(int *animeFlg, int *timeFlg, int *timer);
	bool IsCreated();


private:
	static bool m_createdFlag;

	int timer, timeFlg, animeFlg;

	//‰æ‘œ
	int backScreen;
	int tom;
	int pc;
	int vector_Red_R;
	int vector_Red_L;
	int vector_Red_S1;
	int vector_Red_S2;
	int vector_Blue_S1;
	int vector_Blue_S2;
	int vector_Blue_S3;
	int vector_Blue_LB;
};

void HackIdle();




#endif //!_HACK_IDLESCAN_H