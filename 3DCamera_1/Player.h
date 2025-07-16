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

	//�v���C���[�̈ʒu��n��
	VECTOR GetPos() const { return m_pos; }

private:

	//�W���C�p�b�h�̏o��
	DINPUT_JOYSTATE m_input;

	//�W���C�p�b�h�̏o�͂̕ێ�
	int m_pad;

	//���f���̃n���h��
	int m_handle;

	//���f���̍��W
	VECTOR m_pos;
};	

