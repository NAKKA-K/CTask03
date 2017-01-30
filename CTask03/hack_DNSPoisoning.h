#ifndef _HACK_DNSPOISONING_H
#define _HACK_DNSPOISONING_H

class DNS {
public:
	DNS();
	~DNS();

	void DNSGraph();
	void DNSKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[32];

	static bool m_createdFlag;

	int m_hackBG;
	int m_pcG;
	int m_arrowBlueG;

};

void HackDNS();


#endif // !_HACK_DNSPOISONING_H