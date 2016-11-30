/**
* ServerInfo.cpp : contains update() method for assigning new user IDs
*/

#pragma once
#include "stdafx.h"
#include "ServerInfo.h"

unsigned int ServerInfo::client_id;


ServerInfo::ServerInfo(void)

{
	//initialization for connected clients IDs
	client_id = 1;

	//calling new instance of serverinit 
	initialization = new ServerInit();
}

void ServerInfo::update()
{
	//accept new client connection and assign new ID
	if (initialization->acceptNewClient(client_id))
	{
		printf("Client %d has joined", client_id);

		client_id++;
	}

}