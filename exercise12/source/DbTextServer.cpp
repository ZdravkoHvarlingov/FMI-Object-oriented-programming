#include "DbTextServer.h"

net::DbTextServer::DbTextServer()
{}

std::string net::DbTextServer::ProcessRequest(std::string msg)
{
	messages.push_back(msg);

	return "DbTextServer: Message saved successfully.";
}

const std::vector<std::string>& net::DbTextServer::GetMessages() const
{
	return messages;
}
