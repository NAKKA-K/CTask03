#include "menu_graph_list.h"
#include<DxLib.h>

int MenuGraphList::m_menuG = 0;
int MenuGraphList::m_pulse = 0;
int MenuGraphList::m_bin = 0;
int MenuGraphList::m_titleG = 0;
int MenuGraphList::m_modeG = 0;
int MenuGraphList::m_hackListBG = 0;

MenuGraphList::MenuGraphList()
{
	m_bin = LoadGraph("Image/bin.png");
	m_menuG = LoadGraph("Image/pnc.png");
	m_pulse = LoadGraph("Image/pulse.png");
	m_titleG = LoadGraph("Image/Title.png");
	m_modeG = LoadGraph("Image/tl.png");
	m_hackListBG = LoadGraph("Image/hacklist.png");
}

MenuGraphList::~MenuGraphList()
{
}
