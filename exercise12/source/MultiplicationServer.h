#pragma once
#include "MathServer.h"

namespace net
{
	class MultiplicationServer : public MathServer
	{
		// Inherited via MathServer
		virtual std::string ProcessRequest(std::string msg) override;
	};
}
