#include "KeyBoadChecker.h"

/**
	@brief	�L�[�{�[�h�̓��͏�Ԃ𒲂ׂ�
	@detail ������bool�z��ƂȂ��Ă���A1���ʂɒ��ׂĂ���
			inpEvent_ : ���������ǂ���
			inpState_ : �����������Ă��邩�ǂ���
*/
void KeyBoadChecker::Accepts() {
	inpEvent_.Accepts();
	inpState_.Accepts();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(A�`Z�͈̔�)
	@return�@true : ���͂��ꂽ false : ���͂���Ă��Ȃ�
*/
bool KeyBoadChecker::EventCharaKey(char inputKey) {
	return inpEvent_.CharaKey(inputKey);
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(UP,DOWN,LEFT,RIGHT)
	@return�@true : ���͂��ꂽ false : ���͂���Ă��Ȃ�
*/
bool KeyBoadChecker::EventArrowKey(ARROW_KEY inputKey) {
	return inpEvent_.ArrowKey(inputKey);
}

/**
	@brief	��������̕����������̓��͏�Ԃ�Ԃ�
	@return�@true : ���͂��ꂽ false : ���͂���Ă��Ȃ�
*/
bool KeyBoadChecker::EventAnyKey() {
	return inpEvent_.AnyKey();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@return�@���͂��������̃x�N�g��(���K������Ă���)
*/
Vector2 KeyBoadChecker::EventDirection() {
	return inpEvent_.Direction();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(A�`Z�͈̔�)
	@return�@true : ���͂���Ă��� false : ���͂���Ă��Ȃ�
*/
bool KeyBoadChecker::StateCharaKey(char inputKey) {
	return inpState_.CharaKey(inputKey);
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@param  inputKey  ���͏�Ԃ𒲂ׂ����������w�肷��(UP,DOWN,LEFT,RIGHT)
	@return�@true : ���͂���Ă��� false : ���͂���Ă��Ȃ�
*/
bool KeyBoadChecker::StateArrowKey(ARROW_KEY inputKey) {
	return inpState_.ArrowKey(inputKey);
}

/**
	@brief	��������̕����������̓��͏�Ԃ�Ԃ�
	@return�@true : ���͂���Ă��� false : ���͂���Ă��Ȃ�
*/
bool KeyBoadChecker::StateAnyKey() {
	return inpState_.AnyKey();
}

/**
	@brief	�w�肵�������̓��͏�Ԃ�Ԃ�
	@return�@���͂��Ă�������̃x�N�g��(���K������Ă���)
*/
Vector2 KeyBoadChecker::StateDirection() {
	return inpState_.Direction();
}