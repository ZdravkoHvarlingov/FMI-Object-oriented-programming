#include "Network.h"
#include "DbTextServer.h"
#include "MultiplicationServer.h"
#include "AdditionServer.h"
#include <iostream>

using namespace std;

int main()
{
	net::Network network;
	net::DbTextServer dbServer;
	net::MultiplicationServer multyServer;
	net::AdditionServer additionServer;

	int dbServerId = network.AddServer(&dbServer);
	int multyServerId = network.AddServer(&multyServer);
	int additionServerId = network.AddServer(&additionServer);
	int zdravkoId = network.AddClient("Zdravko", 22);
	int ivkaId = network.AddClient("Ivka", 21);

	std::string response = network.SendMessage(zdravkoId, dbServerId, "New message");
	std::string response2 = network.SendMessage(zdravkoId, multyServerId, "2 3");

	//std::cout << response << std::endl << response2 << std::endl;

	std::string toAll = network.SendMessagesToAll(zdravkoId, "123 3");
	std::string toAll2 = network.SendMessagesToAll(ivkaId, "No numbers here!");

	//std::cout << toAll << toAll2;

	std::vector<std::string> requestResponses = network.GetAllInfo();
	for (std::string &msg : requestResponses)
	{
		std::cout << msg << std::endl;
	}

    return 0;
}
