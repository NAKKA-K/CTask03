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

	static char m_questionTitle[32][64];	//�Ƃ肠����32���ڂ�����΂������ȁH
	static bool m_readedListFlag;	//�ǂݍ��݃t���O
	static int m_questionNum;	//��ԍŌ�ɓǂݍ��񂾖��̎��ʔԍ�(strNum)
	static int m_selectList;
	static int m_questionCount;	//��萔(�s��)�J�E���g

	static int m_hackListBG;		//�E�w�i�摜�ǂݍ���
	const char *m_genreName[3] = {		//�W��������
		"Program",	"Network","Cipher"
	};

};

#endif // !_HACK_LIST_IO_H
