/**
 * @file UseKeyCheck.h
 * @brief ゲームで用いる入力を管理するクラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "KeyBoadChecker.h"
#include "GamePadChecker.h"

//マクロ
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