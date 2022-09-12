/**
 * @file UseKBKey.h
 * @brief �L�[�{�[�h�̓��͊Ǘ��N���X
 * @author �V���D�F
 * @date 2021/09/09
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "UseKeyFuncSets.h"
#include "YsKeyBoad.h"

class UseKBKey : public UseKeyFuncSets {
public:
	UseKBKey() { input_ = std::make_unique<YsKeyboard>(); }
	virtual ~UseKBKey() {}

	virtual void Accepts(const int index) override { input_->accepts(0); }
	virtual void SetInputFlag(VPInput::VPInpSet vpInput) override {}

	virtual bool AnyKey		()					override { return input_->get_anykey(); }
	virtual bool UpKey		(const int index)	override { return input_->get_key((int)GM_KEY::UP); }
	virtual bool DownKey	(const int index)	override { return input_->get_key((int)GM_KEY::DOWN); }
	virtual bool LeftKey	(const int index)	override { return input_->get_key((int)GM_KEY::LEFT); }
	virtual bool RightKey	(const int index)	override { return input_->get_key((int)GM_KEY::RIGHT); }
	virtual bool DecisionKey(const int index)	override { return input_->get_key((int)GM_KEY::B); }
	virtual bool CancelKey	(const int index)	override { return input_->get_key((int)GM_KEY::A); }

	// �ǂ����邩�l���Ă���
	//virtual bool MiniGameFinedKey(const int index) override { return false; }

	virtual bool ThrasherKey(const int index) override { return input_->get_key((int)GM_KEY::X); }
	virtual bool ShotKey(const int index) override { return input_->get_key((int)GM_KEY::A); }
	virtual DirectX::SimpleMath::Vector2 MoveDirection(const int index) override { return input_->get_direction(0); }
};