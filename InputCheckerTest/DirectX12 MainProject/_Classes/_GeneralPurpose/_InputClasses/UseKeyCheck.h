/**
 * @file UseKeyCheck.h
 * @brief �Q�[���ŗp������͂��Ǘ�����N���X
 * @author �V���D�F
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "KeyBoadChecker.h"
#include "GamePadChecker.h"

//�}�N��
#define Press UseKeyCheck::GetInstance()

class UseKeyCheck {
public:
	static UseKeyCheck& GetInstance() { return inctance_; }

	void Accepts();

	bool AnyKey();
	bool MoveStateLeft();
	bool MoveStateRight();
	bool Jump();
	bool Reset();

private:
	UseKeyCheck() {}
	virtual ~UseKeyCheck() {}

	static UseKeyCheck inctance_;
	KeyBoadChecker key_;
	GamePadChecker pad_;
};