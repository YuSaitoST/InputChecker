/**
 * @file VPInputData.h
 * @brief VP�p���̓f�[�^�ϊ�
 * @author �V���D�F
 * @date 2021/08/22
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include <string>

namespace VPInput {

	/*
	* @brief ���͏��
	*/
	struct VPInpSet {
		int			ID				: 3;
		int			BUTTON_ID		: 3;
		float		X;
		float		Y;
		std::string INPUT_PATTERN;
	};

	/*
	* @brief �󂯎�������͏���ϊ�����
	* @param recvData ���͏��
	* @return �L�[���̓f�[�^
	*/
	inline VPInpSet GetInputData(std::string recvData) {
		std::string data(recvData);
		VPInpSet	input{};

		if (data.empty()) {
			input.ID			= 0;
			input.BUTTON_ID		= 0;
			input.X				= 0.0;
			input.Y				= 0.0f;
			input.INPUT_PATTERN = "N";
			return input;
		}

		// �v���C���[ID�̎擾
		input.ID = std::atoi(data.substr(0, 1).c_str());

		// �`�������̎擾
		input.INPUT_PATTERN = data.substr(2, 1);
		data.erase(0, 4);

		// �`�����Ƃ̃p�����[�^�擾
		if (input.INPUT_PATTERN == "B") {
			input.BUTTON_ID = std::atoi(data.substr(0, 1).c_str());
		}
		else if (input.INPUT_PATTERN == "S") {
			int	pos = data.find(" ");
			input.X = std::stof(data.substr(0, pos).c_str());

			data.erase(0, pos + 1);

			input.Y = std::stof(data.substr(0, data.find(" ")).c_str());
		}

		data.erase();

		return input;
	}
}