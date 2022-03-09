#pragma once

#include "InputBase.h"

class InputState final : public InputBase {
public:
	InputState() {};
	virtual ~InputState() {};

	virtual void Initialize() override;
	virtual void Accepts() override;
};