#include "Player.h"

void Player::Initialize(Model* model, uint32_t textureHandle) {
	//NULLポインタチェック
	assert(model);

	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	textureHandle_ = textureHandle;

	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ワールド変換の初期化
	worldTransform_.Initialize();
}

void Player::Update() {
	//キャラクターの移動速度
	const float speed = 0.5f;

	//上キーを押したら
	if (input_->PushKey(DIK_UP)) {
		worldTransform_.translation_.y += speed;
	}
	//下キーを押したら
	if (input_->PushKey(DIK_DOWN)) {
		worldTransform_.translation_.y -= speed;
	}
	//左キーを押したら
	if (input_->PushKey(DIK_LEFT)) {
		worldTransform_.translation_.x -= speed;
	}
	//右キーを押したら
	if (input_->PushKey(DIK_RIGHT)) {
		worldTransform_.translation_.x += speed;
	}

	//平行移動行列を宣言
	Matrix4 matTrans = MathUtility::Matrix4Identity();//単位行列
	matTrans.m[3][0] = worldTransform_.translation_.x;
	matTrans.m[3][1] = worldTransform_.translation_.y;
	matTrans.m[3][2] = worldTransform_.translation_.z;
	//ワールド行列を単位行列で初期化
	worldTransform_.matWorld_ = MathUtility::Matrix4Identity();
	//ワールド行列に平行移動行列をかける
	worldTransform_.matWorld_ *= matTrans;
	//ワールド行列の転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() {

}