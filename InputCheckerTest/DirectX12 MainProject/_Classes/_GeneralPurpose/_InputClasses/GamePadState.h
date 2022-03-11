#pragma once

#include "GamePadBase.h"

class GamePadState final : GamePadBase {
public:
	GamePadState() {}
	virtual ~GamePadState() {}

	virtual void Accepts(int index) override;
};