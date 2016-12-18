#include "stdafx.h"
#include "Clientinit.h"


ClientInit::ClientInit(void)
{
	//create wsadata object #fap
	WSADATA wsaData;

	//socket initialization
	ConnectionSocket = INVALID_SOCKET;


	//struct for socket addrinfo
	struct addrinfo *result = NULL,
					*ptr = NULL,
					hints;

	//Initialize Winsock 
	iReturn = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iReturn != 0)
	{
		printf("Initialization failed with error: %d\n", iReturn);
			exit(1);
	}


	//clear connection data
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP; //choosing type of connection (TCP)

	//retrieve address with specific type of connection
	iReturn = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);


	if (iReturn != 0)
	{
		printf("Address acquiring failed with error: %d\n", iReturn);
		WSACleanup();
		exit(1);
	}

	//Attempt to connect until success
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{
		//pass connection values
		ConnectionSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);


		//check for error

		if (ConnectionSocket == INVALID_SOCKET)
		{
			printf("Socket failed to connect with error: &d\n", WSAGetLastError());
			WSACleanup();
			exit(1);
		}

		//Connect to server with specific address
		iReturn = connect(ConnectionSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iReturn == SOCKET_ERROR)
		{
			closesocket(ConnectionSocket);
			ConnectionSocket = INVALID_SOCKET;
			printf("server down, couldnt connect");
		}


		freeaddrinfo(result);

		if (ConnectionSocket == INVALID_SOCKET)
		{
			printf("Couldnt connect");
			WSACleanup();
			exit(1);
		}

		// Set the mode of the socket to be nonblocking
		u_long iMode = 1;

		iReturn = ioctlsocket(ConnectionSocket, FIONBIO, &iMode);
		if (iReturn == SOCKET_ERROR)
		{
			printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectionSocket);
			WSACleanup();
			exit(1);
		}

		
	


	}

}