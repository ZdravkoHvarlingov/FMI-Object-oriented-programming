#include "AdditionServer.h"

std::string net::AdditionServer::ProcessRequest(std::string msg)
{
	bool isValid = IsMessageValid(msg);
	if (!isValid)
	{
		return "AdditionServer: Invalid message format.";
	}

	return "AdditionServer: " + std::to_string(firstNum + secondNum);
}
