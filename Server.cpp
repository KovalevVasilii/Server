#include "Server.h"

Server::Server() {
	nClients = 0;
}

Server::~Server() {
}

DWORD WINAPI CheckCommonBuffer(LPVOID client_socket);
DWORD WINAPI WorkWithClient(LPVOID client_socket);
char* cbuff = "";

void Server::startServer() {
	if (WSAStartup(MAKEWORD(2, 2), &wData) == 0)
	{
		std::cout<<"WSA Startup succes"<<std::endl;
	}
	else
	{
		std::cout << WSAGetLastError() << std::endl;
		return;
	}

	if ((mysocket = socket(AF_INET, SOCK_STREAM, 0))<0)
	{
		std::cout << "Error socket\n"<< WSAGetLastError() << std::endl;
		WSACleanup();
		return;
	}


	sockaddr_in local_addr;
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(MY_PORT);
	local_addr.sin_addr.s_addr = 0;



	if (bind(mysocket, (sockaddr *)&local_addr,
		sizeof(local_addr)))
	{
		std::cout << "Error bind \n"<<WSAGetLastError() << std::endl;
		closesocket(mysocket);  
		WSACleanup();
		return ;
	}
	
	if (listen(mysocket, SOMAXCONN)== SOCKET_ERROR)
	{
		std::cout << "Error listen \n"<< WSAGetLastError() << std::endl;
		closesocket(mysocket);
		WSACleanup();
		return ;
	}

	std::cout << "Waiting for connection" << std::endl;

	handle();
}

void Server::closeServer() {
	closesocket(mysocket);
	WSACleanup();
	std::cout << "Server was stoped. You can close app" << std::endl;
}


void Server::handle() {
	SOCKET client_socket;
	sockaddr_in client_addr;
	int client_addr_size = sizeof(client_addr);
	while ((client_socket = accept(mysocket, (sockaddr *)
		&client_addr, &client_addr_size)))
	{
		nClients++;     
		HOSTENT *hst;
		hst = gethostbyaddr((char *)
			&client_addr.sin_addr.s_addr, 4, AF_INET);

		std::cout << "+"<< "new connect!\n"<<inet_ntoa(client_addr.sin_addr) << std::endl;
		if (nClients)
		{
			std::cout << nClients << "users on-line"<< std::endl;
		}
		else
		{
			std::cout << "No User on line" << std::endl;
		}

		DWORD thID;
		CreateThread(NULL, NULL, WorkWithClient,&client_socket, NULL, &thID);
		CreateThread(NULL, NULL, CheckCommonBuffer, &client_socket, NULL, &thID);
	}
	return;
}

DWORD WINAPI WorkWithClient(LPVOID client_socket)
{
	SOCKET my_sock;
	my_sock = ((SOCKET *)client_socket)[0];
	char buff[1024] = "";

	send(my_sock, "Hello, new member! This's our chat!))\r\n", sizeof("Hello, new member! This's our chat!))\r\n"), 0);


	int bytes_recv;
	while (true)
	{
		bytes_recv = recv(my_sock, buff, sizeof(buff), 0);
		cbuff = buff;
		send(my_sock, &buff[0], bytes_recv, 0);


		std::cout << buff << std::endl;
	}
	
	std::cout << "-disconnect" << std::endl;

		closesocket(my_sock);
	return 0;
}


DWORD WINAPI CheckCommonBuffer(LPVOID client_socket)
{

	SOCKET my_sock;
	my_sock = ((SOCKET *)client_socket)[0];
	while (true)
	{
		if (cbuff[0] != 9 && sizeof(*cbuff)>1)

		{
			send(my_sock, cbuff, sizeof(cbuff), 0);
			std::cout << cbuff << std::endl;
			cbuff[0] = 9;
			Sleep(2000);
		}
	}
}