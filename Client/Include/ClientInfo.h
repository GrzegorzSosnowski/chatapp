/**
* ClientInfo.h : holds call to clientinit pointer
*/

#pragma once
#define _WINSOCKAPI_
#include <Windows.h>
#include <winSock2.h>

#include "ClientInit.h"

class ClientInfo

{
public:

	ClientInfo(void);
	~ClientInfo(void);

	ClientInit* network;
};


