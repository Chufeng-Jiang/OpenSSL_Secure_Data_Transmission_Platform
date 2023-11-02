#include "Server.h"

int main()
{
	Server server{ string{"server.json"} };
	server.startServer();
}