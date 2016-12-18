/**
* SocketServices.h : Prepares send/recv wrappers for function calls to use by client and server.
*/

#pragma once
#define _WINSOCKAPI_
#include <winSock2.h>
#include <Windows.h>

class SocketServices
{
public:

	static int sendMessage(SOCKET curSocket, char * message, int messageSize);
	static int receiveMessage(SOCKET curSocket, char * buffer, int bufSize);



};
