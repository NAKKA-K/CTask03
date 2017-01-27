#include "font_list.h"
#include"font_list.h"
#include<DxLib.h>

int FontList::m_font30 = 0;
int FontList::m_font50 = 0;
int FontList::m_font75 = 0;
int FontList::m_font100 = 0;

int FontList::m_loadFlag = 0;
int FontList::m_colorBlack = 0;
int FontList::m_colorWhite = 0;
int FontList::m_colorWhite1 = 0;
int FontList::m_colorOrange = 0;
int FontList::m_colorGreen = 0;
int FontList::m_colorGreen1 = 0;
int FontList::m_colorBlue = 0;

FontList::FontList()
{
	if (m_loadFlag==0) {
		m_colorWhite = GetColor(255, 255, 255);
		m_colorWhite1 = GetColor(100, 100, 100);
		m_colorBlack = GetColor(0, 0, 0);
		m_colorOrange = GetColor(183, 65, 14);
		m_colorGreen = GetColor(0, 255, 0);
		m_colorGreen1 = GetColor(50, 200, 80);
		m_colorBlue = GetColor(0,0,255);
		m_font30 = CreateFontToHandle("メイリオ", 30, -1);
		m_font50 = CreateFontToHandle("メイリオ", 50, -1);
		m_font75 = CreateFontToHandle("メイリオ", 75, -1);
		m_font100 = CreateFontToHandle("メイリオ", 100, -1);

		//読み込みを制限するためのflag
		m_loadFlag = 1;
	}

}
FontList::~FontList()
{
}
