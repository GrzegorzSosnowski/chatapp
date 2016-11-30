// BasicServer.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include "ServerInfo.h"

#include <process.h>

ServerInfo * server;

int main()
{


	//Initailize server
	server = new ServerInfo();
	while (true) // loop for accepting pending connections
	{
		server->update();
	}
    return 0;
}

