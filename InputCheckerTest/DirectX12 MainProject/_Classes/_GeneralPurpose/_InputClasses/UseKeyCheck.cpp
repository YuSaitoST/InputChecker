#include "UseKeyCheck.h"

void UseKeyCheck::Accepts() {
	key_.Accepts();
	pad_.Accepts(0);
}

bool UseKeyCheck::MoveStateLeft() {
	return key_.StateOnOffKey(KEY::LEFT) || pad_.StateOnOffKey(0, PAD::P_LEFT);
}

bool UseKeyCheck::MoveStateRight() {
	return key_.StateOnOffKey(KEY::RIGHT) || pad_.StateOnOffKey(0, PAD::P_RIGHT);
}