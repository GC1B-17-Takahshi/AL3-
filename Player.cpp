#include "Player.h"

void Player::Initialize(Model* model, uint32_t textureHandle) {
	//NULL�|�C���^�`�F�b�N
	assert(model);

	//�����Ƃ��Ď󂯎�����f�[�^�������o�ϐ��ɋL�^����
	model_ = model;
	textureHandle_ = textureHandle;

	//�V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//���[���h�ϊ��̏�����
	worldTransform_.Initialize();
}

void Player::Update() {
	//�L�����N�^�[�̈ړ����x
	const float speed = 0.5f;

	//��L�[����������
	if (input_->PushKey(DIK_UP)) {
		worldTransform_.translation_.y += speed;
	}
	//���L�[����������
	if (input_->PushKey(DIK_DOWN)) {
		worldTransform_.translation_.y -= speed;
	}
	//���L�[����������
	if (input_->PushKey(DIK_LEFT)) {
		worldTransform_.translation_.x -= speed;
	}
	//�E�L�[����������
	if (input_->PushKey(DIK_RIGHT)) {
		worldTransform_.translation_.x += speed;
	}

	//���s�ړ��s���錾
	Matrix4 matTrans = MathUtility::Matrix4Identity();//�P�ʍs��
	matTrans.m[3][0] = worldTransform_.translation_.x;
	matTrans.m[3][1] = worldTransform_.translation_.y;
	matTrans.m[3][2] = worldTransform_.translation_.z;
	//���[���h�s���P�ʍs��ŏ�����
	worldTransform_.matWorld_ = MathUtility::Matrix4Identity();
	//���[���h�s��ɕ��s�ړ��s���������
	worldTransform_.matWorld_ *= matTrans;
	//���[���h�s��̓]��
	worldTransform_.TransferMatrix();
}

void Player::Draw() {

}