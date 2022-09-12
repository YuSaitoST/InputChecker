/**
 * @file InputDevice.h
 * @brief ���̓f�o�C�X���N���X
 * @author �V���D�F
 * @date 2021/08/05
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "Base/pch.h"
#include "Base/dxtk.h"
#include "_Classes/_VPServer/VPInputData.h"

using namespace DirectX::SimpleMath;

class InputDevice {
public:
	InputDevice() : flag_(0), direct_(DirectX::XMFLOAT2()) {}
	virtual ~InputDevice() {}

	virtual void accepts(int id) = 0;
	virtual Vector2 get_direction(int id) = 0;
	virtual void set_inputflag(VPInput::VPInpSet vpInput) = 0;

	/**
	* @brief ��������̃{�^�����͏�Ԃ�Ԃ�
	* @return ���͂���Ă����true�@�Ȃ����false
	*/
	inline bool get_anykey() {
		return flag_ != 0;
	}

	/**
	* @brief �w�肵���{�^���̓��͏�Ԃ�Ԃ�
	* @param KeyID ���͏�Ԃ𒲂ׂ����{�^��
	* @return ���͂���Ă����true�@�Ȃ����false
	*/
	inline bool get_key(int keyID) {
		return (flag_ & (1 << keyID));
	}

protected:
	//! ���͏�Ԃ��r�b�g�ŕێ�����ϐ�
	unsigned int flag_;

	//! ���͂��ꂽ������ێ�����ϐ�
	Vector2 direct_;
};