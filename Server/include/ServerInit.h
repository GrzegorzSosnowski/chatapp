/**
* ServerInit.h : Declares sockets, user tab, iReturn for server and client 
*/
#pragma once

#define _WINSOCKAPI_
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "6543" 

#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <map>

#include "SocketServices.h"

using namespace std;

#pragma comment (lib, "Ws2_32.lib")



class ServerInit
{

public:

	ServerInit(void);
	~ServerInit(void);

	//Socket for server to bind to
	SOCKET ListenSocket; 

	//Socket for user to connect to
	SOCKET UserSocket;

	// for returning possible errors
	int iReturn;

	// tab for holding client socket sessions
	std::map<unsigned int, SOCKET> sessions;


	bool acceptNewClient(unsigned int & id);

};




