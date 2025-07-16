#include "Player.h"

Player::Player():m_handle(-1),m_pos(VGet(0.0f,0.0f,0.0f)),m_pad(0)
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

void Player::Update()
{
	m_pad = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_input);

	//スティックを倒した方向に進む
	if (m_input.X < 0)
	{
		m_pos.x -= 10.0f;
	}
	if((m_input.X > 0))
	{
		m_pos.x += 10.0f;
	}

	if (m_input.Y < 0)
	{
		m_pos.z += 10.0f;
	}
    if(m_input.Y > 0)
	{
		m_pos.z -= 10.0f;
	}

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
