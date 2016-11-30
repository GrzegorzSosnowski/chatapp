/**
* ClientInit.h : holds declaration of IReturn and ConnectionSocket
*/
#pragma once
#define _WINSOCKAPI_
#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#include "SocketServices.h"

//setting constants, port
#define	DEFAULT_BUFLEN 512
#define DEFAULT_PORT "6543"
//linking additional libraries 
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


class ClientInit
{
public:


	//call for error checking
	int iReturn;

	//creating socket for client to connect with
	SOCKET ConnectionSocket;


	
	ClientInit(void);
	~ClientInit(void);





};