#include "UseKeyCheck.h"

UseKeyCheck UseKeyCheck::inctance_;

void UseKeyCheck::Accepts() {
	key_.Accepts();
}

bool UseKeyCheck::MoveStateLeft() {
	return key_.StateArrowKey(ARROW_KEY::K_LEFT);
}

bool UseKeyCheck::MoveStateRight() {
	return key_.StateArrowKey(ARROW_KEY::K_RIGHT);
}