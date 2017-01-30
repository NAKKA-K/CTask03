#ifndef _HACK_XSS_H
#define _HACK_XSS_H

class XSS
{
public:
	XSS();
	~XSS();

	void XSSGraph();
	void XSSKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[32];

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
	int m_pcG;
	int m_tomG;

};

void HackXSS();


#endif // !_HACK_XSS_H

