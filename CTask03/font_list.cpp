#include "font_list.h"
#include"font_list.h"
#include<DxLib.h>
int FontList::m_font50 = 0;
int FontList::m_font100 = 0;
int FontList::m_loadFlag = 0;
int FontList::m_colorBlack = 0;
int FontList::m_colorWhite = 0;
int FontList::m_colorWhite1 = 0;
int FontList::m_colorGreen = 0;


FontList::FontList()
{
	if (m_loadFlag==0) {
		m_colorWhite = GetColor(255, 255, 255);
		m_colorWhite1 = GetColor(100, 100, 100);
		m_colorBlack = GetColor(0, 0, 0);
		m_colorGreen = GetColor(0, 255, 0);
		m_font50 = CreateFontToHandle(NULL, 50,-1);
		m_font100 = CreateFontToHandle(NULL, 100, -1);

		//ì«Ç›çûÇ›Çêßå¿Ç∑ÇÈÇΩÇﬂÇÃflag
		m_loadFlag = 1;
	}

}
FontList::~FontList()
{
	DeleteFontToHandle(m_font50);
}
