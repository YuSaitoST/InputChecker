/**
 * @file UseKeyChecker.h
 * @brief ゲームで用いる入力を管理するクラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "UseKBKey.h"
#include "UseGPKey.h"
#include "UseVPKey.h"
#include "_Classes/_VPServer/VPManager.h"

//マクロ
#define INPSystem UseKeyChecker::GetInstance()

enum class InputSystem {
	KEYBOAD,
	GAMEPAD,
	VIRTUAL_PAD
};

class UseKeyChecker {
public:
	static UseKeyChecker& GetInstance() { 
		if (inctance_ == nullptr) {
			inctance_ = new UseKeyChecker();
		}
		return *inctance_; 
	}

	/*
	* @brief 入力方法の変更
	*/
	inline void SetInputSystem(InputSystem system, int playerID) {
		if (system == InputSystem::GAMEPAD) {
			inputSystemList_[playerID]	= InputSystem::GAMEPAD;
			inputList_[playerID]		= std::make_unique<UseGPKey>();
		}
		else if (system == InputSystem::VIRTUAL_PAD) {
			// 成功なら更新
			if (vpManager_->TCP_Connection(playerID) == TCP_CONNECT_OK) {
				inputSystemList_[playerID]	= InputSystem::VIRTUAL_PAD;
				inputList_[playerID]		= std::make_unique<UseVPKey>();
			}
		}
		else {
			inputSystemList_[playerID]	= InputSystem::KEYBOAD;
			inputList_[playerID]		= std::make_unique<UseKBKey>();
		}
	}

	/*
	* @brief 各プレイヤーの入力方法の取得
	*/
	inline std::vector<InputSystem> GetNowInputSystem() const { 
		return inputSystemList_; 
	}

	/*
	* @brief UDP通信の開始
	*/
	inline void UDPStart() {
		vpManager_->UDP_Initialize();
	}

	/*
	* @brief 各プレイヤーの入力状態を調べる
	*/
	inline void Accepts() {
		for (int i = 0; i < 4; ++i) {
			inputList_[i]->Accepts(i);
		}

		VPInput::VPInpSet input_ = VPInput::GetInputData(vpManager_->UDP_Receive());
		inputList_[input_.ID]->SetInputFlag(input_);
	}

	inline bool AnyKey() {
		return inputList_[0]->AnyKey() || inputList_[1]->AnyKey() || inputList_[2]->AnyKey() || inputList_[3]->AnyKey();
	}

	inline bool UpKey(const int index) {
		return inputList_[index]->UpKey(index);
	}

	inline bool DownKey(const int index) {
		return inputList_[index]->DownKey(index);
	}

	inline bool LeftKey(const int index) {
		return inputList_[index]->LeftKey(index);
	}

	inline bool RightKey(const int index) {
		return inputList_[index]->RightKey(index);
	}

	inline bool DecisionKey(const int index) {
		return inputList_[index]->DecisionKey(index);
	}

	inline bool CancelKey(const int index) {
		return inputList_[index]->CancelKey(index);
	}

	//bool MiniGameFinedKey(const int index);

	inline bool ThrasherKey(const int index) {
		return inputList_[index]->ThrasherKey(index);
	}

	inline bool ShotKey(const int index) {
		return inputList_[index]->ShotKey(index);
	}

	inline Vector2 MoveDirection(const int index) {
		return inputList_[index]->MoveDirection(index);
	}

	/**
	* @brief Tabの単発入力状態を返
	* @return 入力されていればtrue　なければfalse
	*/
	inline bool TabKey() { return DXTK->KeyEvent->pressed.Tab; }

private:
	UseKeyChecker() {
		inputList_.push_back(std::make_unique<UseKBKey>());
		inputList_.push_back(std::make_unique<UseGPKey>());
		inputList_.push_back(std::make_unique<UseGPKey>());
		inputList_.push_back(std::make_unique<UseGPKey>());

		inputSystemList_.push_back(InputSystem::KEYBOAD);
		inputSystemList_.push_back(InputSystem::GAMEPAD);
		inputSystemList_.push_back(InputSystem::GAMEPAD);
		inputSystemList_.push_back(InputSystem::GAMEPAD);

		vpManager_ = std::make_unique<VPManager>();
	}
	virtual ~UseKeyChecker() {}

	static UseKeyChecker*							inctance_;
	std::vector<InputSystem>						inputSystemList_;
	std::vector<std::unique_ptr<UseKeyFuncSets>>	inputList_;
	std::unique_ptr<VPManager>						vpManager_;
};

UseKeyChecker* UseKeyChecker::inctance_ = nullptr;