#pragma once
#include "DxLib.h"

class Camera
{
public:
    Camera();
    virtual ~Camera();

    //������
    void Init();

    //�J�����̓���
    //�J������Ǐ]���邽�߂ɁA�v���C���[�̍��W�ʒu���󂯎��
    void Update(VECTOR mplayerPos);

private:

    //�W���C�p�b�h�̏o��
    DINPUT_JOYSTATE m_input;

    //�W���C�p�b�h�̏o�͂̕ێ�
    int m_pad;

    //�J�����A���O���̈ʒu
    float m_cameraAngle;

    //�J�����̍��W
    VECTOR m_cameraPos;

    //�J�����̒����_
    VECTOR m_cameraTarget;

};

