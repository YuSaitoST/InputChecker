/**
 * @file VPManager.h
 * @brief VP�p�T�[�o�[�Ǘ��N���X
 * @author �V���D�F
 * @date 2021/08/22
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include <stdio.h>

#include "VPTransceiverTool.h"
#include "TCPServer.h"
#include "UDPServer.h"

#define TCP_CONNECT_OK  1
#define TCP_CONNECT_NOK 0

class VPManager {
public:
	VPManager() { udp_server_ = std::make_unique<UDPServer>(); }
	virtual ~VPManager() { udp_server_->Close(); }

	/*
	* @brief TCP�ɂ�鏉��ڑ�
	* @param playerID �ڑ������݂�v���C���[��ID
	* @return �ڑ���ԃ��b�Z�[�W
	*/
	inline int TCP_Connection(int playerID) {
		std::string					sendData	= VPInput::CreatedSendGameMassage(playerID, titleName);
		std::unique_ptr<TCPServer>	tcp_server	= std::make_unique<TCPServer>();
		int							err			= tcp_server->Initialize();

		switch (err) {
			case VPERR_SAFE			 : 
				tcp_server->Send(sendData);
				tcp_server->Close();
				return TCP_CONNECT_OK;
			case VPERR_CREATE_SOCKET : 
			case VPERR_BIND			 : 
			case VPERR_SELECT_FUNC	 : 
			case VPERR_TIMEOUT		 : 
			case VPERR_LISTEN		 : 
				return TCP_CONNECT_NOK;
		}
	}

	/*
	* @brief UDP�ʐM�̏�����
	*/
	inline void UDP_Initialize() { 
		int err = udp_server_->Initialize(); 
	}

	/*
	* @brief UDP�ʐM�ɂ��f�[�^���
	* @return ��M�f�[�^
	*/
	inline std::string UDP_Receive() { return udp_server_->Recv(); }

private:
	const wchar_t* titleName = L"���j�o�[�X�|�[�c";

	std::unique_ptr<UDPServer> udp_server_;
};