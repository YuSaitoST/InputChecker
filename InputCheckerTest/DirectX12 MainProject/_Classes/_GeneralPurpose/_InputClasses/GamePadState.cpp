#include "GamePadState.h"

void GamePadState::Accepts(int index) {
	// 桁上がり防止
	flag_	= 0;
	direct_ = Vector2::Zero;

	/*
		各bitに入力状態を入れる
		足す理由は、同時押しを判定できるようにするため
	*/
	flag_ += DXTK->GamePadState[index].buttons.a				? (1 << P_A			 ) : 0;
	flag_ += DXTK->GamePadState[index].buttons.b				? (1 << P_B			 ) : 0;
	flag_ += DXTK->GamePadState[index].buttons.x				? (1 << P_X			 ) : 0;
	flag_ += DXTK->GamePadState[index].buttons.y				? (1 << P_Y			 ) : 0;
	flag_ += DXTK->GamePadState[index].dpad.up					? (1 << P_UP		 ) : 0;
	flag_ += DXTK->GamePadState[index].dpad.down				? (1 << P_DOWN		 ) : 0;
	flag_ += DXTK->GamePadState[index].dpad.left				? (1 << P_LEFT		 ) : 0;
	flag_ += DXTK->GamePadState[index].dpad.right				? (1 << P_RIGHT		 ) : 0;
	flag_ += DXTK->GamePadState[index].IsLeftThumbStickUp()		? (1 << STICK_L_UP	 ) : 0;
	flag_ += DXTK->GamePadState[index].IsLeftThumbStickDown()	? (1 << STICK_L_DOWN ) : 0;
	flag_ += DXTK->GamePadState[index].IsLeftThumbStickLeft()	? (1 << STICK_L_LEFT ) : 0;
	flag_ += DXTK->GamePadState[index].IsLeftThumbStickRight()	? (1 << STICK_L_RIGHT) : 0;
	flag_ += DXTK->GamePadState[index].IsRightThumbStickUp()	? (1 << STICK_R_UP	 ) : 0;
	flag_ += DXTK->GamePadState[index].IsRightThumbStickDown()	? (1 << STICK_R_DOWN ) : 0;
	flag_ += DXTK->GamePadState[index].IsRightThumbStickLeft()	? (1 << STICK_R_LEFT ) : 0;
	flag_ += DXTK->GamePadState[index].IsRightThumbStickRight() ? (1 << STICK_R_RIGHT) : 0;
	flag_ += DXTK->GamePadState[index].IsLeftShoulderPressed()	? (1 << SHOULDER_L	 ) : 0;
	flag_ += DXTK->GamePadState[index].IsRightShoulderPressed() ? (1 << SHOULDER_R	 ) : 0;
	flag_ += DXTK->GamePadState[index].IsLeftTriggerPressed()	? (1 << TRIGGER_L	 ) : 0;
	flag_ += DXTK->GamePadState[index].IsRightTriggerPressed()	? (1 << TRIGGER_R	 ) : 0;

	n_Lx_	= DXTK->GamePadState[index].thumbSticks.leftX;
	n_Ly_	= DXTK->GamePadState[index].thumbSticks.leftY;
	n_Rx_	= DXTK->GamePadState[index].thumbSticks.rightX;
	n_Ry_	= DXTK->GamePadState[index].thumbSticks.rightY;
	n_Ltrg_ = DXTK->GamePadState[index].triggers.left;
	n_Rtrg_ = DXTK->GamePadState[index].triggers.right;
}