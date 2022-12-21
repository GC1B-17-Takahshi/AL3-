#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include <cassert>
#include "Input.h"
#include "DebugText.h"

/// <summary>
/// ���@
/// </summary>
class Player {
public:
	  /// <summary>
	  /// ������
	  /// </summary>
	  /// <param name="model">���f��</param>
	  /// <param name="textureHandle">�e�N�X�`���n���h��</param>
	  void Initialize(Model* model,uint32_t textureHandle);

	  /// <summary>
	  /// �X�V
	  /// </summary>
	  void Update();

	  /// <summary>
	  /// �`��
	  /// </summary>
	  void Draw();

private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
	//�C���v�b�g
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;
};