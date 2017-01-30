#ifndef _HACK_SESSIONHIJACK_H
#define _HACK_SESSIONHIJACK_H

class Hijack
{
public:
	Hijack();
	~Hijack();

	void HijackMain();
	void HijackGraph(int animeFlg, int pal, int mail_X, int mail_Y);
	void HijackKey(int *animeFlg, int *timeFlg, int *timer, int *pal, int *mail_X, int *mail_Y);
	bool IsCreated();


private:
	static bool m_createdFlag;

	int timer, timeFlg, animeFlg, pal, mail_X, mail_Y;


	//‰æ‘œ
	int SM;
	int backScreen;
	int bob;
	int cathy;
	int tom;
	int pc;
	int smartphone_Cathy;
	int receive1;
	int receive2;
	int receive3;
	int send1;
	int send2;
	int send3;
	int frame;
	int mail;
	int vector_Red_R;
	int vector_Red_L;
	int vector_Red_S1;
	int vector_Red_S2;
	int vector_Blue_S1;
	int vector_Blue_S2;
	int vector_Blue_S3;
	int vector_Blue_LB;


};

void HackHijack();




#endif //!_HACK_SESSIONHIJACK_H