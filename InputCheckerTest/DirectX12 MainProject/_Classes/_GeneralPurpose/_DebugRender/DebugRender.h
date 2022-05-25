#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

#define DebugList DebugRender::GetInstance()

using namespace DirectX;

class DebugRender {
public:
	static DebugRender& GetInstance() {
		static DebugRender inctance_;
		return inctance_;
	}

	inline void PushList(std::wstring text, float& value);
	inline void Render();
	inline void ClearList();

private:
	DebugRender() { Initialize(); }
	virtual ~DebugRender() {}

	inline void Initialize();

	struct Items {
		std::wstring sentence;
		float& value;
	};

	DX9::SPRITEFONT font_;
	std::vector<Items> items_;
};