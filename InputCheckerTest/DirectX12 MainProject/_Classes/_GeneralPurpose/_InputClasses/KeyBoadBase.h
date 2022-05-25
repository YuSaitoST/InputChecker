/**
 * @file KeyBoadBase.h
 * @brief �L�[�{�[�h���͂̊��N���X
 * @author �V���D�F
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "Base/pch.h"
#include "Base/dxtk.h"

using namespace DirectX::SimpleMath;

/**
 * @enum KEY
 * �Ή����Ă������
 */
enum KEY {
	//! A�`Z
	A, B, C, D, E,
	F, G, H, I, J,
	K, L, M, N, O,
	P, Q, R, S, T,
	U, V, W, X, Y, Z,

	//! �\���L�[
	UP, DOWN, LEFT, RIGHT,TAB
};

class KeyBoadBase {
public:
	KeyBoadBase() : flag_(0), direct_(DirectX::XMFLOAT2()) {}
	virtual ~KeyBoadBase() {}

	virtual void Accepts() = 0;

	/**
	* @brief �w�肵���{�^���̓��͏�Ԃ�Ԃ�
	* @param inputKey ���͏�Ԃ𒲂ׂ����{�^��
	* @return ���͂���Ă����true�@�Ȃ����false
	*/
	inline bool OnOffKey(KEY inputKey) {
		return (flag_ & (1 << (int)inputKey));
	}

	/**
	* @brief ��������{�^���̓��͏�Ԃ�Ԃ�
	* @return ���͂���Ă����true�@�Ȃ����false
	*/
	inline bool AnyKey() {
		return (flag_ != 0);
	}

	/**
	* @brief ���͂���������Ԃ�
	* @return ���͂��ꂽ�����̃x�N�g��
	*/
	inline Vector2 Direction() {
		if (flag_ & (1 << UP   )) direct_.y = 1;
		if (flag_ & (1 << DOWN )) direct_.y = -1;
		if (flag_ & (1 << LEFT )) direct_.x = -1;
		if (flag_ & (1 << RIGHT)) direct_.x = 1;
		direct_.Normalize();
		return direct_;
	}

protected:
	//! ���͏�Ԃ�ێ�����
	unsigned int flag_;

	//! ���͂���������ێ�����
	Vector2 direct_;

private:
	//! A�`Z�̕�����
	const int CHARA = 26;
};