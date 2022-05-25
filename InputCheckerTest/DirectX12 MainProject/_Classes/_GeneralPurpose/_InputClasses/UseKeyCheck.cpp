#include "UseKeyCheck.h"

UseKeyCheck UseKeyCheck::inctance_;

/**
* @brief ���͏�Ԃ𒲂ׂ�
*/
void UseKeyCheck::Accepts() {
	key_.Accepts();
	pad_.Accepts(0);
}

/**
* @brief ��������̒P�����͏�Ԃ�Ԃ�
* @return ���͂���Ă����true�@�Ȃ����false
*/
bool UseKeyCheck::AnyKey() {
	return key_.EventAnyKey() || pad_.EventAnyKey(0);
}

/**
* @brief �������̒��������͏�Ԃ�Ԃ�
* @return ���͂���Ă����true�@�Ȃ����false
*/
bool UseKeyCheck::MoveStateLeft() {
	return key_.StateOnOffKey(KEY::LEFT) || pad_.StateOnOffKey(0, PAD::P_LEFT);
}

/**
* @brief �E�����̒��������͏�Ԃ�Ԃ�
* @return ���͂���Ă����true�@�Ȃ����false
*/
bool UseKeyCheck::MoveStateRight() {
	return key_.StateOnOffKey(KEY::RIGHT) || pad_.StateOnOffKey(0, PAD::P_RIGHT);
}

/**
* @brief �W�����v�̒P�����͏�Ԃ�Ԃ�
* @return ���͂���Ă����true �Ȃ����false
*/
bool UseKeyCheck::Jump() {
	return key_.EventOnOffKey(KEY::C) || pad_.EventOnOffKey(0, PAD::P_A);
}

/**
* @brief ���Z�b�g�̒P�����͏�Ԃ�Ԃ�
* @return ���͂���Ă����true �Ȃ����false
*/
bool UseKeyCheck::Reset() {
	return key_.EventOnOffKey(KEY::X) || pad_.EventOnOffKey(0, PAD::P_X);
}