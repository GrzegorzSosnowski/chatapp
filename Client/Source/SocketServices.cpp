/***
* SocketServices.cpp : contains methods that take socket type objects used to send/receive messages through pointer
*/
#pragma once
#include "stdafx.h"
#include "SocketServices.h"


int SocketServices::sendMessage(SOCKET curSocket, char * message, int messageSize)
{
	return send(curSocket, message, messageSize, 0);
}

int SocketServices::receiveMessage(SOCKET curSocket, char * buffer, int bufSize)
{
	return recv(curSocket, buffer, bufSize, 0);
}