#ifndef _TITLE_H
#define _TITLE_H

class Title
{
public:
	Title();
	~Title();

	void TitleGraph();
	void TitleKey();
	int GetFont();

private:
	int m_font100;
	int m_menuBG;
};

#endif // !_TITLE_H
