/**
 * @file UseGPKey.h
 * @brief �Q�[���p�b�h�̓��͊Ǘ��N���X
 * @author �V���D�F
 * @date 2021/09/09
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "UseKeyFuncSets.h"
#include "YsGamePad.h"

class UseGPKey : public UseKeyFuncSets {
public:
	UseGPKey() { input_ = std::make_unique<YsGamePad>(); }
	virtual ~UseGPKey() {}

	virtual void Accepts(const int index) override { input_->accepts(index); }
	virtual void SetInputFlag(VPInput::VPInpSet vpInput) override {}

	virtual bool AnyKey		()					override { return input_->get_anykey(); }
	virtual bool UpKey		(const int index)	override { return input_->get_key((int)GM_PAD::P_UP); }
	virtual bool DownKey	(const int index)	override { return input_->get_key((int)GM_PAD::P_DOWN); }
	virtual bool LeftKey	(const int index)	override { return input_->get_key((int)GM_PAD::P_LEFT); }
	virtual bool RightKey	(const int index)	override { return input_->get_key((int)GM_PAD::P_RIGHT); }
	virtual bool DecisionKey(const int index)	override { return input_->get_key((int)GM_PAD::P_B); }
	virtual bool CancelKey	(const int index)	override { return input_->get_key((int)GM_PAD::P_A); }

	// �ǂ����邩�l���Ă���
	//virtual bool MiniGameFinedKey(const int index) override { return false; }

	virtual bool ThrasherKey(const int index) override { return input_->get_key((int)GM_PAD::P_X); }
	virtual bool ShotKey(const int index) override { return input_->get_key((int)GM_PAD::P_A); }
	virtual DirectX::SimpleMath::Vector2 MoveDirection(const int index) override { return input_->get_direction(index); }
};