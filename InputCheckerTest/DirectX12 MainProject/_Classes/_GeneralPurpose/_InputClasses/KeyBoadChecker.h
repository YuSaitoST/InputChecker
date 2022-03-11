/**
 * @file KeyBoadChecker.h
 * @brief DirectXにおけるキーボードの入力状態を管理するクラス
 * @author 齋藤優宇
 * @date 2022/02/19
 */

#pragma once

#include "KeyBoadEvent.h"
#include "KeyBoadState.h"

enum ARROW_KEY {
	UP, DOWN, LEFT, RIGHT
};

class KeyBoadChecker {
public:
	KeyBoadChecker() {}
	virtual ~KeyBoadChecker() {}

	void Accepts();

	bool EventCharaKey(char inputKey);
	bool EventArrowKey(ARROW_KEY inputKey);
	bool EventAnyKey();
	Vector2 EventDirection();
	
	bool StateCharaKey(char inputKey);
	bool StateArrowKey(ARROW_KEY inputKey);
	bool StateAnyKey();
	Vector2 StateDirection();

private:
	KeyBoadEvent inpEvent_;
	KeyBoadState inpState_;
};