#pragma once
#include "DxLib.h"

class Player
{
public:

	Player();
	virtual ~Player();

	//������
	void Init();

	//����
	void Update();

	//�`��
	void Draw();


	//�v���C���[�̍��W�ʒu��n��
	VECTOR GetPos() const { return m_pos; }

private:

	//���f���̃n���h��
	int m_handle;

	//���f���̍��W
	VECTOR m_pos;
};	

