#pragma once
#include "DxLib.h"

class Player
{
public:

	Player();
	virtual ~Player();

	//初期化
	void Init();

	//動き カメラのアングルを受け取る
	void Update(float cameraAngle);

	//描画
	void Draw();

	//プレイヤーの位置を渡す
	VECTOR GetPos() const { return m_pos; }

private:


	//モデルのハンドル
	int m_handle;

	//キャラクターが向いている方向
	float m_characterAngle;

	//モデルの座標
	VECTOR m_pos;

	// キャラクターがどこまで動いたか
	VECTOR m_move;

	//カメラの回転を方向に変換した値を保存する
	VECTOR m_movementDirection;

	//カメラのマトリックス
	MATRIX m_rotMatrix;

	// モデルの回転行列を作成
	MATRIX m_modelRotMatrix;
};	

