#include "KeyBoadChecker.h"

void KeyBoadChecker::Accepts() {
	inpEvent_.Accepts();
	inpState_.Accepts();
}

bool KeyBoadChecker::EventCharaKey(char inputKey) {
	return inpEvent_.CharaKey(inputKey);
}

bool KeyBoadChecker::EventArrowKey(ARROW_KEY inputKey) {
	return inpEvent_.ArrowKey(inputKey);
}

bool KeyBoadChecker::EventAnyKey() {
	return inpEvent_.AnyKey();
}

Vector2 KeyBoadChecker::EventDirection() {
	return inpEvent_.Direction();
}

bool KeyBoadChecker::StateCharaKey(char inputKey) {
	return inpState_.CharaKey(inputKey);
}

bool KeyBoadChecker::StateArrowKey(ARROW_KEY inputKey) {
	return inpState_.ArrowKey(inputKey);
}

bool KeyBoadChecker::StateAnyKey() {
	return inpState_.AnyKey();
}

Vector2 KeyBoadChecker::StateDirection() {
	return inpState_.Direction();
}