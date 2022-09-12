/**
 * @file UDPServer.h
 * @brief VP用UDP通信サーバークラス
 * @author 齋藤優宇
 * @date 2021/08/22
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "VPServer.h"


class UDPServer : public VPServer {
public:
	UDPServer() {}
	virtual ~UDPServer() {}

	/**
	* @brief UDP通信の準備
	* @return エラーコード { 0...正常終了 -1...ソケット生成失敗 -2...バインド失敗 }
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

		// ノンブロッキングに設定
		u_long val = 1;
		ioctlsocket(socket_, FIONBIO, &val);

		return VPERR_SAFE;
	}

	virtual void Send(std::string sendData) override {

	}

	/**
	* @brief 受信
	* @param recvData 受信データを入れる変数
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