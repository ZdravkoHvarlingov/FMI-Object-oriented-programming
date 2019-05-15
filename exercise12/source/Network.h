#pragma once
#include "Server.h"
#include <vector>

namespace net
{
#define ServerIndToId(ind) (ind) * 2
#define ServerIdToInd(id) (id) / 2
#define ClientIndToId(ind) (ind) * 2 + 1
#define ClientIdToInd(id) ((id) - 1) / 2

	class Network
	{
	public:
		int AddServer(Server *server);
		int AddClient(std::string name, int age);
		
		std::string SendMessage(int clientId, int serverId, std::string msg);
		std::string SendMessagesToAll(int clientId, std::string msg);
		
		std::vector<std::string> GetAllInfo() const;

	private:
		struct Client
		{
			std::string name;
			int age;
		};

		//Id will be index * 2 - even numbers
		std::vector<Server*> servers;
		//Id will be index * 2 + 1 - odd numbers
		std::vector<Client> clients;
		std::vector<std::string> requestResponses;
	};
}
