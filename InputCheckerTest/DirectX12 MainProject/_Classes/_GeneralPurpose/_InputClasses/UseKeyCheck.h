#pragma once

#include "KeyBoadChecker.h"

#define Press UseKeyCheck::GetInstance()

class UseKeyCheck {
public:
	static UseKeyCheck& GetInstance() { return inctance_; }

	void Accepts();

	bool MoveStateLeft();
	bool MoveStateRight();

private:
	UseKeyCheck() {}
	virtual ~UseKeyCheck() {}

	static UseKeyCheck inctance_;
	KeyBoadChecker key_;
};