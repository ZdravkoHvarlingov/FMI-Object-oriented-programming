#pragma once
#include "Server.h"

namespace net
{
	class MathServer : public Server
	{
	protected:

		bool IsMessageValid(std::string msg);

		int firstNum;
		int secondNum;
	};
}
