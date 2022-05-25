#include "DebugRender.h"

void DebugRender::Initialize() {
	font_ = DX9::SpriteFont::CreateFromFontName(DXTK->Device9, L"MS ÉSÉVÉbÉN", 10);
}

void DebugRender::PushList(std::wstring text, float& value) {
	items_.push_back(Items{ text, value });
}

void DebugRender::Render() {
	for (int _i = 0; _i < items_.size(); ++_i)
		DX9::SpriteBatch->DrawString(font_.Get(), SimpleMath::Vector2(0.0f, _i * 15), DX9::Colors::White, items_.at(_i).sentence.c_str(), items_.at(_i).value);
}

void DebugRender::ClearList() {
	items_.clear();
}