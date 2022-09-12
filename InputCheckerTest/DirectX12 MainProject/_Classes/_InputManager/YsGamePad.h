/**
 * @file YsGamePad.h
 * @brief �Q�[���p�b�h���͂̊��N���X
 * @author �V���D�F
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "InputDevice.h"

/**
 * @enum PAD
 * �Ή����Ă������
 */
enum class GM_PAD {
	//! �E����4��ނ̃{�^��
	P_A, P_B, P_X, P_Y,

	//! �\���L�[
	P_UP, P_DOWN, P_LEFT, P_RIGHT,

	////! ���X�e�B�b�N
	//STICK_L_UP	, STICK_L_DOWN,
	//STICK_L_LEFT, STICK_L_RIGHT,

	////! �E�X�e�B�b�N
	//STICK_R_UP	, STICK_R_DOWN,
	//STICK_R_LEFT, STICK_R_RIGHT,

	////! ���E�̃V�����_�[
	//SHOULDER_L	, SHOULDER_R,

	////! ���E�̃g���K�[
	//TRIGGER_L	, TRIGGER_R
};


class YsGamePad : public InputDevice {
public:
	YsGamePad() {};
	virtual ~YsGamePad() {}

	/**
	* @brief ���͏�Ԃ𒲂ׂ�
	* @param index �Q�[���p�b�h�̔ԍ�
	*/
	virtual void accepts(int index) override{
		//���オ��h�~
		flag_ = 0;

		//�e�r�b�g�ɓ��͏�Ԃ�����
		flag_ |= (bool)DXTK->GamePadEvent[index].a			<< (int)GM_PAD::P_A;
		flag_ |= (bool)DXTK->GamePadEvent[index].b			<< (int)GM_PAD::P_B;
		flag_ |= (bool)DXTK->GamePadEvent[index].x			<< (int)GM_PAD::P_X;
		flag_ |= (bool)DXTK->GamePadEvent[index].y			<< (int)GM_PAD::P_Y;
		flag_ |= (bool)DXTK->GamePadEvent[index].dpadUp		<< (int)GM_PAD::P_UP;
		flag_ |= (bool)DXTK->GamePadEvent[index].dpadDown	<< (int)GM_PAD::P_DOWN;
		flag_ |= (bool)DXTK->GamePadEvent[index].dpadLeft	<< (int)GM_PAD::P_LEFT;
		flag_ |= (bool)DXTK->GamePadEvent[index].dpadRight	<< (int)GM_PAD::P_RIGHT;

		//0.0�`1.0�Ŏ�����
		direct_.x = DXTK->GamePadState[index].thumbSticks.leftX;
		direct_.y = DXTK->GamePadState[index].thumbSticks.leftY;
	}

	/**
	* @brief ���͂��ꂽ������Ԃ�
	* @return ���͂��ꂽ�����̃x�N�g��
	*/
	virtual Vector2 get_direction(int id) {
		direct_.Normalize();
		return direct_;
	}

	virtual void set_inputflag(VPInput::VPInpSet vpInput) override {}
};