#pragma once

#include "InputBase.h"

class InputEvent final : public InputBase {
public:
	InputEvent() {};
	virtual ~InputEvent() {};

	virtual void Initialize() override;
	virtual void Accepts() override;
};