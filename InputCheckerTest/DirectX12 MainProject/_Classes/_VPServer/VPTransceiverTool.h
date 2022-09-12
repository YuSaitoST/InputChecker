/**
 * @file VPTransceiverTool.h
 * @brief VP�p����M�c�[��
 * @author �V���D�F
 * @date 2021/08/22
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include <string>
#include <sstream>

namespace VPInput {
	/**
	* @brief ����̑��M�f�[�^���\�z����
	* @param playerID �v���C���[ID
	* @param titleName �^�C�g��
	* @return ���M�f�[�^
	*/
	inline std::string CreatedSendGameMassage(int playerID, const wchar_t* titleName) {
		// �v���C���[ID
		std::stringstream ss_id;
		ss_id << playerID;

		// �^�C�g����
		std::wstring wstr = titleName;

		// �^�C�g�����𐔒l�ɕϊ�
		std::stringstream ss_title;
		for (const auto& item : wstr) {
			ss_title << std::hex << int(item) << " ";
		}

		// ���M�f�[�^�����
		std::string sendData = ss_title.str();
		sendData[sendData.length() - 1] = *ss_id.str().c_str();

		return sendData;
	}
}