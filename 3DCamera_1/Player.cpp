#include "Player.h"

Player::Player():m_handle(-1),m_pos(VGet(0.0f,0.0f,0.0f))
{
}

Player::~Player()
{
	//���f���̍폜
	MV1DeleteModel(m_handle);
}

void Player::Init()
{
	//���f�������[�h�A���������f����ۑ����Ă���ʒu�������B
	m_handle = MV1LoadModel("data/model/player/Player.mv1");

	//���f���̈ʒu��ݒ肷��
	MV1SetPosition(m_handle, m_pos);

}

void Player::Update()
{

}

void Player::Draw()
{
	//���f���̕\��
	MV1DrawModel(m_handle);
}
