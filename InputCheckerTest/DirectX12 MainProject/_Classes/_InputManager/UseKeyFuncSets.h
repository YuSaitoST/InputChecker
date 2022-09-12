/**
 * @file UseKeyFuncSets.h
 * @brief �Q�[���ŗp������͂��Ǘ�����N���X
 * @author �V���D�F
 * @date 2021/09/09
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "Base/pch.h"
#include "Base/dxtk.h"
#include "InputDevice.h"

class UseKeyFuncSets {
public:
	UseKeyFuncSets() {}
	virtual ~UseKeyFuncSets() {}

	virtual void Accepts(const int index) = 0;
	virtual void SetInputFlag(VPInput::VPInpSet vpInput) = 0;

	virtual bool AnyKey() = 0;
	virtual bool UpKey(const int index) = 0;
	virtual bool DownKey(const int index) = 0;
	virtual bool LeftKey(const int index) = 0;
	virtual bool RightKey(const int index) = 0;
	virtual bool DecisionKey(const int index) = 0;
	virtual bool CancelKey(const int index) = 0;

	// �ǂ����邩�l���Ă���
	//virtual bool MiniGameFinedKey(const int index) = 0;

	virtual bool ThrasherKey(const int index) = 0;
	virtual bool ShotKey(const int index) = 0;
	virtual DirectX::SimpleMath::Vector2 MoveDirection(const int index) = 0;

protected:
	std::unique_ptr<InputDevice> input_;
};