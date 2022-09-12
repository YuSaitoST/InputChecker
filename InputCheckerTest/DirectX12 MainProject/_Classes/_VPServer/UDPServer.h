/**
 * @file UDPServer.h
 * @brief VP�pUDP�ʐM�T�[�o�[�N���X
 * @author �V���D�F
 * @date 2021/08/22
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "VPServer.h"


class UDPServer : public VPServer {
public:
	UDPServer() {}
	virtual ~UDPServer() {}

	/**
	* @brief UDP�ʐM�̏���
	* @return �G���[�R�[�h { 0...����I�� -1...�\�P�b�g�������s -2...�o�C���h���s }
	*/
	virtual int Initialize() override {
		sockaddr_in addr;

		WSAStartUp();
		AddrSetting(addr, AF_INET, INADDR_ANY);

		socket_ = CreateSocket(addr.sin_family, SOCK_DGRAM, 0);
		if (socket_ == INVALID_SOCKET) {
			WSACleanUp();
			return VPERR_CREATE_SOCKET;
		}

		if (Bind(socket_, addr) == SOCKET_ERROR) {
			WSACleanUp();
			return VPERR_BIND;
		}

		// �m���u���b�L���O�ɐݒ�
		u_long val = 1;
		ioctlsocket(socket_, FIONBIO, &val);

		return VPERR_SAFE;
	}

	virtual void Send(std::string sendData) override {

	}

	/**
	* @brief ��M
	* @param recvData ��M�f�[�^������ϐ�
	*/
	virtual std::string Recv() override {
		char buffer[256]{};
		int count = recv(socket_, buffer, sizeof(buffer), 0);
		if (count < 1) {
			return "";
		}
		std::string str = buffer;
		return str;
	}
};