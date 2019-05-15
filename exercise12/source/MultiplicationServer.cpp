#include "MultiplicationServer.h"

std::string net::MultiplicationServer::ProcessRequest(std::string msg)
{
	bool isValid = IsMessageValid(msg);
	if (!isValid)
	{
		return "MultiplicationServer: Invalid message format.";
	}

	return "MultiplicationServer: " + std::to_string(firstNum * secondNum);
}
