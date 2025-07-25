#include "Object.h"

Object::Object()
{

}

Object::~Object()
{
	for (int i = 0; i < 4; i++)
	{
		MV1DeleteModel(m_handle[i]);
	}
	
}

void Object::Init()
{
	//モデルをロードする
	for (int i = 0; i < 4; i++)
	{
		m_handle[i] = MV1LoadModel("data/Cube_Grass_Single.mv1");
	}
	//座標位置
	m_pos[0] = VGet(100.0f, 0.0f, 100.0f);
	m_pos[1] = VGet(-1000.0f, 0.0f, -100.0f);
	m_pos[2] = VGet(1000.0f, 0.0f, -100.0f);
	m_pos[3] = VGet(-1000.0f, 0.0f, 100.0f);

	//モデルの位置を設定する

	for (int i = 0; i < 4; i++)
	{
		//モデルの位置を設定する
		MV1SetPosition(m_handle[i], m_pos[i]);
	}

}

void Object::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		//モデルの表示
		MV1DrawModel(m_handle[i]);
	}

}
