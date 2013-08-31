#pragma once
#include <string>
class Map
{

public:
	Map(std::string filepath);
	~Map(void);

private:
	char * mapData;
	std::string name;



};

