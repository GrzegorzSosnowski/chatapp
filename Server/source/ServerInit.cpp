/**
* ServerInit.cpp : contains basic server methods, accepts user connections and stores them in user tab
*/

#pragma once

#include "stdafx.h" 
#include "ServerInit.h"


// accept new connections
bool ServerInit::acceptNewClient(unsigned int &id)
{
	// accept pending connections
	UserSocket = accept(ListenSocket, NULL, NULL);

	if (UserSocket != INVALID_SOCKET)
	{
		// save user socket with corresponding ID in user connections tab
		sessions.insert(pair<unsigned int, SOCKET>(id, UserSocket));
		printf("%i", id);
		return true;
	}
	//Sleep(1000);
	//printf("No pending connections: \n");
	return false;

	
}


ServerInit::ServerInit(void)
{

	// create WSADATA object holding winsock info
	WSADATA wsaData;

	// sockets initialization
	ListenSocket = INVALID_SOCKET;
	UserSocket = INVALID_SOCKET;



	// address info for the server to listen to
	struct addrinfo *result = NULL;
	struct addrinfo hints;

	// Initialize Winsock ver 2.0
	iReturn = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iReturn != 0) {
		printf("WSAStartup failed with error: %d\n", iReturn);
		exit(1);
	}

	// clear address information
	ZeroMemory(&hints, sizeof(hints));
	//set address information
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;    
	hints.ai_flags = AI_PASSIVE;


	// set server address as localhost
	iReturn = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

	if (iReturn != 0) {
		printf("getaddrinfo failed with error: %d\n", iReturn);
		WSACleanup();
		exit(1);
	}

	// load server address into server socket
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		exit(1);
	}

	// Set the mode of the socket to be nonblocking
	u_long iMode = 1;
	iReturn = ioctlsocket(ListenSocket, FIONBIO, &iMode);

	if (iReturn == SOCKET_ERROR) {
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}

	// bind server socket to given addres
	iReturn = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);

	if (iReturn == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}

	// after init free addrinfo
	freeaddrinfo(result);

	// set server socket into listening state
	iReturn = listen(ListenSocket, SOMAXCONN); //set max number of pending connections

	if (iReturn == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}

	
}