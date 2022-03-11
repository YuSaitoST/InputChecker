#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

using namespace DirectX::SimpleMath;

enum PAD {
	A, B, X, Y,
	UP, DOWN, LEFT, RIGHT,
	STICK_L_UP	, STICK_L_DOWN,
	STICK_L_LEFT, STICK_L_RIGHT,
	STICK_R_UP	, STICK_R_DOWN,
	STICK_R_LEFT, STICK_R_RIGHT,
	SHOULDER_L	, SHOULDER_R,
	TRIGGER_L	, TRIGGER_R
};

class GamePadBase {
public:
	GamePadBase() : flag_(0) {};
	virtual ~GamePadBase() {}

	virtual void Accepts(int index) = 0;

	inline bool OnOffKey(PAD inputKey) { return (flag_ & (1 << inputKey)); }

	inline bool AnyKey() { return (flag_ & 0xffffffff); }

	inline Vector2 Direction() {
		if (flag_ & (1 << UP   )) direct_.y = -1;
		if (flag_ & (1 << DOWN )) direct_.y = 1;
		if (flag_ & (1 << LEFT )) direct_.x = -1;
		if (flag_ & (1 << RIGHT)) direct_.x = 1;
		return direct_;
	}
	
protected:
	unsigned int flag_;
	Vector2 direct_;
};