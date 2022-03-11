#pragma once

#include "KeyBoadEvent.h"
#include "KeyBoadState.h"

enum ARROW_KEY {
	K_UP, K_DOWN, K_LEFT, K_RIGHT
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