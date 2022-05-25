#include "UseKeyCheck.h"

UseKeyCheck UseKeyCheck::inctance_;

/**
* @brief 入力状態を調べる
*/
void UseKeyCheck::Accepts() {
	key_.Accepts();
	pad_.Accepts(0);
}

/**
* @brief 何かしらの単発入力状態を返す
* @return 入力されていればtrue　なければfalse
*/
bool UseKeyCheck::AnyKey() {
	return key_.EventAnyKey() || pad_.EventAnyKey(0);
}

/**
* @brief 左方向の長押し入力状態を返す
* @return 入力されていればtrue　なければfalse
*/
bool UseKeyCheck::MoveStateLeft() {
	return key_.StateOnOffKey(KEY::LEFT) || pad_.StateOnOffKey(0, PAD::P_LEFT);
}

/**
* @brief 右方向の長押し入力状態を返す
* @return 入力されていればtrue　なければfalse
*/
bool UseKeyCheck::MoveStateRight() {
	return key_.StateOnOffKey(KEY::RIGHT) || pad_.StateOnOffKey(0, PAD::P_RIGHT);
}

/**
* @brief ジャンプの単発入力状態を返す
* @return 入力されていればtrue なければfalse
*/
bool UseKeyCheck::Jump() {
	return key_.EventOnOffKey(KEY::C) || pad_.EventOnOffKey(0, PAD::P_A);
}

/**
* @brief リセットの単発入力状態を返す
* @return 入力されていればtrue なければfalse
*/
bool UseKeyCheck::Reset() {
	return key_.EventOnOffKey(KEY::X) || pad_.EventOnOffKey(0, PAD::P_X);
}