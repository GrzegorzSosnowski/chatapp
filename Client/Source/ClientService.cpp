// ClientService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ClientInfo.h"
#include <process.h>



ClientInfo * client;
int main()
{
	for (int j = 0;j < 5;j++) //loop that shows multiple connections
	{
		client = new ClientInfo();
		getchar();
	}
    return 0;
}

