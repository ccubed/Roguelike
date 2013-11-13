/** \file Map.cpp
* Contains the Definitions of the map class
*/

#include <iostream>
#include <random>
#include "ProGenMap.h"
#include "Map.h"

using namespace std;


/*!
Constructor for Map that calls mapload on the given file at initialization.

@param filepath The path to the file containing the map
*/
Map::Map(std::string filepath){

	loaded = true;

}

/*!
 Constructor for Map that creates a procedurally generated map automatically.

 @param[in] x Size of map vertically
 @param[in] y Size of map horizontally
 */
Map::Map(int x,int y){

	//allocate
	mapData = new char*[x];
	for (int i(0); i < x; i++)
		mapData[i] = new char[y];

	//empty
	for (int i(0); i < x; i++){

		for (int z(0); z < y; z++){

			mapData[i][z] = ' ';

		}

	}

	max_x = x;
	max_y = y;

	//generate
	ProceduralMap Generator(mapData,x,y);

	loaded = true;

}

/*!
Constructor for Map that just makes a new object without loading a map
*/
Map::Map(){

	loaded = false;

}

/*!
Reads mapdata from the given file

@param[in] filepath Path to the file containing the map
*/
bool Map::MapLoad(std::string filepath){

	loaded = true;
	return 0;

}

/*!
Returns the character from the map at the position x,y

@param[in] x The X Coordinate Position
@param[in] y The Y Coordinate Position
@return The Character at Position x,y on the map
*/
char Map::GetSinglePos(int x, int y){

	if (loaded){

		return mapData[x][y];

	}
	else{

		return '"';

	}

}

/*!
Destructor for Map. Only job is to free memory.
*/
Map::~Map(void){

	delete[] mapData;

}

/*!
Returns the player's position

@return A Coord structure indicating the x,y position of the player on the map
*/
Coord Map::GetPlayerPos(){

	for (int i(0); i < max_x;i++)
		for (int e(0); e < max_y;e++)
			if (mapData[i][e] == '@'){
				Coord a;
				a.x = i;
				a.y = e;
				return a;
			}

	Coord a;
	a.x = -1;
	a.y = -1;
	return a;
				
}

/*!
Returns the name of the current Map

@return A String containing the name of the map
*/
std::string Map::GetName(){

	return name;

}

/**
* First of two DisplayMap functions. This one takes an x,y offset to indicate where the player's new position on the map falls.<br/>
* That is, if the player moves up one space, this function would be called like: DisplayMap(output,0,-1)<br/>
* That is: Display the Map and move the player 0 x spaces, and -1 y spaces (this is actually up)<br/>

* @param[in] output Output stream to print the map to
* @param[in] x X Offset to move the player before display
* @param[in] y Y Offset to move the player before display
*/
void Map::DisplayMap(std::ostream& output, int x, int y){

	if (loaded){

		Coord curpos = GetPlayerPos();
		curpos.x += x;
		curpos.y += y;

		for (int i(0); i < max_x; i++){

			for (int z(0); z < max_y; z++){

				output << mapData[i][z];

			}

			output << std::endl;

		}

	}
	else{

		output << "No map to display. This is probably a bug. Inform the developer.";

	}


}

/**
* Second of two DisplayMap functions. This one takes a Coord struct that indicates where the player should be located when the map is redrawn. <br/>
* The difference between this one and the first one is that this one does no modification to the position provided.<br/>

* @param[in] output Output stream to print the map to
* @param[in] NewPlayerPos A Coord structure indicating the player's new position
* @TODO Check for Valid Move, code ValidMove,  IsWall
*/
void Map::DisplayMap(std::ostream& output, Coord NewPlayerPos){

	if (loaded){

		Coord curpos = GetPlayerPos();
		
		for (int i(0); i < max_x; i++){

			for (int z(0); z < max_y; z++){

				if (i == NewPlayerPos.x && z == NewPlayerPos.y){

					output << '@';
					mapData[i][z] = '@';

				}
				else{

					output << mapData[i][z];

				}

			}

			output << std::endl;

		}

	}
	else{

		output << "No map to display. This is probably a bug. Inform the developer.";

	}

}