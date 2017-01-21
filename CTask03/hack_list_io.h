#ifndef _HACK_LIST_IO_H
#define _HACK_LIST_IO_H


#include<string>
class HackListIO
{
public:
	HackListIO();
	~HackListIO();

	bool ReadHackList();	//FileRead
	void DrawHackList();	//Draw& Key& Mouse
	static bool GetReadedListFlag();	//return m_readedListFlag;
	static void SetReadedListFlag(bool readedListFlag);
	static int GetSelectList();

private:

	FILE *fp;

	static char m_questionTitle[32][64];	//とりあえず32項目もあればいいかな？
	static bool m_readedListFlag;	//読み込みフラグ
	static int m_questionNum;	//一番最後に読み込んだ問題の識別番号(strNum)
	static int m_selectList;
	static int m_questionCount;	//問題数(行数)カウント

	static int m_hackListBG;		//・背景画像読み込み
	const char *m_genreName[3] = {		//ジャンル名
		"Program",	"Network","Cipher"
	};

};

#endif // !_HACK_LIST_IO_H
