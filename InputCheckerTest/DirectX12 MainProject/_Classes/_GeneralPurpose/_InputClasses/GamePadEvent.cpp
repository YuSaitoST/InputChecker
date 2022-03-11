#include "GamePadEvent.h"

void GamePadEvent::Accepts(int index) {
	// 桁上がり防止
	flag_ = 0;

	/*
		各bitに入力状態を入れる
		足す理由は、同時押しを判定できるようにするため
	*/
	flag_ += DXTK->GamePadEvent[index].a				? (1 << A			 ) : 0;
	flag_ += DXTK->GamePadEvent[index].b				? (1 << B			 ) : 0;
	flag_ += DXTK->GamePadEvent[index].x				? (1 << X			 ) : 0;
	flag_ += DXTK->GamePadEvent[index].y				? (1 << Y			 ) : 0;
	flag_ += DXTK->GamePadEvent[index].dpadUp			? (1 << UP			 ) : 0;
	flag_ += DXTK->GamePadEvent[index].dpadDown			? (1 << DOWN		 ) : 0;
	flag_ += DXTK->GamePadEvent[index].dpadLeft			? (1 << LEFT		 ) : 0;
	flag_ += DXTK->GamePadEvent[index].dpadRight		? (1 << RIGHT		 ) : 0;
	flag_ += DXTK->GamePadEvent[index].leftStickUp		? (1 << STICK_L_UP	 ) : 0;
	flag_ += DXTK->GamePadEvent[index].leftStickDown	? (1 << STICK_L_DOWN ) : 0;
	flag_ += DXTK->GamePadEvent[index].leftStickLeft	? (1 << STICK_L_LEFT ) : 0;
	flag_ += DXTK->GamePadEvent[index].leftStickRight	? (1 << STICK_L_RIGHT) : 0;
	flag_ += DXTK->GamePadEvent[index].rightStickUp		? (1 << STICK_R_UP	 ) : 0;
	flag_ += DXTK->GamePadEvent[index].rightStickDown	? (1 << STICK_R_DOWN ) : 0;
	flag_ += DXTK->GamePadEvent[index].rightStickLeft	? (1 << STICK_R_LEFT ) : 0;
	flag_ += DXTK->GamePadEvent[index].rightStickRight	? (1 << STICK_R_RIGHT) : 0;
	flag_ += DXTK->GamePadEvent[index].leftShoulder		? (1 << SHOULDER_L	 ) : 0;
	flag_ += DXTK->GamePadEvent[index].rightShoulder	? (1 << SHOULDER_R	 ) : 0;
	flag_ += DXTK->GamePadEvent[index].leftTrigger		? (1 << TRIGGER_L	 ) : 0;
	flag_ += DXTK->GamePadEvent[index].rightTrigger		? (1 << TRIGGER_R	 ) : 0;
}