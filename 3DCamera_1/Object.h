#pragma once
#include "DxLib.h"

class Object
{
public:

	Object();

	virtual ~Object();

	//������
	void Init();

	//�`��
	void Draw();

private:

	//���f���̃n���h���@�����\���h���܂��B
	int m_handle[4];

	//���W �����ɔz�u���܂�
	VECTOR m_pos[4];

};

