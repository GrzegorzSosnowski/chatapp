/**
* ServerInfo.h : contains headers and refs for ServerInfo class
*/

#pragma once

#define _WINSOCKAPI_
#include "ServerInit.h"

class ServerInfo
{

public:

	ServerInfo(void);
	~ServerInfo(void);

	void update();

private:

	//ID of connected clients
	static unsigned int client_id;

	// Pointer server init class
	ServerInit * initialization;



};


