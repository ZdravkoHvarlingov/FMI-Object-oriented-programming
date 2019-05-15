#pragma once
#include <string>

namespace net
{
	class Server
	{
	public:
		virtual std::string ProcessRequest(std::string msg) = 0;
	};
}

