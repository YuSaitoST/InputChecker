#pragma once

#include "KeyBoadChecker.h"
#include "GamePadChecker.h"

#define Press UseKeyCheck::GetInstance()

class UseKeyCheck {
public:
	static UseKeyCheck& GetInstance() {
		static UseKeyCheck inctance;
		return inctance;
	}

	void Accepts();

	bool Pad_B();
	bool Pad_A();

	bool MoveStateLeft();
	bool MoveStateRight();

private:
	UseKeyCheck() {}
	virtual ~UseKeyCheck() {}

	KeyBoadChecker key_;
	GamePadChecker pad_;
};