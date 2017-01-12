#ifndef _SCENE_MGR_H
#define _SCENE_MGR_H

enum SCENE {
	SCENE_INIT,			//�Q�[���J�n���̏�����(���͏��������K�v�Ȏ�)
	SCENE_TITLE,		//�^�C�g�����
	SCENE_GENRE,		//�W�������I�����
	SCENE_MODE,		//���[�h�I�����
	SCENE_LIST,			//?���I�����

	SCENE_GAME
	//SCENE_PROGRAM,	//�v���O�����̐Ǝ㐫�ɑ΂���U�炪�w�ׂ郂�[�h
	//SCENE_NETWORK,	//NetWork�̐Ǝ㐫�ɑ΂���U�炪�w�ׂ郂�[�h
	//SCENE_CIPHER,		//�Í����A�������w�ׂ郂�[�h
};


class SceneMgr {
public:
	static void SetScene(int scene);
	static int GetScene();

private:
	static int m_scene;	//������邱�Ƃ͂Ȃ��̂ŋ��L
};


#endif _SCENE_MGR_H
