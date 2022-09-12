/**
 * @file UseVPKey.h
 * @brief �o�[�`�����p�b�h�̓��͊Ǘ��N���X
 * @author �V���D�F
 * @date 2021/09/09
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "UseKeyFuncSets.h"
#include "YsVirtualPad.h"

class UseVPKey : public UseKeyFuncSets {
public:
	UseVPKey() { input_ = std::make_unique<YsVirtualPad>(); }
	virtual ~UseVPKey() {}

	virtual void Accepts(const int index) override { input_->accepts(index); }
	virtual void SetInputFlag(VPInput::VPInpSet vpInput) override { input_->set_inputflag(vpInput); }

	virtual bool AnyKey		()					override { return input_->get_anykey(); }
	virtual bool UpKey		(const int index)	override { return input_->get_key((int)GM_VPAD::P_UP); }
	virtual bool DownKey	(const int index)	override { return input_->get_key((int)GM_VPAD::P_DOWN); }
	virtual bool LeftKey	(const int index)	override { return input_->get_key((int)GM_VPAD::P_LEFT); }
	virtual bool RightKey	(const int index)	override { return input_->get_key((int)GM_VPAD::P_RIGHT); }
	virtual bool DecisionKey(const int index)	override { return input_->get_key((int)GM_VPAD::P_B); }
	virtual bool CancelKey	(const int index)	override { return input_->get_key((int)GM_VPAD::P_A); }

	// �ǂ����邩�l���Ă���
	//virtual bool MiniGameFinedKey(const int index) override { return false; }

	virtual bool ThrasherKey(const int index) override { return input_->get_key((int)GM_VPAD::P_X); }
	virtual bool ShotKey(const int index) override { return input_->get_key((int)GM_VPAD::P_A); }
	virtual DirectX::SimpleMath::Vector2 MoveDirection(const int index) override { return input_->get_direction(index); }
};