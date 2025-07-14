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


	//プレイヤーの座標位置を渡す
	VECTOR GetPos() const { return m_pos; }

private:

	//モデルのハンドル
	int m_handle;

	//モデルの座標
	VECTOR m_pos;
};	

