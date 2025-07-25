#include "DxLib.h"
#include "Player.h"
#include <vector>
#include <algorithm>

Player::Player():m_handle(-1), m_characterAngle(0.0f), m_pos(VGet(0.0f, 0.0f, 0.0f)),  m_movementDirection(VGet(0.0f, 0.0f, 0.0f))
{
}

Player::~Player()
{
	//モデルの削除
	MV1DeleteModel(m_handle);
}

void Player::Init()
{
	//モデルをロード、自分がモデルを保存している位置を書く。
	m_handle = MV1LoadModel("data/Player.mv1");

	
	//モデルの位置を設定する
	MV1SetPosition(m_handle, m_pos);
}

void Player::Update(float cameraAngle)
{
	//アナログスティックを使って移動
	int analogX = 0;
	int analogZ = 0;

	GetJoypadAnalogInput(&analogX, &analogZ, DX_INPUT_PAD1);

	//ベクトルの長さが最大で1000になる
	//プレイヤーの最大移動速度は0.01f / frame
	m_move = VGet(analogX, 0.0f, -analogZ);	//ベクトルの長さは0～1000

	//0.00 ~ 0.01の長さにする
	//ベクトルの長さを取得する
	float len = VSize(m_move);

	//ベクトルの長さを0.0~1.0の割合に変換する
	float rate = len / 1000.0f;

	//速度が決定できるので移動ベクトルに反映する
	m_move = VNorm(m_move);

	float speed = 10.0f * rate;
	m_move = VScale(m_move, speed);


	// カメラの回転を基準に方向を変換
	m_rotMatrix = MGetRotY(cameraAngle);
	m_movementDirection = VTransform(m_move, m_rotMatrix);

	//移動距離とキャラクターの座標を足す
	m_pos = VAdd(m_pos,m_movementDirection);

	// 移動中のみ向きを更新する
	if (VSize(m_movementDirection) > 0.0f)
	{
		m_characterAngle = atan2f(-m_movementDirection.x, -m_movementDirection.z);
	}

	//モデルの回転更新
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_characterAngle, 0.0f));

	//モデルの位置を設定する
	MV1SetPosition(m_handle, m_pos);
}

void Player::Draw()
{
	//モデルの表示
	MV1DrawModel(m_handle);

	//プレイヤーの座標位置を表示する
	DrawFormatString(0, 400, GetColor(255, 255, 255), "playerの座標(%.2f,%.2f,%.2f)", m_pos.x, m_pos.y, m_pos.z);
}
