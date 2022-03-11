#include "InputChecker.h"

InputChecker InputChecker::inctance_;

/**
	@brief	�L�[�{�[�h�̓��͏�Ԃ𒲂ׂ�
	@detail ������bool�z��ƂȂ��Ă���A1���ʂɒ��ׂĂ���
			inpEvent_ : ���������ǂ���
			inpState_ : �����������Ă��邩�ǂ���
*/
void InputChecker::Accepts() {
	inpEvent_.Accepts();
	inpState_.Accepts();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(A�`Z�͈̔�)
	@return�@true : ���͂��ꂽ false : ���͂���Ă��Ȃ�
*/
bool InputChecker::EventCharaKey(char inputKey) {
	return inpEvent_.CharaKey(inputKey);
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(UP,DOWN,LEFT,RIGHT)
	@return�@true : ���͂��ꂽ false : ���͂���Ă��Ȃ�
*/
bool InputChecker::EventArrowKey(ARROW_KEY inputKey) {
	return inpEvent_.ArrowKey(inputKey);
}

/**
	@brief	��������̕����������̓��͏�Ԃ�Ԃ�
	@return�@true : ���͂��ꂽ false : ���͂���Ă��Ȃ�
*/
bool InputChecker::EventAnyKey() {
	return inpEvent_.AnyKey();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@return�@���͂��������̃x�N�g��(���K������Ă���)
*/
Vector2 InputChecker::EventDirection() {
	return inpEvent_.Direction();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(A�`Z�͈̔�)
	@return�@true : ���͂���Ă��� false : ���͂���Ă��Ȃ�
*/
bool InputChecker::StateCharaKey(char inputKey) {
	return inpState_.CharaKey(inputKey);
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(UP,DOWN,LEFT,RIGHT)
	@return�@true : ���͂���Ă��� false : ���͂���Ă��Ȃ�
*/
bool InputChecker::StateArrowKey(ARROW_KEY inputKey) {
	return inpState_.ArrowKey(inputKey);
}

/**
	@brief	��������̕����������̓��͏�Ԃ�Ԃ�
	@return�@true : ���͂���Ă��� false : ���͂���Ă��Ȃ�
*/
bool InputChecker::StateAnyKey() {
	return inpState_.AnyKey();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@return�@���͂��Ă�������̃x�N�g��(���K������Ă���)
*/
Vector2 InputChecker::StateDirection() {
	return inpState_.Direction();
}