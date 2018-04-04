#ifndef SERVER_H
#define SERVER_H

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <iostream>
#include <WinSock2.h>
#include <winsock.h>
#define MY_PORT    666
#define SERVERADDR "127.0.0.1"

class Server
{
public:
	Server();
	~Server();
	void startServer();
	void closeServer();
	void handle();
	unsigned short port;
private:
	SOCKET mysocket;
	WSAData wData;
	int nClients;
};

#endif