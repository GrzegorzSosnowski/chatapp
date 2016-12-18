#pragma once
#include <string.h>

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {

	INIT_CONNECTION = 0,

	ACK_PACK = 1,

	CHAT = 2,

};

struct Packet {

	unsigned int packet_type;
	std::string message="";
	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};

