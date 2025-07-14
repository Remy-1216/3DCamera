#include "Player.h"

Player::Player():m_handle(-1),m_pos(VGet(0.0f,0.0f,0.0f))
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
	m_handle = MV1LoadModel("data/model/player/Player.mv1");

	//モデルの位置を設定する
	MV1SetPosition(m_handle, m_pos);

}

void Player::Update()
{

}

void Player::Draw()
{
	//モデルの表示
	MV1DrawModel(m_handle);
}
