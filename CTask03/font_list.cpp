#include "font_list.h"
#include"font_list.h"
#include<DxLib.h>

int FontList::m_font20 = 0;
int FontList::m_font22 = 0;
int FontList::m_font25 = 0;
int FontList::m_font30 = 0;
int FontList::m_font35 = 0;
int FontList::m_font40 = 0;
int FontList::m_font50 = 0;
int FontList::m_font65 = 0;
int FontList::m_font70 = 0;
int FontList::m_font75 = 0;
int FontList::m_font80 = 0;
int FontList::m_font100 = 0;



int FontList::m_loadFlag = 0;
int FontList::m_colorBlack = 0;
int FontList::m_colorWhite = 0;
int FontList::m_colorWhite1 = 0;
int FontList::m_colorOrange = 0;
int FontList::m_colorGreen = 0;
int FontList::m_colorGreen1 = 0;
int FontList::m_colorBlue = 0;
int FontList::m_colorRed = 0;
int FontList::m_colorBrown = 0;

int FontList::m_colorGreen2 = 0;
int FontList::m_colorOrange1 = 0;
int FontList::m_colorBlue1 = 0;

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

		m_colorRed = GetColor(255, 28, 37);
		m_colorBrown = GetColor(183, 65, 14);
		m_colorGreen2 = GetColor(111, 255, 28);
		m_colorOrange1 = GetColor(255, 103, 28);
		m_colorBlue1 = GetColor(28, 73, 255);


		m_font20 = CreateFontToHandle(NULL, 20, -1);
		m_font22 = CreateFontToHandle(NULL, 22, -1);
		m_font25 = CreateFontToHandle(NULL, 25, -1);
		m_font30 = CreateFontToHandle("メイリオ", 30, -1);
		m_font35 = CreateFontToHandle(NULL, 35, -1);
		m_font40 = CreateFontToHandle(NULL, 40, -1);
		m_font50 = CreateFontToHandle("メイリオ", 50, -1);
		m_font65 = CreateFontToHandle(NULL, 65, -1);
		m_font70 = CreateFontToHandle(NULL, 70, -1);
		m_font75 = CreateFontToHandle("メイリオ", 75, -1);
		m_font80 = CreateFontToHandle(NULL, 80, -1);
		m_font100 = CreateFontToHandle("メイリオ", 100, -1);

		//読み込みを制限するためのflag
		m_loadFlag = 1;
	}

}
FontList::~FontList()
{
}
