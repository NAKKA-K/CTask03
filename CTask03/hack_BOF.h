#ifndef _HACK_BOF_H
#define _HACK_BOF_H

class BOF
{
public:
	BOF();
	~BOF();

	void BOFGraph();
	void BOFKey();
	bool IsCreated();
	
private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bobP[2];
	int webAppP[4];
	char str[64];
	int bright;


	static bool m_createdFlag;

	int m_bobG,m_cathyG,m_tomG;
	int m_hackBG;
	int m_balloonG[3];
	int m_webAppG;
};

void HackBOF();

/*
BOF* BOF::getInstance()
{
	static BOF *bof;
	if (flag == false){
		bof = new BOF();
		flag = true;
	}
	return bof;
}
//BOF::getInstance()->GetScene();
*/
#endif // !_HACK_BOF_H