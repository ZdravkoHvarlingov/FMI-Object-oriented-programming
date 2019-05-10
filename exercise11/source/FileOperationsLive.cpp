#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream in("test.txt");

	//First way of reading
	short symbol;
	while ((symbol = in.get()) != -1)
	{
		std::cout << (char)symbol;
	}
	in.clear();
	in.seekg(0, in.beg);

	std::cout << std::endl;
	//Second way of reading
	std::string line;
	while (std::getline(in, line))
	{
		std::cout << line << std::endl;
	}
	in.clear();
	in.seekg(0, in.beg);

	std::cout << std::endl;
	//Third way of reading
	char buff[501];
	while (in.getline(buff, 500))
	{
		std::cout << buff << std::endl;
	}
	in.clear();
	in.seekg(0, in.beg);

	std::cout << std::endl;
	//Forth way of reading
	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);

	char *fullBuff = new char[length + 1];
	in.read(fullBuff, length);
	fullBuff[in.gcount()] = '\0';
	std::cout << fullBuff << std::endl;
	delete fullBuff;

    return 0;
}

