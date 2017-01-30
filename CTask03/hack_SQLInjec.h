#ifndef _HACK_SQLINJEC_H
#define _HACK_SQLINJEC_H

class SQL
{
public:
	SQL();
	~SQL();

	void SQLGraph();
	void SQLKey();
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

void HackSQL();



#endif // !_HACK_SQLINJEC_H