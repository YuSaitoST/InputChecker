/**
 * @file TCPServer.h
 * @brief VP�pTCP�ʐM�T�[�o�[�N���X
 * @author �V���D�F
 * @date 2021/08/22
 */

#pragma once

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include "VPServer.h"


class TCPServer : public VPServer {
private:
	const unsigned int TIME_SEC		= 30;		// �^�C���A�E�g���� (�b�P��
	const unsigned int TIME_USEC	= 3000000;	// �^�C���A�E�g���� (�}�C�N���b�P��

public:
	TCPServer() {}
	virtual ~TCPServer() {}

	/**
	* @brief UDP�ʐM�̏���
	* @return �G���[�R�[�h { 0...����I�� -1...�\�P�b�g�������s -2...�o�C���h���s -3...�ڑ����s}
	*/
	virtual int Initialize() override {
		sockaddr_in addr;
		SOCKET		sockListen;

		//timeval		tv;
		//fd_set		readfds;
		//int			ret_select; 

		//// �^�C���A�E�g���Ԃ�ݒ�
		//tv.tv_sec	= TIME_SEC;
		//tv.tv_usec	= TIME_USEC;
		

		WSAStartUp();
		AddrSetting(addr, AF_INET, INADDR_ANY);

		sockListen = CreateSocket(addr.sin_family, SOCK_STREAM, 0);
		if (sockListen == INVALID_SOCKET) {
			WSACleanUp();
			return VPERR_CREATE_SOCKET;
		}

		if (Bind(sockListen, addr) == SOCKET_ERROR) {
			WSACleanUp();
			return VPERR_BIND;
		}

		//// �ǂݍ���FD�W������ɂ���
		//FD_ZERO(&readfds);

		//// �ǂݍ���FD�W���Ƀ\�P�b�g��ǉ�
		//FD_SET(sockListen, &readfds);

		//// select��readfds�̂ǂꂩ���ǂݍ��݉\�ɂȂ�܂�or�^�C���A�E�g�܂ő҂�
		//ret_select = select(sockListen + 1, &readfds, NULL, NULL, &tv);

		//// �߂�l�`�F�b�N
		//if (ret_select == -1) {
		//	// select�֐����G���[
		//	WSACleanUp();
		//	return VPERR_SELECT_FUNC;
		//}
		//else if (ret_select == 0) {
		//	// �ǂݍ��݉\�ɂȂ���FD�̐���0�Ȃ̂Ń^�C���A�E�g�Ɣ��f
		//	WSACleanUp();
		//	return VPERR_TIMEOUT;
		//}

		// ����ȍ~�Ń^�C���A�E�g�������������������L�q����
		// (����ɂȂ���΂����ɏ���������)

		if (Listen(sockListen, 5) == SOCKET_ERROR) {
			CloseSocket(sockListen);
			WSACleanUp();
			return VPERR_LISTEN;
		}

		if (Connect(sockListen) == VPERR_CONNECT) {
			return VPERR_CONNECT;
		}

		//// �w�肵��FD��ǂݍ���FD�W������폜
		//FD_CLR(socket_, &readfds);

		return VPERR_SAFE;
	}

	/**
	* @brief ���M
	* @param sendData ���M�f�[�^
	*/
	virtual void Send(std::string sendData) override {
		send(socket_, sendData.c_str(), sizeof(sendData), 0);
	}


	virtual std::string Recv() override {
		return "";
	}

	SOCKET& GetSocket() { return socket_; }

private:
	/**
	* @brief �\�P�b�g��ڑ��҂��ɂ���
	*/
	inline int Listen(SOCKET socket, int backlog) {
		return listen(socket, backlog);
	}

	/**
	* @brief �N���C�A���g����̐ڑ���҂�
	* @param socket �\�P�b�g
	*/
	inline int Connect(SOCKET socket) {
		sockaddr_in client{};
		int			clientlen = sizeof(client);
		char		buf[256];
		memset(buf, 0, sizeof(buf));
		
		try {
			socket_ = accept(socket, (sockaddr*)&client, &clientlen);
		}catch(std::exception e) {
			return VPERR_CONNECT;
		}

		return VPERR_SAFE;
	}
};
