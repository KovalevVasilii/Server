
#include "Server.h"

int main()
{
	Server server;
	server.port = 3487;//���� ��� ushort - ��� ��� cin.get() � �.�. ������� ��� ������� �����������. ����� ������ ��������
	server.startServer();
	return 0;
}


//#include < iostream >
//#pragma comment( lib, "ws2_32.lib" )
//#include < Windows.h >
//#include < conio.h >
//using namespace std;
//
//#define MY_PORT    666 // ����, ������� ������� ������
//
//// ������ ���������� ����������  ���� ��� ������ ������ ����� ������ �������   
//char* cbuff = "common buffer"; // ����� ����� ��� ������ ��������� �� ���� ��������
//
//
//							   // ������ ��� ������ ���������� ��������
//							   // ������������� 
//#define PRINTNUSERS if (nclients)\
//  printf("%d user on-line\n",nclients);\
//  else printf("No User on line\n");
//
//							   // �������� �������, �������������
//							   // �������������� �������������
//DWORD WINAPI WorkWithClient(LPVOID client_socket);
//
////����� ������ ���������� ��������� ��������� ���������� ����������
//DWORD WINAPI CheckCommonBuffer(LPVOID client_socket);
//
//int nclients = 0;
//
//int main(int argc, char* argv[])
//{
//	char buff[1024];
//
//	printf("TCP SERVER DEMO\n");
//
//	if (WSAStartup(0x0202, (WSADATA *)&buff[0]))
//	{
//		printf("Error WSAStartup %d\n",
//			WSAGetLastError());
//		return -1;
//	}
//
//	SOCKET mysocket;
//
//	if ((mysocket = socket(AF_INET, SOCK_STREAM, 0))<0)
//	{
//		// ������!
//		printf("Error socket %d\n", WSAGetLastError());
//		WSACleanup();
//		// �������������� ���������� Winsock
//		return -1;
//	}
//
//	// ��� 3 ���������� ������ � ��������� �������
//	sockaddr_in local_addr;
//	local_addr.sin_family = AF_INET;
//	local_addr.sin_port = htons(MY_PORT);
//	// �� �������� � ������� �������!!!
//	local_addr.sin_addr.s_addr = 0;
//	// ������ ��������� �����������
//	// �� ��� IP-������
//
//	// �������� bind ��� ����������
//	if (bind(mysocket, (sockaddr *)&local_addr,
//		sizeof(local_addr)))
//	{
//		// ������
//		printf("Error bind %d\n", WSAGetLastError());
//		closesocket(mysocket);  // ��������� �����!
//		WSACleanup();
//		return -1;
//	}
//
//	// ��� 4 �������� �����������
//	// ������ ������� � 0x100
//	if (listen(mysocket, 20))
//	{
//		// ������
//		printf("Error listen %d\n", WSAGetLastError());
//		closesocket(mysocket);
//		WSACleanup();
//		return -1;
//	}
//
//	printf("Waiting for connection\n");
//
//	// ��� 5 ��������� ��������� �� �������
//	SOCKET client_socket;    // ����� ��� �������
//	sockaddr_in client_addr;    // ����� �������
//								// (����������� ��������)
//
//								// ������� accept ���������� �������� ������
//								// ���������
//	int client_addr_size = sizeof(client_addr);
//
//	// ���� ���������� �������� �� ����������� ��
//	// �������
//	/* accept - ������ ���������� � �� ��� ����� ���������
//	(�� ���� �� ��� ������- ���� ����������� ������)
//	���� �� �������� ��������� ������ �� ����������*/
//	while ((client_socket = accept(mysocket, (sockaddr *)
//		&client_addr, &client_addr_size)))
//	{
//		nclients++;      // ����������� �������
//						 // �������������� ��������
//
//						 // �������� �������� ��� �����
//		HOSTENT *hst;
//		hst = gethostbyaddr((char *)
//			&client_addr.sin_addr.s_addr, 4, AF_INET);
//
//		// ����� �������� � �������
//		printf("+%s [%s] new connect!\n",
//			(hst) ? hst->h_name : "",
//			inet_ntoa(client_addr.sin_addr));
//		PRINTNUSERS
//
//			// ����� ������ ������ ��� ����������� �������
//			// ��, ��� ����� ������������� ������������
//			// _beginthreadex ��, ��������� ������� �����
//			// ������� ����������� �� ���������� ����� ��
//			// ������, ����� �������� � CreateThread
//			DWORD thID;
//		CreateThread(NULL, NULL, WorkWithClient,
//			&client_socket, NULL, &thID);
//
//		/* ��������� ������� ������������� ����� ���������
//		��� ����� ������ ��������� �����, ������ ��� recv()
//		�������� ���������� � �� �������� ������� �������
//		��������� ���� �� ����� ������ ("�������" ��� ������
//		���� �������) ������� ���-������ �� ����� */
//		// CreateThread(NULL,NULL, CheckCommonBuffer, &client_socket,NULL,&thID);
//	}
//	return 0;
//}
//
//
//
//// ��� ������� ��������� � ��������� ������ �
//// ���������� ���������� ��������������� �������
//// ���������� �� ���������
//DWORD WINAPI WorkWithClient(LPVOID client_socket)
//{
//	SOCKET my_sock;
//	my_sock = ((SOCKET *)client_socket)[0];
//	char buff[1024] = "123124";
//	//  char buff2[20*1024];
//#define sHELLO "Hello, new member! This's our win socket chat!))\r\n"
//	//printf(" \n new thread is started connect!\n");
//
//	// ���������� ������� ����������� 
//	send(my_sock, sHELLO, sizeof(sHELLO), 0);
//
//
//
//	// ���� ���-�������: ����� ������ �� ������� �
//	int bytes_recv;
//	// ����������� �� �������
//	// while ( (bytes_recv=recv(my_sock,&buff[0],sizeof(buff),0)) && (bytes_recv !=SOCKET_ERROR))
//	while (1)
//	{
//		bytes_recv = recv(my_sock, buff, sizeof(buff), 0);
//		cbuff = buff; // ����� � ���������� ���������� ����� ������ ���������
//					  // ������ � ���������
//		send(my_sock, &buff[0], bytes_recv, 0);
//
//
//		/*������� ���������� � ������� ������� ����� ���-
//		����� �������� ���� ��� ��������� ���������� �������� ��������-
//		��� ����� ������ ���������� printf*/
//		cout << buff << std::endl; // �������� ��������� ���� �������� � ������� �������
//	}
//
//	// ���� �� �����, �� ��������� ����� �� ����� ��
//	// ������� ���������� �������� recv ������ �
//	// ���������� �������� ���������
//	nclients--; // ��������� ������� �������� ��������
//	printf("-disconnect\n"); PRINTNUSERS
//
//		// ��������� �����
//		closesocket(my_sock);
//	return 0;
//}
//
///*��� ������� ���� �������� ��� ��� ���� ��������
//� ������������ � ���������� � ��������� ������*/
//DWORD WINAPI CheckCommonBuffer(LPVOID client_socket)
//{
//
//	SOCKET my_sock;
//	my_sock = ((SOCKET *)client_socket)[0];
//	char buf[1024]; // ��� �������� ����������� ������
//	while (1)
//	{
//		/* ��������� ����� �������� - ������� ����, ��� ������ ����� ���������
//		buff �������� ���������� � ��������� � ����� ����� ���� ������� -
//		������ ��������� �������� ������� �����(��� �� ������� ������� ������)*/
//		if (cbuff[0] != 9)
//
//		{
//			//char buf[1024] =cbuff ;
//			send(my_sock, cbuff, sizeof(cbuff), 0);
//			cbuff[0] = 9;
//			//Sleep(2000);
//		}
//		/*������� ���������� � ������� ������� ����� ���-
//		����� �������� ���� ��� ��������� ���������� �������� ��������-
//		��� ����� ������ ���������� printf*/
//		//cout << buff << std::endl; // �������� ��������� ���� �������� � ������� �������
//	}
//}