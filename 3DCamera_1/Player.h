#pragma once
#include "DxLib.h"

class Player
{
public:

	Player();
	virtual ~Player();

	//初期化
	void Init();

	//動き
	void Update();

	//描画
	void Draw();

	//プレイヤーの位置を渡す
	VECTOR GetPos() const { return m_pos; }

private:

	//ジョイパッドの出力
	DINPUT_JOYSTATE m_input;

	//ジョイパッドの出力の保持
	int m_pad;

	//モデルのハンドル
	int m_handle;

	//モデルの座標
	VECTOR m_pos;
};	

