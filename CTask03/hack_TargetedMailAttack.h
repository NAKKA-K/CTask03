#ifndef _HACK_TARGETEDMAILATTACK_H
#define _HACK_TARGETEDMAILATTACK_H


void TargetedMailAttack(int num);

class MAIL
{
public:
	MAIL();
	~MAIL();
	bool IsCreated();

	void Init(void);
	void Putstring(int x, int y, int kaigyo, char str[255], int WordCount, int colorFlg);
	void MailFrame(int x, int y);
	void DrawMailLeft(int x, int y, int select);
	void DrawMailRight(int x, int y, int select);
	void TargetedMailKey(int *select1, int *select2);
	void TargetedMail(void);
	void InputFile(int num);
	void False(void);
	void True(void);
private:
	int MailBG;
	int m_falseG;
	static bool m_createdFlag;

};

#endif // !_HACK_TARGETEDMAILATTACK_H