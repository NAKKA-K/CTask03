#include"learn.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"hack_list_io.h"
#include"genre_select.h"
#include<DxLib.h>
#include<stdio.h>


void HackLearn()
{
	static Learn *learn;
	if (learn->IsCreated() == false) learn = new Learn();	//コンストラクタの内部で自動的にflagをtrueに変更


	learn->LearnGraph();		//自動アニメーションや操作アニメーション
	learn->LearnKey();

	//問題の終了処理
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete learn;
		learn = nullptr;
	}
	return;
}


bool Learn::m_createdFlg = false;

Learn::Learn():m_scene(0),m_maxScene(0)
{
	m_createdFlg = true;

	memset(folderName, '\0', sizeof(folderName));

	//フォルダへのパスを特定
	if (GenreSelect::GetSelectGenre()==0) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*BOF攻撃*/
			strcpy_s(folderName, sizeof(folderName), "Learn/BOF攻撃/");
			break;
		default:
			SceneMgr::SetScene(SCENE_LIST);
			break;
		}
	}
	else if (GenreSelect::GetSelectGenre() == 1) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*ARPキャッシュポイズニング*/
			strcpy_s(folderName, sizeof(folderName), "Learn/ARPキャッシュポイズニング/");
			break;
		case 2:	/*DOS攻撃*/
			strcpy_s(folderName, sizeof(folderName), "Learn/DOS攻撃/");
			break;
		case 3:	/*標的型攻撃*/
			strcpy_s(folderName, sizeof(folderName), "Learn/標的型攻撃/");
			break;
		default:
			SceneMgr::SetScene(SCENE_LIST);
			break;
		}
	}
	else if (GenreSelect::GetSelectGenre() == 2) {
		switch (HackListIO::GetSelectList()) {
		default:
			SceneMgr::SetScene(SCENE_LIST);
			break;
		}
	}


	//指定パスのカレントディレクトリにある画像を一括取得
	for (int i = 0; i < 32; i++) {
		char fileFullPath[64];	//folderName[56]+fileName[8]=64
		sprintf_s(fileFullPath, sizeof(fileFullPath), "%s%d.png", folderName, i + 1);

		if ((m_sceneG[i] = LoadGraph(fileFullPath)) == -1) {	//error?
			m_maxScene = i;
			break;
		}
	}

}
Learn::~Learn()
{
	m_createdFlg = false;

	for (int i = 0; i < m_maxScene;i++) {
		DeleteGraph(m_sceneG[i]);
	}
}

void Learn::LearnGraph()
{
	DrawGraph(0, 0, m_sceneG[m_scene], TRUE);

	return;
}
void Learn::LearnKey()
{
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1 && m_scene < m_maxScene - 1) {
		m_scene++;
	}
	else if (Keyboard_Get(KEY_INPUT_LEFT) == 1 && m_scene >= 1) {
		m_scene--;
	}
	else if (Keyboard_Get(KEY_INPUT_BACK)==1) {
		SceneMgr::SetScene(SCENE_LIST);
	}

	return;
}
bool Learn::IsCreated()
{
	return m_createdFlg;
}
