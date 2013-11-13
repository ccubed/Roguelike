/** \file Map.h
* Contains the declarations of the Map class
*/

#pragma once
#include <string>
#include "Structs.h"

/**
* \class Map Map.h "Map.H"
* \brief This class represents a single map
*/
class Map
{

public:

	Map(std::string filepath);
	Map(int x,int y);
	Map();
	bool MapLoad(std::string filepath);
	char GetSinglePos(int x, int y);
	Coord GetPlayerPos();
	std::string GetName();
	void DisplayMap(std::ostream& output, int x, int y);
	void DisplayMap(std::ostream& output, Coord NewPlayerPos);
	bool ValidMove(Coord newpos);
	bool IsWall(Coord newpos);
	~Map(void);

private:

	/*!
	 Char Pointer to mapData array
	 */
	char **mapData;

	/*!
	 String representing the name of the map
	 */
	std::string name;

	/*!
	  Integer representing the x size of the map	
 	 */
	int max_x;
	
	/*!
	 Integer representing the y size of the map
	 */
	int max_y;

	/*!
	 Boolean indicating whether or not a map has been loaded to keep us from causing segmentation faults if people call the functions before mapData has data.
	 */
	bool loaded;
	
};

