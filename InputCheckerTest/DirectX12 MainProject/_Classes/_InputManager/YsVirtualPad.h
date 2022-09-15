/**
 * @file YsVirtualPad.h
 * @brief �o�[�`�����p�b�h���͂̊��N���X
 * @author �V���D�F
 * @date 2021/09/09
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
enum class GM_VPAD {
	//! �E����4��ނ̃{�^��
	P_X, P_Y, P_A, P_B,

	//! �\���L�[
	P_UP, P_DOWN, P_LEFT, P_RIGHT,

	////! ���X�e�B�b�N
	//STICK_L_UP	, STICK_L_DOWN,
	//STICK_L_LEFT, STICK_L_RIGHT,
};


class YsVirtualPad : public InputDevice {
public:
	YsVirtualPad() {};
	virtual ~YsVirtualPad() {}

	virtual void accepts(int index) override {
		flag_	= 0;
		direct_ = Vector2::Zero;
	}

	/**
	* @brief ���͂��ꂽ������Ԃ�
	* @return ���͂��ꂽ�����̃x�N�g��
	*/
	virtual Vector2 get_direction(int id) override {
		direct_.Normalize();
		return direct_;
	}

	// �󂯎�������͏��ɍ��킹�ăf�[�^��ۑ�����
	virtual void set_inputflag(VPInput::VPInpSet vpInput) override {
		if (vpInput.INPUT_PATTERN == "B") {
			flag_ |= 1 << vpInput.BUTTON_ID;
		}
		else if (vpInput.INPUT_PATTERN == "S") {
			direct_.x = vpInput.X;
			direct_.y = vpInput.Y;

			flag_ |= (direct_.y ==	1.0) << (int)GM_VPAD::P_UP;
			flag_ |= (direct_.y == -1.0) << (int)GM_VPAD::P_DOWN;
			flag_ |= (direct_.x == -1.0) << (int)GM_VPAD::P_LEFT;
			flag_ |= (direct_.x ==	1.0) << (int)GM_VPAD::P_RIGHT;
		}
	}
};