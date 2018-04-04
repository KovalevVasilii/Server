
#include "Server.h"

int main()
{
	Server server;
	server.port = 3487;//порт это ushort - так что cin.get() и т.п. функции тут работаю некорректно. Лучше задать фвручную
	server.startServer();
	return 0;
}


//#include < iostream >
//#pragma comment( lib, "ws2_32.lib" )
//#include < Windows.h >
//#include < conio.h >
//using namespace std;
//
//#define MY_PORT    666 // Порт, который слушает сервер
//
//// заведём глобальную переменную  ниже для обмена данным между нитями сервера   
//char* cbuff = "common buffer"; // общий буфер для записи сообщений от всех клиентов
//
//
//							   // макрос для печати количества активных
//							   // пользователей 
//#define PRINTNUSERS if (nclients)\
//  printf("%d user on-line\n",nclients);\
//  else printf("No User on line\n");
//
//							   // прототип функции, обслуживающий
//							   // подключившихся пользователей
//DWORD WINAPI WorkWithClient(LPVOID client_socket);
//
////будет просто циклически проверять знкачение глобальной переменной
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
//		// Ошибка!
//		printf("Error socket %d\n", WSAGetLastError());
//		WSACleanup();
//		// Деиницилизация библиотеки Winsock
//		return -1;
//	}
//
//	// Шаг 3 связывание сокета с локальным адресом
//	sockaddr_in local_addr;
//	local_addr.sin_family = AF_INET;
//	local_addr.sin_port = htons(MY_PORT);
//	// не забываем о сетевом порядке!!!
//	local_addr.sin_addr.s_addr = 0;
//	// сервер принимает подключения
//	// на все IP-адреса
//
//	// вызываем bind для связывания
//	if (bind(mysocket, (sockaddr *)&local_addr,
//		sizeof(local_addr)))
//	{
//		// Ошибка
//		printf("Error bind %d\n", WSAGetLastError());
//		closesocket(mysocket);  // закрываем сокет!
//		WSACleanup();
//		return -1;
//	}
//
//	// Шаг 4 ожидание подключений
//	// размер очереди – 0x100
//	if (listen(mysocket, 20))
//	{
//		// Ошибка
//		printf("Error listen %d\n", WSAGetLastError());
//		closesocket(mysocket);
//		WSACleanup();
//		return -1;
//	}
//
//	printf("Waiting for connection\n");
//
//	// Шаг 5 извлекаем сообщение из очереди
//	SOCKET client_socket;    // сокет для клиента
//	sockaddr_in client_addr;    // адрес клиента
//								// (заполняется системой)
//
//								// функции accept необходимо передать размер
//								// структуры
//	int client_addr_size = sizeof(client_addr);
//
//	// цикл извлечения запросов на подключение из
//	// очереди
//	/* accept - держит управление и не даёт циклу вращаться
//	(то есть не даёт потоку- нити выполняться вообще)
//	пока не поступит очередной запрос на соединение*/
//	while ((client_socket = accept(mysocket, (sockaddr *)
//		&client_addr, &client_addr_size)))
//	{
//		nclients++;      // увеличиваем счетчик
//						 // подключившихся клиентов
//
//						 // пытаемся получить имя хоста
//		HOSTENT *hst;
//		hst = gethostbyaddr((char *)
//			&client_addr.sin_addr.s_addr, 4, AF_INET);
//
//		// вывод сведений о клиенте
//		printf("+%s [%s] new connect!\n",
//			(hst) ? hst->h_name : "",
//			inet_ntoa(client_addr.sin_addr));
//		PRINTNUSERS
//
//			// Вызов нового потока для обслужвания клиента
//			// Да, для этого рекомендуется использовать
//			// _beginthreadex но, поскольку никаких вызов
//			// функций стандартной Си библиотеки поток не
//			// делает, можно обойтись и CreateThread
//			DWORD thID;
//		CreateThread(NULL, NULL, WorkWithClient,
//			&client_socket, NULL, &thID);
//
//		/* запускаем функции прослушивания чужих сообщений
//		нам нужен именно отдельный поток, потому что recv()
//		забирает управление и не позволит послать клиенту
//		сообщение пока от этого самого ("родного" для данной
//		нити сервера) клиента что-нибудь не придёт */
//		// CreateThread(NULL,NULL, CheckCommonBuffer, &client_socket,NULL,&thID);
//	}
//	return 0;
//}
//
//
//
//// Эта функция создается в отдельном потоке и
//// обсуживает очередного подключившегося клиента
//// независимо от остальных
//DWORD WINAPI WorkWithClient(LPVOID client_socket)
//{
//	SOCKET my_sock;
//	my_sock = ((SOCKET *)client_socket)[0];
//	char buff[1024] = "123124";
//	//  char buff2[20*1024];
//#define sHELLO "Hello, new member! This's our win socket chat!))\r\n"
//	//printf(" \n new thread is started connect!\n");
//
//	// отправляем клиенту приветствие 
//	send(my_sock, sHELLO, sizeof(sHELLO), 0);
//
//
//
//	// цикл эхо-сервера: прием строки от клиента и
//	int bytes_recv;
//	// возвращение ее клиенту
//	// while ( (bytes_recv=recv(my_sock,&buff[0],sizeof(buff),0)) && (bytes_recv !=SOCKET_ERROR))
//	while (1)
//	{
//		bytes_recv = recv(my_sock, buff, sizeof(buff), 0);
//		cbuff = buff; // пишем в глобальную переменную чтобы другие участники
//					  // узнали о сообщении
//		send(my_sock, &buff[0], bytes_recv, 0);
//
//
//		/*давайте организуем в консоли сервера общий чат-
//		будем выводить туда все сообщение приходящие отразных клиентов-
//		для этого просто используем printf*/
//		cout << buff << std::endl; // печатает сообщения всех клиентов в консоли сервера
//	}
//
//	// если мы здесь, то произошел выход из цикла по
//	// причине возращения функцией recv ошибки –
//	// соединение клиентом разорвано
//	nclients--; // уменьшаем счетчик активных клиентов
//	printf("-disconnect\n"); PRINTNUSERS
//
//		// закрываем сокет
//		closesocket(my_sock);
//	return 0;
//}
//
///*эту функцию надо допилить так как есть проблемы
//с передаваемым и принимаемы м размерами буфера*/
//DWORD WINAPI CheckCommonBuffer(LPVOID client_socket)
//{
//
//	SOCKET my_sock;
//	my_sock = ((SOCKET *)client_socket)[0];
//	char buf[1024]; // для контроля размерности буфера
//	while (1)
//	{
//		/* изменение этого значения - признак того, что пришло новое сообщение
//		buff является глобальной и поправить её может любая нить сервера -
//		просто проверяем значение первого байта(это не слишком надёжный способ)*/
//		if (cbuff[0] != 9)
//
//		{
//			//char buf[1024] =cbuff ;
//			send(my_sock, cbuff, sizeof(cbuff), 0);
//			cbuff[0] = 9;
//			//Sleep(2000);
//		}
//		/*давайте организуем в консоли сервера общий чат-
//		будем выводить туда все сообщение приходящие отразных клиентов-
//		для этого просто используем printf*/
//		//cout << buff << std::endl; // печатает сообщения всех клиентов в консоли сервера
//	}
//}