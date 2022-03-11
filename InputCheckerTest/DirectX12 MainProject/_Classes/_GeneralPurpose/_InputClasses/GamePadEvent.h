#pragma once

#include "GamePadBase.h"

class GamePadEvent final : GamePadBase {
public:
	GamePadEvent() {}
	virtual ~GamePadEvent() {}

	virtual void Accepts(int index) override;
};