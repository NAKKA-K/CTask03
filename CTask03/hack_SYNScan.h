#ifndef _HACK_SYNSCAN_H
#define _HACK_SYNSCAN_H

class SYN
{
public:
	SYN();
	~SYN();

	void SYNGraph();
	void SYNKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[8];

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
	int m_pcG;
	int m_arrowBlueG;
	int m_arrowRedG;
};

void HackSYN();


#endif // !_HACK_SYNSCAN_H