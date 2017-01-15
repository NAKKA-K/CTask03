#ifndef _MOUSE_STATUS_H
#define _MOUSE_STATUS_H

class MouseStatus
{
public:
	MouseStatus();

	bool GetMouseStatus(int x1, int y1, int x2, int y2);
	int GetMouseButton();	//¶ƒNƒŠƒbƒN‚³‚ê‚Ä‚¢‚é‚©•Ô‚·

private:
	int m_mouseButton;
	int m_mouseX, m_mouseY;
};

#endif // !_MOUSE_STATUS_H
