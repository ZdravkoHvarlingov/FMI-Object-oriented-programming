#include "Network.h"

int net::Network::AddServer(Server * server)
{
	servers.push_back(server);

	int id = ServerIndToId((int)servers.size() - 1);

	return (ServerIndToId((int)servers.size() - 1));
}

int net::Network::AddClient(std::string name, int age)
{
	clients.push_back({ name, age });

	return (ClientIndToId((int)clients.size() - 1));
}

std::string net::Network::SendMessage(int clientId, int serverId, std::string msg)
{
	int cliendInd = ClientIdToInd(clientId);
	int serverInd = ServerIdToInd(serverId);

	if (cliendInd >= clients.size() || serverInd >= servers.size())
	{
		return "Invalid client and server ID!";
	}

	std::string response = servers[serverInd]->ProcessRequest(msg);
	requestResponses.push_back("Client ID: " + std::to_string(clientId) + ", serverID: " + std::to_string(serverId) +
		", REQUEST: " + msg + ", RESPONSE: " + response);

	return response;
}

std::string net::Network::SendMessagesToAll(int clientId, std::string msg)
{
	if (ClientIdToInd(clientId) >= clients.size())
	{
		return "Invalid client ID!";
	}

	std::string res = "";
	for (size_t i = 0; i < servers.size(); i++)
	{
		res += SendMessage(clientId, ServerIndToId(i), msg);
		res += '\n';
	}

	return res;
}

std::vector<std::string> net::Network::GetAllInfo() const
{
	return requestResponses;
}
