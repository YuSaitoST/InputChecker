/**
 * @file InputChecker.h
 * @brief DirectX‚Ì“ü—Íó‘Ô‚ğŠÇ—‚·‚éƒNƒ‰ƒX
 * @author âV“¡—D‰F
 * @date 2022/02/19
 */

#pragma once

#include "InputEvent.h"
#include "InputState.h"

#define Input InputChecker::GetInctance()	

enum ARROW_KEY {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class InputChecker {
public:
	static InputChecker& GetInctance() {
		return inctance_;
	}

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
	InputChecker() {
		inpEvent_.Initialize();
		inpState_.Initialize();
	}
	virtual ~InputChecker() {}

	static InputChecker inctance_;
	InputEvent inpEvent_;
	InputState inpState_;
};