#pragma once

#include <string>
#include <vector>

struct Ticket
{
	std::string date;
	std::string from;
	std::string to;
	std::string type;
	std::vector<std::string> seats;
};

