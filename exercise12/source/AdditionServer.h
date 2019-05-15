#pragma once
#include "MathServer.h"

namespace net
{
	class AdditionServer : public MathServer
	{
		virtual std::string ProcessRequest(std::string msg) override;
	};
}
