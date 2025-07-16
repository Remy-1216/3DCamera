#pragma once
#include "DxLib.h"

class Camera
{
public:
    Camera();
    virtual ~Camera();

    //初期化
    void Init();

    //カメラの動き
    //カメラを追従するために、プレイヤーの座標位置を受け取る
    void Update(VECTOR playerPos);

private:

    //ジョイパッドの出力
    DINPUT_JOYSTATE m_input;

    //ジョイパッドの出力の保持
    int m_pad;

    //左右のアングルの位置
    float m_cameraAngleX;

    //上下のアングルの位置
    float m_cameraAngleY;

    //カメラの座標
    VECTOR m_cameraPos;

    //カメラの注視点
    VECTOR m_cameraTarget;

};

