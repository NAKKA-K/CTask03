#ifndef _MODE_SELECT_H
#define _MODE_SELECT_H


#define MAX_SELECT_MODE 2
class ModeSelect
{
public:
	ModeSelect();
	~ModeSelect();

	void ModeGraph();
	void ModeKey();
	int GetFont();
	static int GetSelectMode();

private:
	static int m_selectMode;
	int m_font100;
	int m_menuBG;
};

#endif // !_MODE_SELECT_H
