#pragma once
#include "Server.h"
#include <vector>

namespace net
{
	class DbTextServer: public Server
	{
	public:
		DbTextServer();

		virtual std::string ProcessRequest(std::string msg) override;
		const std::vector<std::string>& GetMessages() const;

	private:
		std::vector<std::string> messages;
	};
}

