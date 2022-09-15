/**
 * @file VPServer.h
 * @brief VP�p�\�P�b�g�ʐM�N���X
 * @author �V���D�F
 * @date 2021/08/22
 */

#pragma once

#pragma comment(lib, "Ws2_32.lib")

 //------------------------------------------------------------------------------
 //	�C���N���[�h�t�@�C��
 //------------------------------------------------------------------------------
#include <memory>
#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>


#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define VPERR_SAFE			 0
#define VPERR_CREATE_SOCKET -1
#define VPERR_BIND			-2
#define VPERR_SELECT_FUNC	-3
#define VPERR_SOCK_OPTION	-4
#define VPERR_TIMEOUT		-5
#define VPERR_LISTEN		-6
#define VPERR_CONNECT		-7

#define VP_PORTNUMBER		 51234


class VPServer {
public:
	VPServer() : socket_(0) {}
	virtual ~VPServer() {}

	virtual int Initialize() = 0;
	virtual void Send(std::string sendData) = 0;
	virtual std::string Recv() = 0;

	/**
	* @brief �ʐM���I������
	*/
	inline void Close() {
		CloseSocket(socket_);
		WSACleanUp();
	}

protected:
	/**
	* @brief WinSock������
	*/
	inline void WSAStartUp() {
		/*
			��1���� :	WINSOCK_VERSION ... �ŐV�̃o�[�W����
						MAKEWORD(n, m)	... �o�[�W����n, m
		*/
		WSAData wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			//WinSock���������s
		}
	}

	/**
	* @param �A�h���X���̐ݒ�
	* @param addr �ݒ肷��A�h���X
	* @param family �A�h���X�t�@�~��
	* @param sinAddr IP�A�h���X
	*/
	inline void AddrSetting(sockaddr_in& addr, ADDRESS_FAMILY family, ULONG sinAddr) {
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = family;
		addr.sin_port = htons(VP_PORTNUMBER);	// ��M�|�[�g(�֐��ʂ��ʂƐ������z�X�g���J���Ȃ��݂���)
		addr.sin_addr.S_un.S_addr = sinAddr;				// INADDR_ANY : �ǂ�IP����ł��ʐM���󂯎���Ԃɂ���A��M���͂���ő��v
		// or ���M�A�h���X���Œ�ɂ���ꍇ
		//addr.sin_addr.S_un.S_addr = inet_addr(/*���M�A�h���X*/"127.0.0.1");
	}

	/**
	* @brief �\�P�b�g����
	* @param family �v������A�h���X�E�h���C�� { AF_INET(IPv4), AF_INET6, AF_UNIX, AF_RAW }
	* @param type �ʐM���@ { SOCK_STREAM(TCP), SOCK_DGRAM(UDP), SOCK_RAW }
	* @param protocol �v���g�R��
	*/
	inline SOCKET CreateSocket(ADDRESS_FAMILY family, int type, int protocol) {
		return socket(family, type, protocol);
	}

	/**
	* @brief �\�P�b�g�ɃA�h���X�����蓖�Ă�
	* @param socket �\�P�b�g
	* @param addr �A�h���X���
	*/
	inline int Bind(SOCKET socket, sockaddr_in addr) {
		return bind(socket, (sockaddr*)&addr, sizeof(addr));
	}

	/**
	* @brief �\�P�b�g�̔j��
	* @param socket �j������\�P�b�g
	*/
	inline void CloseSocket(SOCKET socket) {
		closesocket(socket);
	}

	/**
	* @brief WinSock�̉��
	*/
	inline void WSACleanUp() {
		//���������ɓǂݍ��܂ꂽDLL���A�����[�h�����
		WSACleanup();
	}

	SOCKET socket_;
};
