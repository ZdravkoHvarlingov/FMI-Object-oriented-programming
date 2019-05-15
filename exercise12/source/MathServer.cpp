#include "MathServer.h"

bool net::MathServer::IsMessageValid(std::string msg)
{
	int spacesCount = 0;
	int lastSpaceInd = -1;
	for (size_t i = 0; i < msg.length(); i++)
	{
		if (msg[i] == ' ')
		{
			++spacesCount;
			lastSpaceInd = i;
		}
	}

	if (spacesCount != 1)
	{
		return false;
	}

	std::string leftPart = msg.substr(0, lastSpaceInd);
	for (size_t i = 0; i < leftPart.size(); i++)
	{
		if (leftPart[i] < '0' || leftPart[i] > '9')
		{
			return false;
		}
	}
	std::string rightPart = msg.substr(lastSpaceInd + 1);
	for (size_t i = 0; i < rightPart.size(); i++)
	{
		if (rightPart[i] < '0' || rightPart[i] > '9')
		{
			return false;
		}
	}

	firstNum = std::stoi(leftPart);
	secondNum = std::stoi(rightPart);
	
	return true;
}
