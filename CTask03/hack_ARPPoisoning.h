#ifndef _HACK_ARPPOISONING_H
#define _HACK_ARPPOISONING_H

class ARP
{
public:
	ARP();
	~ARP();

	void ARPGraph();
	void ARPKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[32];

	static bool m_createdFlag;

	int m_hackBG;
	int m_bobG;
	int m_cathyG;
	int m_tomG;

};

void HackARP();



#endif // !_HACK_ARPPOISONING_H